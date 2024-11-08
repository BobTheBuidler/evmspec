
from dictstruct import LazyDictStruct
from msgspec import field

from evmspec.data import Address, Wei


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