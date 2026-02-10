from dictstruct import LazyDictStruct  # type: ignore [import-not-found]
from faster_hexbytes import HexBytes  # type: ignore [import-not-found]

from evmspec.data import Address, BlockHash, BlockNumber, Nonce, UnixTimestamp, Wei, uint


# WIP - this struct is still evolving alongside erigon header changes.
class ErigonBlockHeader(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True):  # type: ignore [call-arg, misc]
    """
    Represents a block header in the Erigon client.

    This class inherits from :class:`LazyDictStruct`, which provides features for handling block header data,
    ensuring immutability and strictness to known fields. It is currently under development,
    and specific features may not yet be functional. There may be known issues needing resolution.

    See Also:
        - :class:`LazyDictStruct` for more details on the underlying structure and its features.
    """

    parentHash: HexBytes
    """The hash of the parent block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     sha3Uncles=HexBytes("0xdef"),
        ...     miner=Address("0x123"),
        ...     stateRoot=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.parentHash
        HexBytes('0xabc')
    """

    sha3Uncles: HexBytes
    """The hash of the list of uncle headers.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     sha3Uncles=HexBytes("0xdef"),
        ...     miner=Address("0x123"),
        ...     stateRoot=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.sha3Uncles
        HexBytes('0xdef')
    """

    miner: Address
    """The address of the miner who mined the block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     sha3Uncles=HexBytes("0xdef"),
        ...     miner=Address("0x123"),
        ...     stateRoot=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.miner
        Address('0x123')
    """

    stateRoot: HexBytes
    """The root hash of the state trie.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     sha3Uncles=HexBytes("0xdef"),
        ...     miner=Address("0x123"),
        ...     stateRoot=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.stateRoot
        HexBytes('0x456')
    """

    difficulty: uint
    """The difficulty level of the block.

    Examples:
        >>> header = ErigonBlockHeader(
        ...     timestamp=UnixTimestamp(1638316800),
        ...     parentHash=HexBytes("0xabc"),
        ...     sha3Uncles=HexBytes("0xdef"),
        ...     miner=Address("0x123"),
        ...     stateRoot=HexBytes("0x456"),
        ...     difficulty=uint(1000)
        ... )
        >>> header.difficulty
        uint(1000)
    """

    # Canonical header fields (kept together below; erigon-specific fields above).
    number: BlockNumber
    """The block number."""

    gasLimit: Wei
    """The maximum gas allowed in the block."""

    gasUsed: Wei
    """The total gas used by all transactions in the block."""

    timestamp: UnixTimestamp
    """The Unix timestamp for when the block was collated."""

    transactionsRoot: HexBytes
    """The root hash of the transactions trie."""

    receiptsRoot: HexBytes
    """The root hash of the receipts trie."""

    logsBloom: HexBytes
    """The bloom filter for the logs of the block."""

    extraData: HexBytes
    """The extra data field of the block."""

    mixHash: HexBytes
    """The mix hash of the block."""

    nonce: Nonce
    """The nonce of the block."""

    baseFeePerGas: Wei | None = None
    """The base fee per gas (post-London)."""

    withdrawalsRoot: HexBytes | None = None
    """The withdrawals root (post-Shanghai)."""

    blobGasUsed: Wei | None = None
    """The blob gas used (post-Cancun)."""

    excessBlobGas: Wei | None = None
    """The excess blob gas (post-Cancun)."""

    parentBeaconBlockRoot: HexBytes | None = None
    """The parent beacon block root (post-Cancun)."""

    requestsHash: HexBytes | None = None
    """The requests hash (post-Cancun)."""

    blockAccessListHash: HexBytes | None = None
    """The block access list hash when present (post-Cancun)."""

    hash: BlockHash
    """The hash of the block."""

    totalDifficulty: uint | None = None
    """The total difficulty up to this block when present."""

    @property
    def uncleHash(self) -> HexBytes:
        return self.sha3Uncles

    @property
    def coinbase(self) -> Address:
        return self.miner

    @property
    def root(self) -> HexBytes:
        return self.stateRoot
