import enum
from datetime import timezone
from decimal import Decimal

import pytest
from cchecksum import to_checksum_address
from faster_hexbytes import HexBytes as FasterHexBytes  # type: ignore [import-not-found]
from hexbytes import HexBytes  # type: ignore [import-not-found]

from evmspec.data import Address, HexBytes32, UnixTimestamp, Wei, uint
from evmspec.data._main import _decode_hook, _decode_hook_unsafe

ADDRESS_LOWER = "0xde0b295669a9fd93d5f28d9ec85e40f4cb697bae"
ADDRESS_CHECKSUM = "0xDe0B295669a9FD93d5F28D9Ec85E40f4cb697BAe"
HEX32 = "0x" + "11" * 32


def test_address_checksum_and_reduce() -> None:
    addr = Address(ADDRESS_LOWER)
    assert str(addr) == to_checksum_address(ADDRESS_LOWER)

    reduce_fn, args = addr.__reduce__()
    rebuilt = reduce_fn(*args)
    assert isinstance(rebuilt, Address)
    assert str(rebuilt) == to_checksum_address(ADDRESS_LOWER)


def test_address_decode_hooks() -> None:
    decoded = Address._decode_hook(Address, ADDRESS_LOWER)
    assert decoded == Address(to_checksum_address(ADDRESS_LOWER))

    unsafe = Address._decode_hook_unsafe(Address, ADDRESS_LOWER)
    assert unsafe == ADDRESS_LOWER


def test_uint_decode_and_repr() -> None:
    assert uint.fromhex("0x1a") == 26
    assert uint._decode("0x1a") == 26
    assert uint._decode(26) == 26
    assert repr(uint(26)) == "uint(26)"
    assert str(uint(26)) == "26"


def test_wei_scaled() -> None:
    assert Wei(10**18).scaled == Decimal("1")


def test_unix_timestamp_datetime() -> None:
    ts = UnixTimestamp(0)
    assert ts.datetime.tzinfo is timezone.utc
    assert ts.datetime.timestamp() == 0


def test_decode_hook_variants() -> None:
    assert _decode_hook(HexBytes, "0x01") == HexBytes("0x01")
    assert _decode_hook(Decimal, "1.5") == Decimal("1.5")

    class ExampleEnum(int, enum.Enum):
        one = 1

    assert _decode_hook(ExampleEnum, 1) is ExampleEnum.one
    assert _decode_hook(uint, "0x2") == 2


def test_decode_hook_unsupported() -> None:
    with pytest.raises(NotImplementedError):
        _decode_hook(list, "value")


def test_decode_hook_unsafe_address() -> None:
    decoded = _decode_hook_unsafe(Address, ADDRESS_LOWER)
    assert decoded == ADDRESS_LOWER


def test_hexbytes32_repr_hex_strip_hash() -> None:
    hb = HexBytes32("0x" + "00" * 31 + "12")
    assert repr(hb) == f"HexBytes32(0x{bytes.hex(hb)})"
    assert hb.hex() == f"0x{bytes.hex(hb)}"
    assert hb.strip() == "12"
    assert hash(hb) == hash(bytes(hb))
    zeroed = HexBytes32("0x" + "00" * 32)
    assert zeroed.strip() == "0"


def test_hexbytes32_getitem() -> None:
    hb = HexBytes32(HEX32)
    raw = bytes(hb)
    assert isinstance(hb[0], int)
    assert hb[0] == raw[0]
    assert hb[-1] == raw[-1]
    sliced = hb[:2]
    assert isinstance(sliced, FasterHexBytes)


def test_hexbytes32_check_hexstr() -> None:
    HexBytes32._check_hexstr(HEX32)
    with pytest.raises(ValueError):
        HexBytes32._check_hexstr("0x" + "11" * 31)
    with pytest.raises(ValueError):
        HexBytes32._check_hexstr("0x" + "11" * 33)


def test_hexbytes32_too_long_bytes() -> None:
    with pytest.raises(ValueError):
        HexBytes32(b"\x00" * 33)
