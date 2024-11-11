from enum import EnumMeta
from typing import Union


class StringToIntEnumMeta(EnumMeta):
    """
    A metaclass for Enums that enables conversion from string or integer
    values to Enum members using the member map.

    When a value is given, the process to find the corresponding Enum member
    is as follows:

    - If the value exists in the `_member_map_`, the corresponding Enum
      member is returned.
    - If the value is not found in the `_member_map_`, the original value is
      returned and passed to the base `EnumMeta`'s `__call__` method. This
      method may raise an exception if the value does not correspond to any
      Enum member as per typical Enum behavior.

    Args:
        value: The value to be converted to an Enum member. It can be either
               a string that matches a member's name or an integer that
               matches a member's value.
        *args: Additional arguments.
        **kw: Additional keyword arguments.
    """

    def __call__(cls, value: Union[str, int], *args, **kw):
        """Attempts to convert a given value to an Enum member.

        If the value exists in the `_member_map_`, the corresponding Enum
        member is returned. If not, the original value is passed to the base
        `EnumMeta`'s `__call__` method.

        Args:
            value: The value to be converted to an Enum member.
            *args: Additional arguments.
            **kw: Additional keyword arguments.
        """
        return super().__call__(cls._member_map_.get(value, value), *args, **kw)  # type: ignore [arg-type]
