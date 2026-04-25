import os
import time
import urllib.request
import cv2
import mediapipe as mp

MODEL_PATH = os.path.join(os.path.dirname(__file__), "hand_landmarker.task")
MODEL_URL = (
    "https://storage.googleapis.com/mediapipe-models/"
    "hand_landmarker/hand_landmarker/float16/1/hand_landmarker.task"
)

_CONNECTIONS = [
    (0, 1), (1, 2), (2, 3), (3, 4),            # thumb
    (0, 5), (5, 6), (6, 7), (7, 8),            # index
    (0, 9), (9, 10), (10, 11), (11, 12),       # middle
    (0, 13), (13, 14), (14, 15), (15, 16),     # ring
    (0, 17), (17, 18), (18, 19), (19, 20),     # pinky
    (5, 9), (9, 13), (13, 17),                 # palm arch
]


def _ensure_model():
    if not os.path.exists(MODEL_PATH):
        print("[GestureDetector] Downloading hand landmarker model (~8 MB)…")
        urllib.request.urlretrieve(MODEL_URL, MODEL_PATH)
        print("[GestureDetector] Model saved to", MODEL_PATH)


class GestureDetector:
    def __init__(self, max_hands=1, detection_confidence=0.75, tracking_confidence=0.75):
        _ensure_model()

        options = mp.tasks.vision.HandLandmarkerOptions(
            base_options=mp.tasks.BaseOptions(model_asset_path=MODEL_PATH),
            running_mode=mp.tasks.vision.RunningMode.VIDEO,
            num_hands=max_hands,
            min_hand_detection_confidence=detection_confidence,
            min_hand_presence_confidence=detection_confidence,
            min_tracking_confidence=tracking_confidence,
        )
        self._landmarker = mp.tasks.vision.HandLandmarker.create_from_options(options)

    def detect(self, rgb_frame):
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_frame)
        return self._landmarker.detect_for_video(mp_image, int(time.monotonic() * 1000))

    def get_landmarks(self, results, frame_shape):
        """Return pixel-space (x, y, z) tuples for the first hand, or None."""
        if not results.hand_landmarks:
            return None
        h, w = frame_shape[:2]
        return [(int(lm.x * w), int(lm.y * h), lm.z) for lm in results.hand_landmarks[0]]

    def draw_landmarks(self, frame, results):
        if not results.hand_landmarks:
            return
        h, w = frame.shape[:2]
        for hand_lms in results.hand_landmarks:
            pts = [(int(lm.x * w), int(lm.y * h)) for lm in hand_lms]
            for a, b in _CONNECTIONS:
                cv2.line(frame, pts[a], pts[b], (80, 200, 80), 2)
            for pt in pts:
                cv2.circle(frame, pt, 5, (255, 255, 255), cv2.FILLED)
                cv2.circle(frame, pt, 5, (0, 150, 0), 1)

    def close(self):
        self._landmarker.close()
