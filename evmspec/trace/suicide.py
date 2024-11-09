from typing import ClassVar, Literal

from evmspec.trace._base import _ActionBase, _FilterTraceBase


class Action(
    _ActionBase,
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    Represents the action type for contract suicides, capturing the details of the self-destruct operation.
    """


class Trace(
    _FilterTraceBase,
    tag="suicide",
    frozen=True,
    kw_only=True,
    forbid_unknown_fields=True,
    omit_defaults=True,
    repr_omit_defaults=True,
):  # type: ignore [call-arg]
    """
    Represents a trace of a contract self-destruct operation.
    """

    type: ClassVar[Literal["suicide"]] = "suicide"

    action: Action
    """The suicide action, parity style."""

    result: Literal[None]
