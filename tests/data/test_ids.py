# mypy: disable-error-code=assignment
import pytest

from evmspec.data._ids import ChainId, IntId, LogIndex, TransactionIndex


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_add(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) + 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_sub(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) - 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_mul(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) * 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_truediv(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) / 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_floordiv(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) // 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_pow(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        cls(1) ** 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_radd(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 + cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rsub(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 - cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rmul(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 * cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rtruediv(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 / cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rfloordiv(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 // cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_rpow(cls: type[IntId]) -> None:
    with pytest.raises(TypeError) as exc_info:
        1 ** cls(1)
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_iadd(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj += 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_isub(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj -= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_imul(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj *= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_itruediv(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj /= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_ifloordiv(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj //= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )


@pytest.mark.parametrize("cls", (ChainId, TransactionIndex, LogIndex))
def test_ipow(cls: type[IntId]) -> None:
    obj = cls(1)
    with pytest.raises(TypeError) as exc_info:
        obj **= 1
    e = exc_info.value
    assert (
        len(e.args) == 1 and e.args[0] == f"You cannot perform math on a {cls.__name__}"
    )
