from enum import EnumMeta
from typing import Union


class StringToIntEnumMeta(EnumMeta):
    """
    A metaclass for Enums that enables conversion from string or integer
    values to Enum members using the member map.

    When a value is given, the process to find the corresponding Enum member
    is as follows:

    - If the value exists in the :attr:`_member_map_`, the corresponding Enum
      member is returned.
    - If the value is not found in the :attr:`_member_map_`, the original value is
      passed to the base :class:`EnumMeta`'s :meth:`__call__` method. This method
      may raise a :class:`ValueError` if the value does not correspond to any
      Enum member, as per typical Enum behavior.

    Args:
        value: The value to be converted to an Enum member. It can be either
               a string that matches a member's name or an integer that
               matches a member's value.
        *args: Additional arguments.
        **kw: Additional keyword arguments.

    Examples:
        Given an Enum `Color` with members `RED = 1` and `GREEN = 2`, you can
        convert from string or integer to Enum member as follows:

        >>> class Color(Enum, metaclass=StringToIntEnumMeta):
        ...     RED = 1
        ...     GREEN = 2

        >>> Color('RED')
        <Color.RED: 1>
        >>> Color(1)
        <Color.RED: 1>
        >>> Color('BLUE')  # This will raise a ValueError
        Traceback (most recent call last):
            ...
        ValueError: 'BLUE' is not a valid Color

    See Also:
        - :class:`EnumMeta`
        - :meth:`EnumMeta.__call__`
    """

    def __call__(cls, value: Union[str, int], *args, **kw):
        """
        Attempts to convert a given value to an Enum member.

        If the value exists in the :attr:`_member_map_`, the corresponding Enum
        member is returned. If not, the original value is passed to the base
        :class:`EnumMeta`'s :meth:`__call__` method, which may raise a
        :class:`ValueError` if the value does not correspond to any Enum member.

        This method uses the :meth:`dict.get` method to attempt to retrieve the
        value from :attr:`_member_map_`, defaulting to the original value if not found.

        Args:
            value: The value to be converted to an Enum member.
            *args: Additional arguments.
            **kw: Additional keyword arguments.

        Examples:
            Using the `Color` Enum from the class docstring:

            >>> Color('GREEN')
            <Color.GREEN: 2>
            >>> Color(2)
            <Color.GREEN: 2>
            >>> Color(3)  # This will raise a ValueError
            Traceback (most recent call last):
                ...
            ValueError: 3 is not a valid Color

        See Also:
            - :class:`EnumMeta`
            - :meth:`EnumMeta.__call__`
        """
        return __em_call__(cls, cls._member_map_.get(value, value), *args, **kw)  # type: ignore [arg-type]


__em_call__ = EnumMeta.__call__
