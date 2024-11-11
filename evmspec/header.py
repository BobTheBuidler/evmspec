from hexbytes import HexBytes

from dictstruct import LazyDictStruct
from evmspec.data import Address, UnixTimestamp, uint


# WIP - pretty sure this will fail right now
class ErigonBlockHeader(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents a block header in the Erigon client.

    This class is designed to utilize `LazyDictStruct` for handling block header data,
    ensuring immutability and strictness to known fields. It is currently under development,
    and specific features may not yet be functional. There may be known issues needing resolution.

    Attributes:
        timestamp (UnixTimestamp): The Unix timestamp for when the block was collated.
        parentHash (HexBytes): The hash of the parent block.
        uncleHash (HexBytes): The hash of the list of uncle headers.
        coinbase (Address): The address of the miner who mined the block.
        root (HexBytes): The root hash of the state trie.
        difficulty (uint): The difficulty level of the block.
    """

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    parentHash: HexBytes
    """The hash of the parent block."""

    uncleHash: HexBytes
    """The hash of the list of uncle headers."""

    coinbase: Address
    """The address of the miner who mined the block."""

    root: HexBytes
    """The root hash of the state trie."""

    difficulty: uint
    """The difficulty level of the block."""
