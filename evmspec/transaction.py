from functools import cached_property
from typing import Any, ClassVar, List, Optional, Union

from dictstruct import LazyDictStruct
from hexbytes import HexBytes
from msgspec import UNSET, Raw, field, json

from evmspec._ids import ChainId, TransactionIndex
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


class AccessListEntry(LazyDictStruct, frozen=True, forbid_unknown_fields=True):  # type: ignore [call-arg]
    """
    Represents an entry in an Ethereum transaction access list.

    Access lists are used in EIP-2930 and EIP-1559 transactions to specify storage slots
    that the transaction plans to access, potentially reducing gas costs.

    Example:
        >>> entry = AccessListEntry(...)
        >>> access_list_entry.address
        '0x742d35Cc6634C0532925a3b844Bc454e4438f44e'
        >>> len(access_list_entry.storage_keys)
        2
    """

    address: Address
    """The Ethereum address of the contract whose storage is being accessed."""

    _storageKeys: Raw = field(name="storageKeys")
    """The specific storage slot keys within the contract that will be accessed."""

    @cached_property
    def storageKeys(self) -> List[HexBytes32]:
        """The specific storage slot keys within the contract that will be accessed."""
        return json.decode(
            self._storageKeys,
            type=List[HexBytes32],
            dec_hook=lambda hexbytes_type, obj: hexbytes_type(obj),
        )


class _TransactionBase(LazyDictStruct, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
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
    
    `None` for v in {27, 28}, otherwise derived from eip-155

    This field is not included in the transactions field of a eth_getBlock response.
    """

    # details
    sender: Address = field(name="from")
    """The address of the sender."""

    blockHash: BlockHash
    """The hash of the block including this transaction. `None` when it's pending."""

    blockNumber: BlockNumber
    """The number of the block including this transaction. `None` when it's pending."""

    transactionIndex: TransactionIndex
    """The index position of the transaction in the block. `None` when it's pending."""

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
        """
        return self.blockNumber

    _accessList: Raw = field(name="accessList", default=UNSET)
    """A list of addresses and storage keys that the transaction plans to access."""

    @cached_property
    def accessList(self) -> List[AccessListEntry]:
        """A list of addresses and storage keys that the transaction plans to access."""
        return json.decode(self._accessList, type=List[AccessListEntry])


class TransactionRLP(_TransactionBase, frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]

    # These fields are only present on Optimism, pre-Bedrock.
    l1BlockNumber: BlockNumber = UNSET
    l1TxOrigin: Address = UNSET

    # These fields are only present on Arbitrum
    indexInParent: uint = UNSET
    arbType: uint = UNSET
    arbSubType: uint = UNSET


class TransactionLegacy(_TransactionBase, tag="0x0", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("0")


class Transaction2930(_TransactionBase, tag="0x1", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("1")


class Transaction1559(_TransactionBase, tag="0x2", frozen=True, kw_only=True, forbid_unknown_fields=True, omit_defaults=True, repr_omit_defaults=True):  # type: ignore [call-arg]
    type: ClassVar[HexBytes] = HexBytes("2")

    maxFeePerGas: Wei
    """The maximum fee per gas set in the transaction."""

    maxPriorityFeePerGas: Wei
    """The maximum priority gas fee set in the transaction."""


Transaction = Union[TransactionLegacy, Transaction2930, Transaction1559]
AnyTransaction = Union[Transaction, TransactionRLP]
