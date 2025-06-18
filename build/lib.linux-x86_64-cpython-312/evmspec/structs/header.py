from dictstruct import LazyDictStruct
from hexbytes import HexBytes

from evmspec.data import Address, UnixTimestamp, uint


# WIP - pretty sure this will fail right now
class ErigonBlockHeader(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents a block header in the Erigon client.

    This class inherits from :class:`LazyDictStruct`, which provides features for handling block header data,
    ensuring immutability and strictness to known fields. It is currently under development,
    and specific features may not yet be functional. There may be known issues needing resolution.

    See Also:
        - :class:`LazyDictStruct` for more details on the underlying structure and its features.
    """

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.timestamp
        UnixTimestamp(1638316800)
    """

    parentHash: HexBytes
    """The hash of the parent block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.parentHash
        HexBytes('0xabc')
    """

    uncleHash: HexBytes
    """The hash of the list of uncle headers.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.uncleHash
        HexBytes('0xdef')
    """

    coinbase: Address
    """The address of the miner who mined the block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.coinbase
        Address('0x123')
    """

    root: HexBytes
    """The root hash of the state trie.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.root
        HexBytes('0x456')
    """

    difficulty: uint
    """The difficulty level of the block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     uncleHash=HexBytes("0xdef"),
        ...     coinbase=Address("0x123"),
        ...     root=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.difficulty
        uint(1000)
    """
