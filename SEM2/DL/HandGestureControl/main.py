import time
import cv2

from camera_input import CameraInput
from gesture_detector import GestureDetector
from gesture_recognizer import GestureRecognizer, Gesture, THUMB_TIP, INDEX_TIP
from volume_controller import VolumeController

# Pinch state-machine thresholds (normalised by hand size)
PINCH_ENTER  = 0.18   # ratio to activate pinch mode
PINCH_EXIT   = 0.65   # ratio to release pinch mode
PINCH_MAP_LO = 0.18   # ratio - 0 % volume
PINCH_MAP_HI = 0.60   # ratio - 100 % volume

# Smoothing — prevents hand tremor from jittering volume
PINCH_SMOOTH   = 0.15   # EMA factor
PINCH_DEADBAND = 0.012  
PINCH_SETTLE   = 1.5    # seconds of stillness to auto-release

HOLD_SECONDS = 0.5    # hold time for discrete gestures

# HUD colours
GREEN  = (0, 220, 80)
RED    = (0, 50, 220)
WHITE  = (240, 240, 240)
GRAY   = (140, 140, 140)
YELLOW = (0, 210, 255)
PURPLE = (220, 80, 220)

HELP_LINES = [
    "PINCH + hold still  lock volume",
    "FIST                toggle mute",
    "OPEN PALM           volume max",
    "PEACE SIGN          volume 50%",
    "POINTING            volume 25%",
    "Q                   quit",
]


def _pinch_to_volume(ratio: float) -> float:
    level = (ratio - PINCH_MAP_LO) / (PINCH_MAP_HI - PINCH_MAP_LO)
    return max(0.0, min(1.0, level))


