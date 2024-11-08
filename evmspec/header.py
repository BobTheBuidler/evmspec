from hexbytes import HexBytes

from dictstruct import LazyDictStruct
from evmspec.data import Address, UnixTimestamp, uint


# WIP - pretty sure this will fail right now
class ErigonBlockHeader(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    parentHash: HexBytes
    uncleHash: HexBytes
    coinbase: Address
    root: HexBytes
    difficulty: uint
