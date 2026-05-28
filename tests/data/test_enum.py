from enum import Enum

import pytest

from evmspec.data._enum import StringToIntEnumMeta


class Color(Enum, metaclass=StringToIntEnumMeta):
    RED = 1
    GREEN = 2


def test_string_to_int_enum_meta() -> None:
    assert Color("RED") is Color.RED
    assert Color(1) is Color.RED
    assert Color("GREEN") is Color.GREEN


def test_string_to_int_enum_meta_invalid() -> None:
    with pytest.raises(ValueError):
        Color("BLUE")
