from datetime import datetime, timezone
from decimal import Decimal
from enum import Enum
from functools import cached_property
from typing import TYPE_CHECKING, Any, Callable, Tuple, Type, TypeVar, Union

from cchecksum import to_checksum_address
from hexbytes import HexBytes
from hexbytes._utils import to_bytes
from msgspec import Raw, Struct, json
from typing_extensions import Self

from evmspec.data._cache import ttl_cache

if TYPE_CHECKING:
    from evmspec.structs.log import Log
    from evmspec.structs.receipt import TransactionReceipt


_T = TypeVar("_T")
"""A generic type variable."""

DecodeHook = Callable[[Type[_T], Any], _T]
"""A type alias for a function that decodes an object into a specific type."""


class Address(str):
    """
    Represents an Ethereum address in its EIP-55 checksum format.

    This class ensures that any Ethereum address is stored in its checksummed format,
    as defined by EIP-55. It uses a custom Cython implementation for the checksum
    conversion to optimize performance.

    Examples:
        >>> addr = Address("0x52908400098527886E0F7030069857D2E4169EE7")
        >>> print(addr)
        0x52908400098527886E0F7030069857D2E4169EE7

    See Also:
        - `cchecksum.to_checksum_address`: Function used for checksum conversion.
    """

    def __new__(cls, address: str):
        """Creates a new Address instance with checksum validation.

        This function takes a hex address and returns it in the checksummed format
        as defined by EIP-55. It uses a custom Cython implementation for the
        checksum conversion to optimize performance.

        Args:
            address: A string representing the Ethereum address.

        Returns:
            An Address object with a checksummed address.

        Examples:
            >>> Address("0xde0B295669a9FD93d5F28D9Ec85E40f4cb697BAe")
            Address('0xDe0B295669a9FD93d5F28D9Ec85E40f4cb697BAe')

        See Also:
            - `cchecksum.to_checksum_address`: Function used for checksum conversion.
        """
        return __str_new__(cls, to_checksum_address(address))

    @classmethod
    def _decode_hook(cls, typ: Type["Address"], obj: str):
        """Decodes an object into an Address instance with checksum validation.

        This function takes a hex address and returns it in the checksummed format
        as defined by EIP-55. It uses a custom Cython implementation for the
        checksum conversion to optimize performance.

        Args:
            typ: The type that is expected to be decoded to.
            obj: The object to decode, expected to be a string representation of an Ethereum address.

        Returns:
            An Address object with a checksummed address.

        Examples:
            >>> Address._decode_hook(Address, "0xde0B295669a9FD93d5F28D9Ec85E40f4cb697BAe")
            Address('0xDe0B295669a9FD93d5F28D9Ec85E40f4cb697BAe')

        Note:
            This method utilizes :meth:`cls.checksum` as a class method to ensure the address is checksummed.

        See Also:
            - `cchecksum.to_checksum_address`: Function used for checksum conversion.
        """
        return cls.checksum(obj)

    @classmethod
    def checksum(cls, address: str) -> Self:
        """Returns the checksummed version of the address.

        This function takes a hex address and returns it in the checksummed format
        as defined by EIP-55. It uses a custom Cython implementation for the
        checksum conversion to optimize performance.

        Args:
            address: A string representing the Ethereum address.

        Returns:
            The checksummed Ethereum address.

        Examples:
            >>> Address.checksum("0xde0B295669a9FD93d5F28D9Ec85E40f4cb697BAe")
            Address('0xDe0B295669a9FD93d5F28D9Ec85E40f4cb697BAe')

        See Also:
            - `cchecksum.to_checksum_address`: Function used for checksum conversion.
        """
        # there is a race condition in the cache expire function due to
        # my hacky removal of the threading.Lock from ttl_cache, but
        # the race condition can be ignored for our use-case
        while True:
            try:
                return cls.__checksum(address)
            except KeyError:
                pass

    @classmethod
    @ttl_cache(maxsize=None, ttl=600)
    def __checksum(cls, address: str) -> Self:
        return cls(address)


# Integers


