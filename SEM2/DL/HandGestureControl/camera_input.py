import cv2


class CameraInput:
    def __init__(self, camera_index=0, width=640, height=480):
        self.cap = cv2.VideoCapture(camera_index)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        if not self.cap.isOpened():
            raise RuntimeError(f"Cannot open camera at index {camera_index}")

    def read_frame(self):
        success, frame = self.cap.read()
        if not success:
            return None
        return cv2.flip(frame, 1)  # mirror so movement feels natural

    def preprocess(self, frame):
        """Return an RGB read-only copy suitable for MediaPipe."""
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        rgb.flags.writeable = False
        return rgb

    def release(self):
        self.cap.release()
