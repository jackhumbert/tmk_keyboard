"""Functions that help us work with files and folders.
"""
import logging
import os
from pathlib import Path

from qmk.constants import MAX_KEYBOARD_SUBFOLDERS, QMK_FIRMWARE
from qmk.errors import NoSuchKeyboardError


def is_keyboard(keyboard_name):
    """Returns True if `keyboard_name` is a keyboard we can compile.
    """
    if keyboard_name:
        keyboard_path = QMK_FIRMWARE / 'keyboards' / keyboard_name
        rules_mk = keyboard_path / 'rules.mk'
        return rules_mk.exists()


def under_qmk_firmware():
    """Returns a Path object representing the relative path under qmk_firmware, or None.
    """
    cwd = Path(os.environ['ORIG_CWD'])

    try:
        return cwd.relative_to(QMK_FIRMWARE)
    except ValueError:
        return None


def keymap(keyboard):
    """Locate the correct directory for storing a keymap.

    Args:

        keyboard
            The name of the keyboard. Example: clueboard/66/rev3
    """
    keyboard_folder = Path('keyboards') / keyboard

    for i in range(MAX_KEYBOARD_SUBFOLDERS):
        if (keyboard_folder / 'keymaps').exists():
            return (keyboard_folder / 'keymaps').resolve()

        keyboard_folder = keyboard_folder.parent

    logging.error('Could not find the keymaps directory!')
    raise NoSuchKeyboardError('Could not find keymaps directory for: %s' % keyboard)


def normpath(path):
    """Returns a `pathlib.Path()` object for a given path.

    This will use the path to a file as seen from the directory the script was called from. You should use this to normalize filenames supplied from the command line.
    """
    path = Path(path)

    if path.is_absolute():
        return path

    return Path(os.environ['ORIG_CWD']) / path
