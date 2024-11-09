from enum import Enum
from functools import cached_property
from typing import ClassVar, Literal

from msgspec import Raw, field, json

from evmspec._enum import StringToIntEnumMeta
from evmspec.data import Address, _decode_hook
from evmspec.trace._base import _ActionBase, _FilterTraceBase


class Type(Enum, metaclass=StringToIntEnumMeta):
    """
    Enum representing the types of rewards in Ethereum: block or uncle.
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
    """
    Action type for rewards.
    """

    author: Address
    """The author of this transaction."""

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
    """
    Represents the trace for a reward.
    """

    type: ClassVar[Literal["reward"]] = "reward"

    _action: Raw = field(name="action")
    """The reward action, parity style."""

    @cached_property
    def action(self) -> Action:
        """The reward action, parity style."""
        return json.decode(self._action, type=Action, dec_hook=_decode_hook)
