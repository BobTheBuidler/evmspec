"""
This module provides classes to decode and represent unsigned integer
types of any byte size, ensuring values adhere to defined minimum and maximum constraints.

Note:
    While only a few specific classes like :class:`uint8`, :class:`uint64`,
    :class:`uint128`, and :class:`uint256` are explicitly defined,
    other classes are dynamically generated for byte sizes from 2 to 31, excluding those already defined.
"""

import sys

from hexbytes import HexBytes

from evmspec.data._main import uint


class _UintData(uint):
    """
    Base class for unsigned integer types with specific byte sizes.

    This class provides a framework to define unsigned integer types of any byte size,
    ensuring values adhere to defined minimum and maximum constraints.

    Note:
        Classes for the following byte sizes are explicitly defined: :class:`uint8`, :class:`uint64`,
        :class:`uint128`, and :class:`uint256`. For other byte sizes from 2 to 31, excluding those
        explicitly defined, classes are dynamically generated.

    See Also:
        :class:`uint8`, :class:`uint64`, :class:`uint128`, :class:`uint256`
    """

    bytes: int
    bits: int
    min_value = 0
    max_value: int

    def __new__(cls, v: HexBytes):
        """
        Create a new unsigned integer of the specified type from a hex byte value.

        Args:
            v: The value to be converted into the unsigned integer type.

        Raises:
            ValueError: If the value is smaller than the minimum value or larger than
            the maximum value.

        Examples:
            >>> uint8(HexBytes('0x01'))
            uint8(1)

            >>> uint256(HexBytes('0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'))
            uint256(115792089237316195423570985008687907853269984665640564039457584007913129639935)
        """
        if v:
            new = __int_new__(cls, bytes.hex(v), 16)
        else:
            new = __int_new__(cls, 0)
        if new < cls.min_value:
            raise ValueError(
                f"{v!r} ({new}) is smaller than {cls.__name__} min value {cls.min_value}"
            )
        if new > cls.max_value:
            raise ValueError(
                f"{v!r} ({new}) is larger than {cls.__name__} max value {cls.max_value}"
            )
        return new


class uint8(_UintData):
    """Unsigned 8-bit integer.

    Examples:
        >>> uint8(HexBytes('0x01'))
        uint8(1)
    """

    bytes = 1
    bits = bytes * 8
    max_value = 2**bits - 1


class uint64(_UintData):
    """Unsigned 64-bit integer.

    Examples:
        >>> uint64(HexBytes('0xFFFFFFFFFFFFFFFF'))
        uint64(18446744073709551615)
    """

    bytes = 8
    bits = bytes * 8
    max_value = 2**bits - 1


class uint128(_UintData):
    """Unsigned 128-bit integer.

    Examples:
        >>> uint128(HexBytes('0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'))
        uint128(340282366920938463463374607431768211455)
    """

    bytes = 16
    bits = bytes * 8
    max_value = 2**bits - 1


class uint256(_UintData):
    """Unsigned 256-bit integer.

    Examples:
        >>> uint256(HexBytes('0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'))
        uint256(115792089237316195423570985008687907853269984665640564039457584007913129639935)
    """

    bytes = 32
    bits = bytes * 8
    max_value = 2**bits - 1


# dynamically define classes for remaining uint types
for i in range(1, 32):
    if i in [1, 8, 16, 32]:
        # These types are already defined above
        continue

    bits = i * 8
    cls_name = f"uint{bits}"
    docstring = f"Unsigned {bits}-bit integer.\n\nExamples:\n    >>> {cls_name}(HexBytes('0x{'FF' * i}'))\n    {cls_name}({2**bits - 1})"
    new_cls = type(
        cls_name,
        (_UintData,),
        {
            "bits": bits,
            "bytes": i,
            "max_value": 2**bits - 1,
            "__doc__": docstring,
        },
    )
    setattr(sys.modules[__name__], cls_name, new_cls)

__all__ = [f"uint{bytes*8}" for bytes in range(1, 32)]

__int_new__ = int.__new__
