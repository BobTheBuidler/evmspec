from typing import ClassVar, Literal

from evmspec.trace._base import _ActionBase, _FilterTraceBase


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):
    """
    Action type for contract suicides.
    """


class Trace(
    _FilterTraceBase,
    tag="suicide",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):

    type: ClassVar[Literal["suicide"]] = "suicide"

    action: Action
    """The suicide action, parity style."""

    result: Literal[None]