def _draw_hud(frame, gesture: Gesture, pinch_active: bool, pinch_cooldown_left: float,
              vol: float, muted: bool, feedback: str):
    h, w = frame.shape[:2]

    # Volume bar
    bx, bt, bb, bw = 30, 120, 360, 28
    filled = int((bb - bt) * vol)
    cv2.rectangle(frame, (bx, bt), (bx + bw, bb), GRAY, 2)
    if not muted and filled > 0:
        cv2.rectangle(frame, (bx, bb - filled), (bx + bw, bb), GREEN, cv2.FILLED)
    cv2.putText(frame, "VOL", (bx - 2, bt - 12), cv2.FONT_HERSHEY_SIMPLEX, 0.5, WHITE, 1)
    cv2.putText(frame, f"{int(vol * 100):3d}%", (bx - 4, bb + 22),
                cv2.FONT_HERSHEY_SIMPLEX, 0.55, WHITE, 1)

    # Gesture label
    if pinch_active:
        label, color = "Pinch - Sliding", PURPLE
    elif pinch_cooldown_left > 0:
        label, color = f"Pinch locked  {pinch_cooldown_left:.1f}s", YELLOW
    elif gesture != Gesture.UNKNOWN:
        label, color = gesture.value, GREEN
    else:
        label, color = gesture.value, GRAY
    cv2.putText(frame, label, (80, 35), cv2.FONT_HERSHEY_SIMPLEX, 0.72, color, 2)

    # Mute badge
    if muted:
        cv2.rectangle(frame, (w // 2 - 60, 10), (w // 2 + 60, 48), RED, cv2.FILLED)
        cv2.putText(frame, "  MUTED", (w // 2 - 54, 40),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.9, WHITE, 2)

    # Feedback toast
    if feedback:
        cv2.putText(frame, feedback, (w // 2 - 140, h - 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.75, YELLOW, 2)

    # Help legend
    for i, line in enumerate(HELP_LINES):
        cv2.putText(frame, line, (w - 290, 25 + i * 22),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.4, GRAY, 1)


def _draw_pinch_line(frame, landmarks):
    t, i = landmarks[THUMB_TIP][:2], landmarks[INDEX_TIP][:2]
    cv2.line(frame, t, i, PURPLE, 3)
    cv2.circle(frame, t, 8, PURPLE, cv2.FILLED)
    cv2.circle(frame, i, 8, PURPLE, cv2.FILLED)


def main():
    camera     = CameraInput()
    detector   = GestureDetector()
    recognizer = GestureRecognizer()
    vol_ctrl   = VolumeController()

    last_gesture    = Gesture.UNKNOWN
    gesture_start   = time.time()
    gesture_fired   = False
    pinch_active    = False
    pinch_cooldown  = 0.0    # time after which pinch can re-activate
    pinch_last_move = 0.0    # time of last meaningful ratio change
    smoothed_ratio  = None
    last_set_ratio  = None
    feedback_text   = ""
    feedback_until  = 0.0

    print("Hand Gesture Volume Controller — press Q in the window to quit.")

    while True:
        frame = camera.read_frame()
        if frame is None:
            print("[ERROR] Camera read failed.")
            break

        results   = detector.detect(camera.preprocess(frame))
        landmarks = detector.get_landmarks(results, frame.shape)
        gesture   = recognizer.recognize(landmarks)
        now       = time.time()

        # Track how long the current gesture has been held
        if gesture != last_gesture:
            last_gesture  = gesture
            gesture_start = now
            gesture_fired = False
        held_for = now - gesture_start

        # Pinch state machine
        if landmarks:
            ratio = recognizer.get_pinch_ratio(landmarks)

            if not pinch_active and now > pinch_cooldown and ratio < PINCH_ENTER:
                pinch_active    = True
                smoothed_ratio  = ratio
                last_set_ratio  = ratio
                pinch_last_move = now

            if pinch_active:
                smoothed_ratio = PINCH_SMOOTH * ratio + (1 - PINCH_SMOOTH) * smoothed_ratio

                if abs(smoothed_ratio - last_set_ratio) > PINCH_DEADBAND:
                    vol_ctrl.unmute()
                    vol_ctrl.set_volume(_pinch_to_volume(smoothed_ratio))
                    last_set_ratio  = smoothed_ratio
                    pinch_last_move = now
                elif now - pinch_last_move >= PINCH_SETTLE:
                    # Hand held still long enough - lock volume and release
                    pinch_active   = False
                    pinch_cooldown = now + 5.0
                    smoothed_ratio = None
                    last_set_ratio = None
                    feedback_text  = "Volume locked"
                    feedback_until = now + 1.5
                    # Block any gesture currently being held from firing
                    gesture_start = now
                    gesture_fired = True

                if pinch_active:
                    # Show settle progress bar under the pinch line
                    still_for   = now - pinch_last_move
                    progress    = min(still_for / PINCH_SETTLE, 1.0)
                    h, w        = frame.shape[:2]
                    bar_len     = int(200 * progress)
                    bar_y       = h - 50
                    cv2.rectangle(frame, (w//2 - 100, bar_y), (w//2 + 100, bar_y + 12), GRAY, 2)
                    if bar_len:
                        cv2.rectangle(frame, (w//2 - 100, bar_y), (w//2 - 100 + bar_len, bar_y + 12), PURPLE, cv2.FILLED)
                    _draw_pinch_line(frame, landmarks)

        # Discrete gestures — fire once per hold
        if not pinch_active and not gesture_fired and held_for >= HOLD_SECONDS:
            if gesture == Gesture.FIST:
                vol_ctrl.toggle_mute()
                feedback_text  = "Muted" if vol_ctrl.is_muted() else "Unmuted"
                feedback_until = now + 1.5
                gesture_fired  = True
            elif gesture == Gesture.OPEN_PALM:
                vol_ctrl.unmute()
                vol_ctrl.set_volume(1.0)
                feedback_text  = "Volume -> 100%"
                feedback_until = now + 1.5
                gesture_fired  = True
            elif gesture == Gesture.PEACE:
                vol_ctrl.unmute()
                vol_ctrl.set_volume(0.5)
                feedback_text  = "Volume -> 50%"
                feedback_until = now + 1.5
                gesture_fired  = True
            elif gesture == Gesture.POINTING:
                vol_ctrl.unmute()
                vol_ctrl.set_volume(0.25)
                feedback_text  = "Volume -> 25%"
                feedback_until = now + 1.5
                gesture_fired  = True

        detector.draw_landmarks(frame, results)
        cooldown_left = max(0.0, pinch_cooldown - now)
        _draw_hud(frame, gesture, pinch_active, cooldown_left,
                  vol_ctrl.get_volume(), vol_ctrl.is_muted(),
                  feedback_text if now < feedback_until else "")

        cv2.imshow("Hand Gesture Volume Control", frame)
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break

    camera.release()
    detector.close()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
