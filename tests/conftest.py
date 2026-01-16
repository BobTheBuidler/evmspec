import os
import sys


def modify_sys_path() -> None:
    """
    Inserts the absolute path of the current working directory at the beginning of the system path.

    This function modifies the Python system path to include the absolute
    path of the current working directory as the first entry. This allows
    the Python interpreter to prioritize imports from the current working
    directory over other directories in the path.
    """
    sys.path.insert(0, os.path.abspath("."))
    dictstruct_path = os.path.abspath(
        os.path.join(os.path.dirname(__file__), "..", "..", "dictstruct")
    )
    if os.path.isdir(dictstruct_path):
        sys.path.insert(0, dictstruct_path)


modify_sys_path()
