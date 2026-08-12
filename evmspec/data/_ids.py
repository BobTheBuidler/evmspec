from typing import NoReturn

from evmspec.data._main import uint


def _fail_at_math(*_) -> NoReturn:
    raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")


class IntId(uint):
    """A base class for identifiers that do not support arithmetic operations.

    This class raises a :class:`TypeError` when attempts are made to perform any
    of the following arithmetic operations on its instances: addition,
    subtraction, multiplication, true division, floor division, and exponentiation.
    It also raises a :class:`TypeError` for reverse arithmetic operations.

    Examples:
        >>> id1 = IntId(1)
        >>> id2 = IntId(2)

        >>> id1 + id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> id1 - id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> id1 * id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> id1 / id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> id1 // id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> id1 ** id2
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 + id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 - id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 * id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 / id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 // id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

        >>> 1 ** id1
        Traceback (most recent call last):
            ...
        TypeError: You cannot perform math on a IntId

    See Also:
        - :class:`ChainId`
        - :class:`TransactionIndex`
        - :class:`LogIndex`
    """

    __add__ = _fail_at_math
    __sub__ = _fail_at_math
    __mul__ = _fail_at_math
    __truediv__ = _fail_at_math
    __floordiv__ = _fail_at_math
    __pow__ = _fail_at_math
    __radd__ = _fail_at_math
    __rsub__ = _fail_at_math
    __rmul__ = _fail_at_math
    __rtruediv__ = _fail_at_math
    __rfloordiv__ = _fail_at_math
    __rpow__ = _fail_at_math


class ChainId(IntId):
    """Represents a unique identifier for an Ethereum chain.

    It is used to distinguish between different blockchain networks.
    This class does not support any arithmetic operations.

    See Also:
        - :class:`IntId`
    """


class TransactionIndex(IntId):
    """Represents the index of a transaction within a block.

    It is used to identify the transaction's position in the block.
    This class does not support any arithmetic operations.

    See Also:
        - :class:`IntId`
    """


class LogIndex(IntId):
    """Represents the index of a log entry within a transaction.

    It is used to identify the log's position within the transaction.
    This class does not support any arithmetic operations.

    See Also:
        - :class:`IntId`
    """
