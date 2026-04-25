import ctypes
from ctypes import cast, POINTER

try:
    import comtypes
    from comtypes import CLSCTX_ALL
    from pycaw.pycaw import IAudioEndpointVolume, IMMDeviceEnumerator, CLSID_MMDeviceEnumerator
    _PYCAW_AVAILABLE = True
except Exception:
    _PYCAW_AVAILABLE = False

# Virtual-key codes for media keys
_VK_MUTE = 0xAD
_VK_DOWN = 0xAE
_VK_UP   = 0xAF
_EXT     = 0x0001  # KEYEVENTF_EXTENDEDKEY
_EXT_UP  = 0x0003  # KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP


def _press_key(vk):
    ctypes.windll.user32.keybd_event(vk, 0, _EXT, 0)
    ctypes.windll.user32.keybd_event(vk, 0, _EXT_UP, 0)


def _get_audio_interface():
    """Enumerate all three Windows audio roles and return the first working endpoint."""
    enumerator = comtypes.CoCreateInstance(
        CLSID_MMDeviceEnumerator, IMMDeviceEnumerator, comtypes.CLSCTX_INPROC_SERVER
    )
    for role in (0, 1, 2):  # eConsole, eMultimedia, eCommunications
        try:
            device = enumerator.GetDefaultAudioEndpoint(0, role)  # 0 = eRender
            iface  = device.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
            vol    = cast(iface, POINTER(IAudioEndpointVolume))
            vol.GetMasterVolumeLevel()  # sanity check
            return vol
        except Exception:
            continue
    return None


class VolumeController:
    def __init__(self):
        self._vol      = None
        self._min_db   = -65.25
        self._max_db   = 0.0
        self._fb_level = 0.5   # tracked level for fallback mode
        self._fb_muted = False

        if _PYCAW_AVAILABLE:
            try:
                self._vol = _get_audio_interface()
                if self._vol is not None:
                    r = self._vol.GetVolumeRange()
                    self._min_db, self._max_db = r[0], r[1]
                    print("[VolumeController] Using Windows Core Audio.")
                    return
            except Exception as e:
                print(f"[VolumeController] pycaw failed: {e}")

        print("[VolumeController] Using media-key fallback.")

    @property
    def _pycaw(self):
        return self._vol is not None

    def _to_db(self, level):
        return self._min_db + (self._max_db - self._min_db) * max(0.0, min(1.0, level))

    def _from_db(self, db):
        span = self._max_db - self._min_db
        return (db - self._min_db) / span if span else 0.0

    def set_volume(self, level: float):
        level = max(0.0, min(1.0, level))
        if self._pycaw:
            self._vol.SetMasterVolumeLevel(self._to_db(level), None)
        else:
            # Windows has ~50 volume steps; each key press moves 2 %.
            steps = round(abs(level - self._fb_level) * 50)
            vk    = _VK_UP if level > self._fb_level else _VK_DOWN
            for _ in range(steps):
                _press_key(vk)
            self._fb_level = level

    def get_volume(self) -> float:
        if self._pycaw:
            return self._from_db(self._vol.GetMasterVolumeLevel())
        return self._fb_level

    def mute(self):
        if self._pycaw:
            self._vol.SetMute(1, None)
        elif not self._fb_muted:
            _press_key(_VK_MUTE)
            self._fb_muted = True

    def unmute(self):
        if self._pycaw:
            self._vol.SetMute(0, None)
        elif self._fb_muted:
            _press_key(_VK_MUTE)
            self._fb_muted = False

    def toggle_mute(self):
        if self._pycaw:
            self._vol.SetMute(not self._vol.GetMute(), None)
        else:
            _press_key(_VK_MUTE)
            self._fb_muted = not self._fb_muted

    def is_muted(self) -> bool:
        return bool(self._vol.GetMute()) if self._pycaw else self._fb_muted
