from functools import cached_property
from typing import Any, ClassVar, List, Optional, Tuple, Union

from dictstruct import LazyDictStruct
from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from evmspec.data import (
    Address,
    BlockHash,
    BlockNumber,
    HexBytes32,
    Nonce,
    TransactionHash,
    Wei,
    uint,
)
from evmspec.data._ids import ChainId, TransactionIndex


class AccessListEntry(LazyDictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents an entry in an Ethereum transaction access list.

    Access lists are used in EIP-2930 and EIP-1559 transactions to specify storage slots
    that the transaction plans to access, potentially reducing gas costs.

    Example:
        >>> entry = AccessListEntry(address='0x742d35Cc6634C0532925a3b844Bc454e4438f44e', storageKeys=[...])
        >>> entry.address
        '0x742d35Cc6634C0532925a3b844Bc454e4438f44e'
        >>> len(entry.storageKeys)
        2

    See Also:
        - :class:`Transaction2930`
        - :class:`Transaction1559`
    """

    address: Address
    """The Ethereum address of the contract whose storage is being accessed."""

    _storageKeys: Raw = field(name="storageKeys")
    """The raw encoded storage slot keys within the contract that will be accessed."""

    @cached_property
    def storageKeys(self) -> List[HexBytes32]:
        """
        Decodes storage keys from raw format to a list of HexBytes32.

        The :attr:`_storageKeys` attribute contains the raw encoded data, which is
        decoded into a list of `HexBytes32` objects when accessed through this
        property.

        Example:
            >>> entry = AccessListEntry(address='0x742d35Cc6634C0532925a3b844Bc454e4438f44e', storageKeys=[...])
            >>> decoded_keys = entry.storageKeys
            >>> isinstance(decoded_keys, list)
            True
            >>> isinstance(decoded_keys[0], HexBytes32)
            True

        See Also:
            - :meth:`_TransactionBase.accessList`
        """
        return json.decode(
            self._storageKeys,
            type=List[HexBytes32],
            dec_hook=lambda hexbytes_type, obj: hexbytes_type(obj),
        )


class _TransactionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Base class for Ethereum transactions.
    """

    input: HexBytes
    """The data sent along with the transaction."""

    hash: TransactionHash
    """The hash of the transaction."""

    to: Optional[Address]
    """The address of the receiver. `None` when it's a contract creation transaction."""

    gas: Wei
    """The gas provided by the sender."""

    value: Wei
    """The value transferred in wei encoded as hexadecimal."""

    nonce: Nonce
    """The number of transactions made by the sender before this one."""

    chainId: Optional[ChainId] = UNSET  # type: ignore [assignment]
    """
    The chain id of the transaction, if any.

    `None` for v in {27, 28}, otherwise derived from eip-155.

    This field is not included in the transactions field of a eth_getBlock response.
    """

    # details
    sender: Address = field(name="from")
    """The address of the sender.

    Note:
        This attribute is mapped to the :func:`~msgspec.field` name 'from' during serialization and deserialization.
    """

    blockHash: BlockHash
    """The hash of the block including this transaction."""

    blockNumber: BlockNumber
    """The number of the block including this transaction."""

    transactionIndex: TransactionIndex
    """The index position of the transaction in the block."""

    # signature
    v: uint
    """ECDSA recovery ID."""

    r: HexBytes
    """The R field of the signature."""

    s: HexBytes
    """The S field of the signature."""

    def __hash__(self) -> int:
        return hash(self.hash.hex())

    def __getitem__(self, key: str) -> Any:
        try:
            return getattr(self, key)
        except AttributeError:
            if key == "from":
                return self.sender
            raise KeyError(key) from None

    gasPrice: Wei
    """The gas price provided by the sender in wei."""

    @property
    def block(self) -> BlockNumber:
        """
        A shorthand getter for blockNumber.

        Example:
            >>> transaction = _TransactionBase(...)
            >>> transaction.block == transaction.blockNumber
            True
        """
        return self.blockNumber

    _accessList: Raw = field(name="accessList", default=UNSET)  # type: ignore [assignment]
    """A list of addresses and storage keys that the transaction plans to access."""

    @cached_property
    def accessList(self) -> List[AccessListEntry]:
        """
        Decodes the access list from raw format to a list of AccessListEntry.

        Example:
            >>> transaction = _TransactionBase(...)
            >>> access_list = transaction.accessList
            >>> isinstance(access_list, list)
            True
            >>> isinstance(access_list[0], AccessListEntry)
            True

        See Also:
            - :class:`AccessListEntry`
        """
        return json.decode(self._accessList, type=List[AccessListEntry])


class TransactionRLP(_TransactionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents a RLP encoded transaction that might have network-specific fields.
    """

    # These fields are only present on Optimism, pre-Bedrock.
    l1BlockNumber: BlockNumber = UNSET  # type: ignore [assignment]
    l1TxOrigin: Address = UNSET  # type: ignore [assignment]

    # These fields are only present on Arbitrum
    indexInParent: uint = UNSET  # type: ignore [assignment]
    arbType: uint = UNSET  # type: ignore [assignment]
    arbSubType: uint = UNSET  # type: ignore [assignment]


class TransactionLegacy(_TransactionBase, tag="0x0", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents a Legacy Ethereum transaction (pre-EIP-2718).
    """

    type: ClassVar[HexBytes] = HexBytes("0")


class Transaction2930(_TransactionBase, tag="0x1", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents a type-2930 (EIP-2930) Ethereum transaction with an access list.
    """

    type: ClassVar[HexBytes] = HexBytes("1")


class Transaction1559(_TransactionBase, tag="0x2", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents a type-1559 (EIP-1559) Ethereum transaction with dynamic fee.
    """

    type: ClassVar[HexBytes] = HexBytes("2")

    maxFeePerGas: Wei
    """The maximum fee per gas set in the transaction."""

    maxPriorityFeePerGas: Wei
    """The maximum priority gas fee set in the transaction."""


class Transaction4844(Transaction1559, tag="0x3", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    """
    Represents a type-1559 (EIP-1559) Ethereum transaction with dynamic fee.
    """

    type: ClassVar[HexBytes] = HexBytes("3")

    maxFeePerBlobGas: Wei

    blobVersionedHashes: Tuple[HexBytes32, ...]


Transaction = Union[
    TransactionLegacy, Transaction2930, Transaction1559, Transaction4844
]
AnyTransaction = Union[Transaction, TransactionRLP]
