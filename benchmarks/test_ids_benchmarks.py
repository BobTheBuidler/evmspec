# mypy: disable-error-code=misc
import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data._ids import ChainId, LogIndex, TransactionIndex


def _exercise_intid_ops(cls) -> None:
    obj = cls(1)
    ops = [
        lambda: obj + 1,
        lambda: obj - 1,
        lambda: obj * 1,
        lambda: obj / 1,
        lambda: obj // 1,
        lambda: obj**1,
        lambda: 1 + obj,
        lambda: 1 - obj,
        lambda: 1 * obj,
        lambda: 1 / obj,
        lambda: 1 // obj,
        lambda: 1**obj,
        lambda: _iadd(obj),
        lambda: _isub(obj),
        lambda: _imul(obj),
        lambda: _itruediv(obj),
        lambda: _ifloordiv(obj),
        lambda: _ipow(obj),
    ]
    for op in ops:
        try:
            op()
        except TypeError:
            pass


def _iadd(obj):
    obj += 1


def _isub(obj):
    obj -= 1


def _imul(obj):
    obj *= 1


def _itruediv(obj):
    obj /= 1


def _ifloordiv(obj):
    obj //= 1


def _ipow(obj):
    obj **= 1


@pytest.mark.benchmark(group="intid_ops")
@pytest.mark.parametrize("cls", [ChainId, TransactionIndex, LogIndex], ids=["chain", "tx", "log"])
def test_intid_ops(benchmark: BenchmarkFixture, cls) -> None:
    benchmark(batch, 5, _exercise_intid_ops, cls)
