from cachetools.func import ttl_cache
from decimal import Decimal
from enum import Enum
from functools import cached_property
from typing import Tuple, Type

from eth_utils import to_checksum_address
from hexbytes import HexBytes
from msgspec import json
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

    # @property
    # def as_gwei(self) -> "Gwei":
    #    return Gwei(self) / 10**9


class BlockNumber(uint):
    ...


# Hook


def _decode_hook(typ: Type, obj: object):
    if issubclass(typ, (HexBytes, Enum, Decimal)):
        return typ(obj)  # type: ignore [arg-type]
    elif typ is Address:
        return Address.checksum(obj)
    elif issubclass(typ, uint):
        if isinstance(obj, str):
            # if obj.startswith("0x"):
            return typ.fromhex(obj)
            # elif obj == "":
            #    return None if typ is ChainId else UNSET  # TODO: refactor
        else:
            return typ(obj)
    raise NotImplementedError(typ, obj, type(obj))


# Hexbytes

ONE_EMPTY_BYTE = bytes(HexBytes("0x00"))


class HexBytes32(HexBytes):
    def __new__(cls, v):
        # if it has 0x prefix it came from the chain or a user and we should validate the size
        # when it doesnt have the prefix it came out of one of my dbs in a downstream lib and we can trust the size.
        if isinstance(v, str) and v.startswith("0x"):
            cls._check_hexstr(v)
        input_bytes = HexBytes(v)
        return super().__new__(cls, cls._get_missing_bytes(input_bytes) + input_bytes)

    def __repr__(self) -> str:
        return f"{type(self).__name__}({self.hex()})"

    __getitem__ = lambda self, key: HexBytes(self)[key]

    # TODO: keep the instance small and just task on the length for operations as needed
    # def __len__(self) -> Literal[32]:
    #    return 32

    @staticmethod
    def _get_missing_bytes(input_bytes: HexBytes) -> bytes:
        missing_length = 32 - len(input_bytes)
        return missing_length * ONE_EMPTY_BYTE

    def __hash__(self) -> int:
        return hash(self.hex())

    def strip(self) -> str:
        """Returns self.hex() with leading zeroes removed."""
        # we trim all leading zeroes since we know how many we need to put back later
        return hex(int(self.hex(), 16))[2:]

    @staticmethod
    def _check_hexstr(hexstr: str):
        l = len(hexstr)
        if l > 66:
            raise ValueError("too high", len(hexstr), hexstr)
        elif l < 66:
            raise ValueError("too smol", len(hexstr), hexstr)


class TransactionHash(HexBytes32):

    try:
        from a_sync import a_sync

        @a_sync("async")
        async def get_receipt(
            self, decode_to: Type["T"], decode_hook: "DecodeHook" = _decode_hook
        ) -> "TransactionReceipt":
            import dank_mids

            return await dank_mids.eth.get_transaction_receipt(
                self, decode_to=decode_to, decode_hook=decode_hook
            )

        @a_sync  # TODO; compare how these type check, they both function the same
        async def get_logs(self) -> Tuple["Log", ...]:
            try:
                import dank_mids
                from dank_mids.structs.log import Log
            except ImportError:
                raise ImportError(
                    "You must have dank_mids installed in order to use this feature"
                )

            receipt = await dank_mids.eth._get_transaction_receipt_raw(self)
            return json.decode(receipt, type=Tuple[Log, ...], dec_hook=_decode_hook)

    except ImportError:
        pass


class BlockHash(HexBytes32):
    ...
