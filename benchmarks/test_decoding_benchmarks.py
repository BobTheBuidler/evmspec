# mypy: disable-error-code=misc
import pytest
from msgspec.json import Decoder
from pytest_codspeed import BenchmarkFixture

from benchmarks.batch import batch
from benchmarks.data import (
    RAW_EIP1559_TX,
    RAW_LEGACY_TX,
    RAW_LOG,
    RAW_RECEIPT,
    RAW_TX_LIST,
)
from evmspec.data import _decode_hook
from evmspec.structs.log import Log
from evmspec.structs.receipt import TransactionReceipt
from evmspec.structs.transaction import Transaction, Transaction1559, TransactionLegacy

_decode_legacy_tx = Decoder(type=TransactionLegacy, dec_hook=_decode_hook).decode
_decode_1559_tx = Decoder(type=Transaction1559, dec_hook=_decode_hook).decode
_decode_transactions = Decoder(type=tuple[Transaction, ...], dec_hook=_decode_hook).decode
_decode_receipt = Decoder(type=TransactionReceipt, dec_hook=_decode_hook).decode
_decode_log = Decoder(type=Log, dec_hook=_decode_hook).decode


def _decode_1559_access_list(raw: bytes) -> None:
    tx = _decode_1559_tx(raw)
    tx.accessList


def _decode_receipt_logs(raw: bytes) -> None:
    receipt = _decode_receipt(raw)
    receipt.logs


@pytest.mark.benchmark(group="decode_tx_legacy")
def test_decode_tx_legacy(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _decode_legacy_tx, RAW_LEGACY_TX)


@pytest.mark.benchmark(group="decode_tx_1559")
def test_decode_tx_1559(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 100, _decode_1559_tx, RAW_EIP1559_TX)


@pytest.mark.benchmark(group="decode_tx_list")
def test_decode_tx_list(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 50, _decode_transactions, RAW_TX_LIST)


@pytest.mark.benchmark(group="decode_tx_access_list")
def test_decode_tx_access_list(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 50, _decode_1559_access_list, RAW_EIP1559_TX)


@pytest.mark.benchmark(group="decode_log")
def test_decode_log(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 200, _decode_log, RAW_LOG)


@pytest.mark.benchmark(group="decode_receipt_logs")
def test_decode_receipt_logs(benchmark: BenchmarkFixture) -> None:
    benchmark(batch, 50, _decode_receipt_logs, RAW_RECEIPT)
