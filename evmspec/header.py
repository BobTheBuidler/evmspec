from hexbytes import HexBytes

from dictstruct import LazyDictStruct
from evmspec.data import Address, UnixTimestamp, uint


# WIP - pretty sure this will fail right now
class ErigonBlockHeader(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents a block header in the Erigon client.
    """

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    parentHash: HexBytes
    """The hash of the parent block."""

    uncleHash: HexBytes
    """The hash of the uncle block."""

    coinbase: Address
    """The address of the miner who mined the block."""

    root: HexBytes
    """The root hash of the block."""

    difficulty: uint
    """The difficulty level of the block."""
