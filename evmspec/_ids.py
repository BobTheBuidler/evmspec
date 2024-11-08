from evmspec.data import uint


class IntId(uint):
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
    ...


class TransactionIndex(IntId):
    ...


class LogIndex(IntId):
    ...
