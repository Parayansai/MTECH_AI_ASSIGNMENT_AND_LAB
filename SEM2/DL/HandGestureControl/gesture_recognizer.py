"""
Gesture database:
PINCH     thumb + index tips nearly touching   continuous volume slider
FIST      all four fingers curled              toggle mute
OPEN_PALM all four fingers extended            volume max
PEACE     index + middle up, ring + pinky down volume 50 %
POINTING  index only up                        volume 25 %
UNKNOWN   anything else
"""

import math
from enum import Enum

# MediaPipe landmark indices
WRIST      = 0
THUMB_TIP  = 4
INDEX_MCP  = 5;  INDEX_PIP  = 6;  INDEX_TIP  = 8
MIDDLE_MCP = 9;  MIDDLE_PIP = 10; MIDDLE_TIP = 12
RING_PIP   = 14; RING_TIP   = 16
PINKY_PIP  = 18; PINKY_TIP  = 20


class Gesture(Enum):
    UNKNOWN   = "Unknown"
    FIST      = "Fist - Mute Toggle"
    OPEN_PALM = "Open Palm - Volume Max"
    PINCH     = "Pinch - Volume Slider"
    PEACE     = "Peace - Volume 50%"
    POINTING  = "Pointing - Volume 25%"


class GestureRecognizer:
    # fraction of hand span to activate pinch mode.
    PINCH_RATIO = 0.18

    @staticmethod
    def _dist(p1, p2):
        return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

    def _hand_scale(self, lm):
        """Wrist-to-middle-MCP length — stable reference regardless of camera distance."""
        return max(self._dist(lm[WRIST], lm[MIDDLE_MCP]), 1)

    def _finger_up(self, lm, tip, pip):
        return lm[tip][1] < lm[pip][1]  

    def get_pinch_ratio(self, landmarks):
        """Thumb-to-index distance normalised by hand size (0 = closed, 1 = open)."""
        raw = self._dist(landmarks[THUMB_TIP], landmarks[INDEX_TIP])
        return raw / self._hand_scale(landmarks)

    def recognize(self, landmarks):
        if landmarks is None:
            return Gesture.UNKNOWN

        lm = landmarks

        if self.get_pinch_ratio(lm) < self.PINCH_RATIO:
            return Gesture.PINCH

        index_up  = self._finger_up(lm, INDEX_TIP,  INDEX_PIP)
        middle_up = self._finger_up(lm, MIDDLE_TIP, MIDDLE_PIP)
        ring_up   = self._finger_up(lm, RING_TIP,   RING_PIP)
        pinky_up  = self._finger_up(lm, PINKY_TIP,  PINKY_PIP)
        fingers_up = sum([index_up, middle_up, ring_up, pinky_up])

        if fingers_up == 0:
            return Gesture.FIST
        if fingers_up == 4:
            return Gesture.OPEN_PALM
        if index_up and middle_up and not ring_up and not pinky_up:
            return Gesture.PEACE
        if index_up and not middle_up and not ring_up and not pinky_up:
            return Gesture.POINTING

        return Gesture.UNKNOWN