class uint(int):
    """
    Represents an unsigned integer with additional utility methods for hexadecimal conversion and representation.

    Examples:
        >>> num = uint.fromhex("0x1a")
        >>> print(num)
        uint(26)

    See Also:
        - :meth:`uint.fromhex`: Method to create a uint from a hexadecimal string.
    """

    @classmethod
    def fromhex(cls, hexstr: str) -> Self:
        """Converts a hexadecimal string to a uint.

        Args:
            hexstr: A string representing a hexadecimal number.

        Returns:
            A uint object representing the integer value of the hexadecimal string.

        Examples:
            >>> uint.fromhex("0x1a")
            uint(26)
        """
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
        """Decodes a hexadecimal string into a uint.

        Args:
            typ: The type that is expected to be decoded to.
            obj: The object to decode, expected to be a hexadecimal string.

        Returns:
            A uint object representing the decoded value.

        Examples:
            >>> uint._decode_hook(uint, "0x1a")
            uint(26)
        """
        return typ(obj, 16)

    @classmethod
    def _decode(cls, obj) -> "uint":
        """Attempts to decode an object as a uint, handling TypeErrors.

        Args:
            obj: The object to decode, expected to be a hexadecimal string or an integer.

        Returns:
            A uint object representing the decoded value.

        Raises:
            TypeError: If the object cannot be converted to a uint.

        Examples:
            >>> uint._decode("0x1a")
            uint(26)
            >>> uint._decode(26)
            uint(26)
        """
        try:
            return cls.fromhex(obj)
        except TypeError as e:
            if "int() can't convert non-string with explicit base" in str(e):
                return cls(obj)
            raise


class Wei(uint):
    @cached_property
    def scaled(self) -> "Decimal":
        """Returns the scaled decimal representation of Wei.

        Calculation:
            The value in Wei divided by 10**18 to convert to Ether.

        Examples:
            >>> wei_value = Wei(1000000000000000000)
            >>> wei_value.scaled
            Decimal('1')
        """
        return Decimal(self) / 10**18

    # @property
    # def as_gwei(self) -> "Gwei":
    #    return Gwei(self) / 10**9


class BlockNumber(uint): ...


class Nonce(uint): ...


class UnixTimestamp(uint):
    @cached_property
    def datetime(self) -> datetime:
        """Converts the Unix timestamp to a datetime object in UTC.

        Returns:
            A datetime object representing the UTC date and time.

        Examples:
            >>> timestamp = UnixTimestamp(1638316800)
            >>> timestamp.datetime
            datetime.datetime(2021, 12, 1, 0, 0, tzinfo=datetime.timezone.utc)
        """
        return datetime.fromtimestamp(self, tz=timezone.utc)


# Hook


def _decode_hook(typ: Type, obj: object):
    """A generic decode hook for converting objects to specific types.

    Args:
        typ: The type that is expected to be decoded to.
        obj: The object to decode.

    Returns:
        The object decoded to the specified type.

    Raises:
        NotImplementedError: If the type cannot be handled.

    Examples:
        >>> _decode_hook(uint, "0x1a")
        uint(26)
        >>> _decode_hook(Address, "0xde0B295669a9FD93d5F28D9Ec85E40f4cb697BAe")
        Address('0xDe0B295669a9FD93d5F28D9Ec85E40f4cb697BAe')

    See Also:
        - :class:`Address`: For decoding Ethereum addresses.
        - :class:`uint`: For decoding unsigned integers.
    """
    if issubclass(typ, (HexBytes, Enum, Decimal)):
        return typ(obj)  # type: ignore [arg-type]
    elif typ is Address:
        return Address.checksum(obj)  # type: ignore [arg-type]
    elif issubclass(typ, uint):
        if isinstance(obj, str):
            # if obj.startswith("0x"):
            return typ.fromhex(obj)
            # elif obj == "":
            #    return None if typ is ChainId else UNSET  # TODO: refactor
        else:
            return typ(obj)  # type: ignore [call-overload]
    raise NotImplementedError(typ, obj, type(obj))


# Hexbytes

ONE_EMPTY_BYTE = bytes(HexBytes("0x00"))


_MISSING_BYTES = {i: (32 - i) * ONE_EMPTY_BYTE for i in range(0, 33)}
"""Calculate the number of missing bytes and return them.

Args:
    input_bytes: The input bytes to check.

Returns:
    A bytes object representing the missing bytes.

Examples:
    >>> HexBytes32._get_missing_bytes(HexBytes("0x1234"))
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
"""

_hex = bytes.hex
"""An alias for `bytes.hex`"""


