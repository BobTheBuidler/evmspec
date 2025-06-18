from typing import Final, Type, TypeVar, Union

import cchecksum
from eth_typing import AnyAddress

from evmspec._utils import to_bytes


__T = TypeVar("__T")


ONE_EMPTY_BYTE: Final = b"\x00"

MISSING_BYTES: Final = tuple((32 - i) * ONE_EMPTY_BYTE for i in range(33))
"""Calculate the number of missing bytes and return them.

Args:
    input_bytes: The input bytes to check.

Returns:
    A bytes object representing the missing bytes.

Examples:
    >>> HexBytes32._get_missing_bytes(HexBytes("0x1234"))
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
"""
to_checksum_address: Final = cchecksum.to_checksum_address


def Address(cls: Type[__T], address: AnyAddress) -> __T:
    return str.__new__(cls, to_checksum_address(address))  # type: ignore [type-var]


def HexBytes32(cls: Type[__T], v: Union[bytes, str]) -> __T:
    # if it has 0x prefix it came from the chain or a user and we should validate the size
    # when it doesnt have the prefix it came out of one of my dbs in a downstream lib and we can trust the size.
    if isinstance(v, str) and v.startswith("0x"):
        cls._check_hexstr(v)  # type: ignore [attr-defined]

    input_bytes = to_bytes(v)
    try:
        missing_bytes = MISSING_BYTES[len(input_bytes)]
    except KeyError as e:
        raise ValueError(f"{repr(v)} is too long: {len(input_bytes)}") from e.__cause__
    return bytes.__new__(cls, missing_bytes + input_bytes)  # type: ignore [type-var]
