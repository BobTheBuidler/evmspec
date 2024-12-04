from enum import Enum
from functools import cached_property
from typing import ClassVar, Literal

from msgspec import Raw, field, json

from evmspec.data import Address, _decode_hook
from evmspec.data._enum import StringToIntEnumMeta
from evmspec.structs.trace._base import _ActionBase, _FilterTraceBase


class Type(Enum, metaclass=StringToIntEnumMeta):
    """Represents the types of rewards in Ethereum: block or uncle.

    This enum is used to specify the type of reward in Ethereum traces.

    Attributes:
        block (int): Represents a block reward.
        uncle (int): Represents an uncle reward.

    Example:
        >>> reward_type = Type.block
        >>> print(reward_type)
        Type.block
    """

    block = 0
    uncle = 1


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Action type for rewards.

    This class extends :class:`_ActionBase` to include specific attributes
    for reward actions in Ethereum traces.

    Attributes:
        author (Address): The author of this reward.
        rewardType (Type): The type of the reward.

    Example:
        >>> action = Action(author=Address("0x123"), rewardType=Type.block)
        >>> print(action.author)
        0x123
    """

    author: Address
    """The author of this reward."""

    rewardType: Type
    """The type of the reward."""


class Trace(
    _FilterTraceBase,
    tag="reward",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """Represents the trace for a reward in Ethereum.

    This class extends :class:`_FilterTraceBase` and is specifically tagged
    as a "reward" trace. It includes raw data for the reward action that
    requires decoding.

    Attributes:
        type (ClassVar[Literal["reward"]]): A class variable indicating the trace type.
        _action (Raw): Raw data of the reward action, requires decoding to be useful.

    Example:
        >>> trace = Trace(blockNumber=123, blockHash=BlockHash("0xabc"), transactionHash=TransactionHash("0xdef"), transactionPosition=0, traceAddress=[], subtraces=0, _action=Raw(b'...'))
        >>> decoded_action = trace.action
        >>> print(decoded_action.rewardType)
        Type.block

    See Also:
        - :class:`Action`: The decoded action object.
        - :class:`_FilterTraceBase`: The base class for trace representations.
    """

    type: ClassVar[Literal["reward"]] = "reward"
    """A class-level constant identifying the trace type as a reward trace.

    This attribute is used to distinguish this trace from other types of traces
    within the Ethereum Virtual Machine (EVM).

    Examples:
        >>> Trace.type
        'reward'
    """

    _action: Raw = field(name="action")
    """Raw data of the reward action, requires decoding to be useful."""

    @cached_property
    def action(self) -> Action:
        """Decodes the raw reward action into an :class:`Action` object, using parity style.

        This method uses the :func:`msgspec.json.decode` function with a
        decoding hook to convert the raw action data into a structured
        :class:`Action` object.

        Returns:
            The decoded action.

        Example:
            >>> trace = Trace(blockNumber=123, blockHash=BlockHash("0xabc"), transactionHash=TransactionHash("0xdef"), transactionPosition=0, traceAddress=[], subtraces=0, _action=Raw(b'...'))
            >>> action = trace.action
            >>> print(action.author)
            0x123
        """
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)
