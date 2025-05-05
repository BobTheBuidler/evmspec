from typing import Final, Type, TypeVar

import cchecksum
from eth_typing import AnyAddress

from evmspec._utils import to_bytes


to_checksum_address: Final = cchecksum.to_checksum_address


def __Address_new__(cls: Type[__T], address: AnyAddress) -> __T:
    return str.__new__(cls, to_checksum_address(address))


def __HexBytes32_new__(cls: Type[__T], b) -> __T:
    return bytes.__new__(cls, to_bytes(b))
