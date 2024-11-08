
from cachetools.func import ttl_cache
from decimal import Decimal
from functools import cached_property
from typing import Type

from eth_utils import to_checksum_address
from typing_extensions import Self


class Address(str):
    def __new__(cls, address: str):
        return super().__new__(cls, to_checksum_address(address))

    @classmethod
    def _decode_hook(cls, typ: Type["Address"], obj: str):
        return cls.checksum(obj)

    @classmethod
    @ttl_cache(ttl=600)
    def checksum(cls, address: str) -> Self:
        return cls(address)


# Integers



class uint(int):
    @classmethod
    def fromhex(cls, hexstr: str) -> Self:
        return cls(hexstr, 16)

    """
    NOTE: Storing encoded data as string is cheaper than ints when integer value is sufficiently high:
    
    string: 0x1  integer: 1
    string: 0x10  integer: 16
    string: 0x100  integer: 256
    string: 0x1000  integer: 4096
    string: 0x10000  integer: 65536
    string: 0x100000  integer: 1048576
    string: 0x1000000  integer: 16777216
    string: 0x10000000  integer: 268435456
    string: 0x100000000  integer: 4294967296
    string: 0x1000000000  integer: 68719476736
    string: 0x10000000000  integer: 1099511627776
    """

    def __repr__(self) -> str:
        return f"{type(self).__name__}({int.__repr__(self)})"

    # we dont want str to use our new repr
    __str__ = int.__repr__

    @classmethod
    def _decode_hook(cls, typ: Type["uint"], obj: str):
        return typ(obj, 16)

    @classmethod
    def _decode(cls, obj) -> "uint":
        try:
            return cls.fromhex(obj)
        except TypeError as e:
            if "int() can't convert non-string with explicit base" in str(e):
                return cls(obj)
            raise


class Wei(uint):
    @cached_property
    def scaled(self) -> "Decimal":
        return Decimal(self) / 10**18

    #@property
    #def as_gwei(self) -> "Gwei":
    #    return Gwei(self) / 10**9