import sys

from hexbytes import HexBytes

from evmspec.data import uint


class _UintData(uint):
    """
    Base class for unsigned integer types with specific byte sizes.

    The class provides a framework to define unsigned integer types of any byte size,
    ensuring values adhere to defined minimum and maximum constraints.

    Attributes:
        bytes (int): The number of bytes for the unsigned integer type.
        bits (int): The number of bits for the unsigned integer type.
        min_value (int): The minimum permissible value (default is 0).
        max_value (int): The maximum permissible value for the type.
    """

    bytes: int
    bits: int
    min_value = 0
    max_value: int

    def __new__(cls, v: HexBytes):
        """
        Create a new unsigned integer of the specified type from a hex byte value.

        Args:
            v (HexBytes): The value to be converted into the unsigned integer type.

        Raises:
            ValueError: If the value is smaller than the minimum value or larger than
            the maximum value.
        """
        new = super().__new__(cls, v.hex() if v else "0x0", 16)
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
    """Unsigned 8-bit integer."""

    bytes = 1
    bits = bytes * 8
    max_value = 2**bits - 1


class uint64(_UintData):
    """Unsigned 64-bit integer."""

    bytes = 8
    bits = bytes * 8
    max_value = 2**bits - 1


class uint128(_UintData):
    """Unsigned 128-bit integer."""

    bytes = 16
    bits = bytes * 8
    max_value = 2**bits - 1


class uint256(_UintData):
    """Unsigned 256-bit integer."""

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
    new_cls = type(
        cls_name, (_UintData,), {"bits": bits, "bytes": i, "max_value": 2**bits - 1}
    )
    setattr(sys.modules[__name__], cls_name, new_cls)

__all__ = [f"uint{bytes*8}" for bytes in range(1, 32)]
