from evmspec import block, header, log, trace, transaction
from evmspec.header import ErigonBlockHeader
from evmspec.receipt import FullTransactionReceipt, TransactionReceipt
from evmspec.trace import FilterTrace
from evmspec.transaction import (
    TransactionRLP,
    TransactionLegacy,
    Transaction1559,
    Transaction2930,
    Transaction,
    AnyTransaction,
)

__all__ = [
    # modules
    "block",
    "header",
    "log",
    "receipt",
    "trace",
    "transaction",
    # structs
    # - header
    "ErigonBlockHeader",
    # - receipt
    "FullTransactionReceipt",
    "TransactionReceipt",
    # - trace
    "FilterTrace",
    # - transaction
    "Transaction",
    "AnyTransaction",
    "TransactionRLP",
    "TransactionLegacy",
    "Transaction2930",
    "Transaction1559",
]

"""
This library provides a collection of msgspec.Struct definitions for use with the Ethereum Virtual Machine.

Modules:
    :mod:`~evmspec.block`: Contains structures related to Ethereum blocks.
    :mod:`~evmspec.header`: Contains structures related to Ethereum block headers.
    :mod:`~evmspec.log`: Contains structures related to Ethereum logs.
    :mod:`~evmspec.receipt`: Contains structures related to Ethereum transaction receipts.
    :mod:`~evmspec.trace`: Contains structures related to Ethereum transaction traces.
    :mod:`~evmspec.transaction`: Contains structures related to Ethereum transactions.

Structs:
    :class:`~evmspec.ErigonBlockHeader`: Represents a block header in the Erigon client.
    :class:`~evmspec.FullTransactionReceipt`: Represents a full transaction receipt.
    :class:`~evmspec.TransactionReceipt`: Represents a transaction receipt.
    :class:`~evmspec.FilterTrace`: Represents a union of different trace types.
    :class:`~evmspec.Transaction`: Represents a generic transaction.
    :class:`~evmspec.AnyTransaction`: Represents any type of transaction.
    :class:`~evmspec.TransactionRLP`: Represents an RLP encoded transaction.
    :class:`~evmspec.TransactionLegacy`: Represents a legacy transaction.
    :class:`~evmspec.Transaction2930`: Represents a transaction with EIP-2930.
    :class:`~evmspec.Transaction1559`: Represents a transaction with EIP-1559.
"""