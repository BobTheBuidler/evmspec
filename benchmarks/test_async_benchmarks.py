# mypy: disable-error-code=misc
import asyncio

import pytest
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import RAW_LOG_LIST
from evmspec.data import TransactionHash
from evmspec.data import _main as data_main
from evmspec.structs.receipt import TransactionReceipt

if not hasattr(TransactionHash, "get_receipt"):
    pytest.skip("a_sync not available", allow_module_level=True)


def _setup_dummies() -> None:
    async def _dummy_get_receipt(*_args, **_kwargs):
        return None

    async def _dummy_get_receipt_raw(*_args, **_kwargs):
        return RAW_LOG_LIST

    data_main._get_transaction_receipt = _dummy_get_receipt
    data_main._get_transaction_receipt_raw = _dummy_get_receipt_raw
    data_main._dank_import_attempted = True
    data_main.__make_decode_logs()


def _run_coro(coro) -> None:
    try:
        asyncio.run(coro)
    except RuntimeError:
        pass


def _get_receipt(tx_hash: TransactionHash) -> None:
    _run_coro(tx_hash.get_receipt(TransactionReceipt))


def _get_logs(tx_hash: TransactionHash) -> None:
    _run_coro(tx_hash.get_logs())


_setup_dummies()
TX_HASH = TransactionHash("0x" + "11" * 32)


@pytest.mark.benchmark(group="txhash_get_receipt")
def test_txhash_get_receipt(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 5, _get_receipt, TX_HASH)


@pytest.mark.benchmark(group="txhash_get_logs")
def test_txhash_get_logs(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 5, _get_logs, TX_HASH)
