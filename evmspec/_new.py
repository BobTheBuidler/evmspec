from typing import Final, Type, TypeVar

import cchecksum
from eth_typing import AnyAddress, HexStr

from evmspec._utils import to_bytes


to_checksum_address: Final = cchecksum.to_checksum_address


def __Address_new__(cls: Type[__T], address: AnyAddress) -> __T:
    return str.__new__(cls, to_checksum_address(address))


def __HexBytes32_new__(cls: Type[__T], b: Union[bytes, str]) -> __T:
    # if it has 0x prefix it came from the chain or a user and we should validate the size
    # when it doesnt have the prefix it came out of one of my dbs in a downstream lib and we can trust the size.
    if isinstance(v, str) and v.startswith("0x"):
        cls._check_hexstr(v)

    input_bytes = to_bytes(v)
    try:
        missing_bytes = _MISSING_BYTES[len(input_bytes)]
    except KeyError as e:
        raise ValueError(f"{v} is too long: {len(input_bytes)}") from e.__cause__
    return bytes.__new__(cls, missing_bytes + input_bytes)
