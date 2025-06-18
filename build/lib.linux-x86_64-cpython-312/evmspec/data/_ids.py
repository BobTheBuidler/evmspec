from evmspec.data._main import uint


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

    def __add__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __sub__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __mul__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __truediv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __floordiv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __pow__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __radd__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __rsub__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __rmul__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __rtruediv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __rfloordiv__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")

    def __rpow__(*_):
        raise TypeError(f"You cannot perform math on a {type(_[0]).__name__}")


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
