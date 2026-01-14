from itertools import product
from typing import cast

import pytest
from hexbytes import HexBytes  # type: ignore [import-not-found]

from evmspec.data import uints


def _get_uint_cls_name(num_bytes: int) -> str:
    return f"uint{num_bytes*8}"


def _get_uint_cls(num_bytes: int) -> type[uints._UintData]:
    return cast(type[uints._UintData], getattr(uints, _get_uint_cls_name(num_bytes)))


@pytest.mark.parametrize("num_bytes", range(1, 32))
def test_all(num_bytes: int) -> None:
    assert uints.__all__[num_bytes - 1] == _get_uint_cls_name(num_bytes)


@pytest.mark.parametrize("num_bytes,value", product(range(1, 32), (0, 1, 100)))
def test_uint_init(num_bytes: int, value: int) -> None:
    uint_type = _get_uint_cls(num_bytes)
    assert uint_type(HexBytes(value)) == value


@pytest.mark.parametrize("num_bytes", range(1, 32))
def test_uint_init_out_of_bounds(num_bytes: int) -> None:
    uint_type = _get_uint_cls(num_bytes)
    bits = num_bytes * 8
    max_value = 2**bits - 1
    too_large = max_value + 1
    hexbytes = HexBytes(too_large)
    with pytest.raises(ValueError) as exc_info:
        uint_type(hexbytes)

    e = exc_info.value
    assert (
        len(e.args) == 1
        and e.args[0]
        == f"{hexbytes!r} ({too_large}) is larger than {uint_type.__name__} max value {max_value}"
    )


@pytest.mark.parametrize("num_bytes", range(1, 32))
def test_uint_docstring(num_bytes: int) -> None:
    uint_type = _get_uint_cls(num_bytes)
    cls_name = uint_type.__name__
    bits = num_bytes * 8
    expected = f"Unsigned {bits}-bit integer.\n\nExamples:\n    >>> {cls_name}(HexBytes('0x{'FF' * num_bytes}'))\n    {cls_name}({2**bits - 1})"


@pytest.mark.parametrize("num_bytes", range(1, 32))
def test_uint_cls_attrs(num_bytes: int) -> None:
    uint_type = _get_uint_cls(num_bytes)
    assert uint_type.bytes == num_bytes
    num_bits = num_bytes * 8
    assert uint_type.bits == num_bits
    assert uint_type.max_value == 2**num_bits - 1


@pytest.mark.parametrize("num_bytes", range(1, 32))
def test_uint_instance_attrs(num_bytes: int) -> None:
    uint_type = _get_uint_cls(num_bytes)
    uint_instance = uint_type(HexBytes(num_bytes))
    assert uint_instance.bytes == num_bytes
    num_bits = num_bytes * 8
    assert uint_instance.bits == num_bits
    assert uint_instance.max_value == 2**num_bits - 1
