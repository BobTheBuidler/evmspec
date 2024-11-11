from typing import List

from dictstruct import DictStruct, LazyDictStruct
from msgspec import UNSET, field

from evmspec.data import Address, BlockHash, BlockNumber, TransactionHash, Wei, uint


class _ActionBase(
    LazyDictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing actions in parity-style Ethereum traces.

    This class provides common attributes for transaction actions such as the
    sender address, the amount of ETH transferred, and the gas provided.
    """

    sender: Address = field(name="from")
    """The sender address. Mapped to the field name 'from'."""

    value: Wei
    """The amount of ETH sent in this action (transaction)."""

    gas: Wei
    """The gas provided."""


class _ResultBase(
    DictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing results in parity-style Ethereum traces.

    This class encapsulates the outcome of transaction actions, specifically
    the amount of gas used by the transaction.
    """

    gasUsed: Wei
    """The amount of gas used by this transaction."""


class _FilterTraceBase(
    LazyDictStruct,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Base class for representing parity-style traces.

    This class contains attributes detailing the block and transaction being traced,
    including block number and hash, transaction hash, position, trace addresses,
    subtraces, and errors if any occurred during execution.
    """

    blockNumber: BlockNumber
    """The number of the block where this action happened."""

    blockHash: BlockHash
    """The hash of the block where this action happened."""

    transactionHash: TransactionHash
    """The hash of the transaction being traced."""

    transactionPosition: int
    """The position of the transaction in the block."""

    traceAddress: List[uint]
    """The trace addresses (array) representing the path of the call within the trace tree."""

    subtraces: uint
    """The number of traces of internal transactions that occurred during this transaction."""

    error: str = UNSET  # type: ignore [assignment]
    """An error message if an error occurred during the execution of the transaction."""

    @property
    def block(self) -> BlockNumber:
        """A shorthand getter for 'blockNumber'."""
        return self.blockNumber
