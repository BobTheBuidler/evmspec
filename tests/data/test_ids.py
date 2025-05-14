import pytest
from hexbytes import HexBytes

from evmspec.data._ids import ChainId, TransactionIndex, LogIndex


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_add(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) + 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_sub(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) - 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_mul(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) * 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_truediv(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) / 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_floordiv(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) // 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_pow(cls):
    with pytest.raises(TypeError) as exc_info:
        cls(HexBytes(1)) ** 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_radd(cls):
    with pytest.raises(TypeError) as exc_info:
        1 + cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rsub(cls):
    with pytest.raises(TypeError) as exc_info:
        1 - cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rmul(cls):
    with pytest.raises(TypeError) as exc_info:
        1 * cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rtruediv(cls):
    with pytest.raises(TypeError) as exc_info:
        1 / cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rfloordiv(cls):
    with pytest.raises(TypeError) as exc_info:
        1 // cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rpow(cls):
    with pytest.raises(TypeError) as exc_info:
        1 ** cls(HexBytes(1))
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_iadd(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj += 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_isub(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj -= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_imul(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj *= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_itruediv(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj /= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_ifloordiv(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj //= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_ipow(cls):
    obj = cls(HexBytes(1))
    with pytest.raises(TypeError) as exc_info:
        obj **= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )
