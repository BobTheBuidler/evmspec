from evmspec import structs
from evmspec.structs import (
    ErigonBlockHeader,
    FilterTrace,
    FullTransactionReceipt,
    Log,
    TransactionReceipt,
    block,
    header,
    trace,
    transaction,
)
from evmspec.structs.transaction import (
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
    "receipt",
    "trace",
    "transaction",
    # structs
    "structs",
    # - header
    "ErigonBlockHeader",
    # - log
    "Log",
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
    :mod:`~evmspec.structs.block`: Contains structures related to Ethereum blocks.
    :mod:`~evmspec.structs.header`: Contains structures related to Ethereum block headers.
    :mod:`~evmspec.structs.log`: Contains structures related to Ethereum logs.
    :mod:`~evmspec.structs.receipt`: Contains structures related to Ethereum transaction receipts.
    :mod:`~evmspec.structs.trace`: Contains structures related to Ethereum transaction traces.
    :mod:`~evmspec.structs.transaction`: Contains structures related to Ethereum transactions.

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
