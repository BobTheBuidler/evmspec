# mypy: disable-error-code=misc
import pytest
from hexbytes import HexBytes
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from evmspec.data import uints


def _collect_uint_classes() -> list[type]:
    # Discover all uint<N> classes, including dynamically generated ones.
    classes: list[tuple[int, type]] = []
    for name in dir(uints):
        if not name.startswith("uint"):
            continue
        suffix = name[4:]
        if not suffix.isdigit():
            continue
        cls = getattr(uints, name)
        if isinstance(cls, type):
            classes.append((int(suffix), cls))
    classes.sort(key=lambda item: item[0])
    return [cls for _, cls in classes]


UINT_CLASSES = _collect_uint_classes()
ZERO_VALUE = HexBytes("0x")

UINT_CASES = []
for cls in UINT_CLASSES:
    max_value = HexBytes("0x" + "ff" * cls.bytes)
    UINT_CASES.append((cls, ZERO_VALUE, f"{cls.__name__}-zero"))
    UINT_CASES.append((cls, max_value, f"{cls.__name__}-max"))

UINT_CASE_VALUES = [(cls, value) for cls, value, _ in UINT_CASES]
UINT_CASE_IDS = [case_id for _, _, case_id in UINT_CASES]


@pytest.mark.benchmark(group="uints_construct")
@pytest.mark.parametrize("cls, value", UINT_CASE_VALUES, ids=UINT_CASE_IDS)
def test_uints_construct(benchmark: BenchmarkFixture, cls, value) -> None:
    benchmark(batch, 100_000, cls, value)