class HexBytes32(HexBytes):
    def __new__(cls, v):
        """Create a new HexBytes32 object.

        Args:
            v: A value that can be converted to HexBytes32.

        Returns:
            A HexBytes32 object.

        Raises:
            ValueError: If the string representation is not the correct length.

        Examples:
            >>> HexBytes32("0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef")
            HexBytes32(0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef)
        """
        # if it has 0x prefix it came from the chain or a user and we should validate the size
        # when it doesnt have the prefix it came out of one of my dbs in a downstream lib and we can trust the size.
        if isinstance(v, str) and v.startswith("0x"):
            cls._check_hexstr(v)

        input_bytes = to_bytes(v)
        try:
            missing_bytes = _MISSING_BYTES[len(input_bytes)]
        except KeyError as e:
            raise ValueError(f"{v} is too long: {len(input_bytes)}") from e.__cause__
        return __bytes_new__(cls, missing_bytes + input_bytes)

    def __repr__(self) -> str:
        return f"{type(self).__name__}(0x{_hex(self)})"

    __getitem__ = lambda self, key: HexBytes(self)[key]  # type: ignore [assignment]

    # TODO: keep the instance small and just task on the length for operations as needed
    # def __len__(self) -> Literal[32]:
    #    return 32

    def __hash__(self) -> int:
        return hash(_hex(self))

    def hex(self) -> str:
        """
        Output hex-encoded bytes, with an "0x" prefix.

        Everything following the "0x" is output exactly like :meth:`bytes.hex`.
        """
        return f"0x{_hex(self)}"

    def strip(self) -> str:  # type: ignore [override]
        """Returns self.hex() with leading zeroes removed.

        Examples:
            >>> hb = HexBytes32("0x0000000000000000000000000000000000000000000000000000000000001234")
            >>> hb.strip()
            '1234'
        """
        # we trim all leading zeroes since we know how many we need to put back later
        return hex(int(_hex(self), 16))[2:]

    @staticmethod
    def _check_hexstr(hexstr: str):
        """Checks if a hex string is of a valid length.

        Args:
            hexstr: The hex string to check.

        Raises:
            ValueError: If the hex string is of an invalid length.

        Examples:
            >>> HexBytes32._check_hexstr("0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef")
            # No exception raised
        """
        l = len(hexstr)
        if l > 66:
            raise ValueError("too high", len(hexstr), hexstr)
        elif l < 66:
            raise ValueError("too smol", len(hexstr), hexstr)


class TransactionHash(HexBytes32):

    try:
        from a_sync import a_sync
    except ImportError:
        a_sync = None

    if a_sync:

        StructType = TypeVar("StructType", bound=Struct)
        ReceiptDataType = Union[Type[Raw], Type[StructType]]

        @a_sync("async")
        async def get_receipt(
            self,
            decode_to: ReceiptDataType,
            decode_hook: DecodeHook[ReceiptDataType] = _decode_hook,
        ) -> "TransactionReceipt":
            """Async method to get the transaction receipt.

            Args:
                decode_to: The type to decode the receipt to.
                decode_hook: A hook function to perform the decoding.

            Returns:
                A TransactionReceipt object for the transaction.

            Raises:
                ImportError: If 'dank_mids' cannot be imported.

            Examples:
                >>> tx_hash = TransactionHash("0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef")
                >>> await tx_hash.get_receipt(TransactionReceipt)
                # Returns a TransactionReceipt object
            """
            import dank_mids

            return await dank_mids.eth.get_transaction_receipt(
                self, decode_to=decode_to, decode_hook=decode_hook
            )

        @a_sync  # TODO; compare how these type check, they both function the same
        async def get_logs(self) -> Tuple["Log", ...]:
            """Async method to get the logs for the transaction.

            Returns:
                A tuple of Log objects for the transaction.

            Raises:
                ImportError: If 'dank_mids' cannot be imported.

            Examples:
                >>> tx_hash = TransactionHash("0x1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef")
                >>> await tx_hash.get_logs()
                # Returns a tuple of Log objects
            """
            try:
                import dank_mids
            except ImportError as e:
                raise ImportError(
                    "You must have dank_mids installed in order to use this feature"
                ) from e.__cause__

            receipt = await dank_mids.eth._get_transaction_receipt_raw(self)
            return json.decode(receipt, type=Tuple["Log", ...], dec_hook=_decode_hook)


class BlockHash(HexBytes32): ...


__str_new__ = str.__new__
__bytes_new__ = bytes.__new__
