# mypy: disable-error-code=misc
import pytest
from msgspec.json import Decoder
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import RAW_BLOCK_WITH_HASHES, RAW_BLOCK_WITH_TXS
from evmspec.data import _decode_hook
from evmspec.structs.block import TinyBlock

_decode_tinyblock = Decoder(type=TinyBlock, dec_hook=_decode_hook).decode


def _decode_block_transactions(raw: bytes) -> None:
    block = _decode_tinyblock(raw)
    block.transactions


@pytest.mark.benchmark(group="tinyblock_transactions")
@pytest.mark.parametrize(
    "raw",
    [RAW_BLOCK_WITH_TXS, RAW_BLOCK_WITH_HASHES],
    ids=["full-transactions", "hashes-only"],
)
def test_tinyblock_transactions(benchmark: BenchmarkFixture, raw: bytes) -> None:
    benchmark(batch, 100, _decode_block_transactions, raw)
