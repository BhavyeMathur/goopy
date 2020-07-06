import time
import os
import sys

from goopy.constants import _root, _update_lasttime

class GraphicsError(Exception):
    """Generic error class for graphics module exceptions."""
    pass


class GraphicsWarning(Warning):
    pass

# Other Image Functions

def resource_path(relative_path):
    # Get absolute path to resource, works for dev and for PyInstaller
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except AttributeError:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)


def wait(t):
    time.sleep(t)


# Time Related Functions

def update(rate=None):
    global _update_lasttime
    if rate:
        now = time.time()
        pauseLength = 1 / rate - (now - _update_lasttime)
        if pauseLength > 0:
            time.sleep(pauseLength)
            _update_lasttime = now + pauseLength
        else:
            _update_lasttime = now

    _root.update()


def getScreenSize():
    return _root.winfo_screenwidth(), _root.winfo_screenheight()