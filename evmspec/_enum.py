from enum import EnumMeta
from typing import Union


class StringToIntEnumMeta(EnumMeta):
    """
    A metaclass for Enums that allows conversion from string to integer Enum members.
    """

    def __call__(cls, value: Union[str, int], *args, **kw):
        return super().__call__(cls._member_map_.get(value, value), *args, **kw)  # type: ignore [arg-type]
