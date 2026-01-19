# mypy: disable-error-code=misc
from decimal import Decimal

import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import ADDRESS_CHECKSUM, HASH_1
from evmspec.data import Address, BlockNumber, HexBytes32, _decode_hook
from evmspec.data._main import _decode_hook_unsafe

DECODE_HOOK_CASES = [
    (_decode_hook, Address, ADDRESS_CHECKSUM, "safe-address"),
    (_decode_hook, BlockNumber, "0x2a", "safe-uint"),
    (_decode_hook, HexBytes32, HASH_1, "safe-hexbytes"),
    (_decode_hook, Decimal, "1.23", "safe-decimal"),
    (_decode_hook_unsafe, Address, ADDRESS_CHECKSUM, "unsafe-address"),
    (_decode_hook_unsafe, BlockNumber, "0x2a", "unsafe-uint"),
    (_decode_hook_unsafe, HexBytes32, HASH_1, "unsafe-hexbytes"),
    (_decode_hook_unsafe, Decimal, "1.23", "unsafe-decimal"),
]
DECODE_HOOK_VALUES = [(hook, typ, value) for hook, typ, value, _ in DECODE_HOOK_CASES]
DECODE_HOOK_IDS = [case_id for _, _, _, case_id in DECODE_HOOK_CASES]


@pytest.mark.benchmark(group="decode_hook")
@pytest.mark.parametrize("hook, typ, value", DECODE_HOOK_VALUES, ids=DECODE_HOOK_IDS)
def test_decode_hook(benchmark: BenchmarkFixture, hook, typ, value) -> None:
    benchmark(batch, 20_000, hook, typ, value)
