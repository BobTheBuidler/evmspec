import os
import sys


def modify_sys_path():
    """
    Inserts the absolute path of the script's directory at the beginning of the system path.

    This function modifies the Python system path to include the absolute
    path of the directory where the script is located as the first entry.
    This allows the Python interpreter to prioritize imports from the script's
    directory over other directories in the path.
    """
    sys.path.insert(0, os.path.abspath("."))


modify_sys_path()
