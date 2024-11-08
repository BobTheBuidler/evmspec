from typing import List

from dictstruct import DictStruct, LazyDictStruct
from msgspec import UNSET, field

from evmspec.data import Address, BlockNumber, BlockHash, TransactionHash, Wei, uint


class _ActionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The action performed, parity style.
    """

    sender: Address = field(name="from")
    """The sender address."""

    value: Wei
    """The amount of ETH sent in this action (transaction)."""

    gas: Wei
    """The gas provided."""


class _ResultBase(DictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    The result object, parity style.
    """

    gasUsed: Wei
    """The amount of gas used by this transaction."""


class _FilterTraceBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    blockNumber: BlockNumber
    """The number of the block where this action happened."""

    blockHash: BlockHash
    """The hash of the block where this action happened."""

    transactionHash: TransactionHash
    """The hash of the transaction being traced."""

    transactionPosition: int
    """The position of the transaction in the block."""

    traceAddress: List[uint]
    """The trace addresses (array) where the call executed (every contract where code was executed)."""

    subtraces: uint
    """The number of traces of internal transactions that happened during this transaction."""

    error: str = UNSET

    @property
    def block(self) -> BlockNumber:
        """A shorthand getter for 'blockNumber'."""
        return self.blockNumber
