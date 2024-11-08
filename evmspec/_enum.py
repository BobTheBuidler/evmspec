
from enum import EnumMeta
from typing import Union


class StringToIntEnumMeta(EnumMeta):
    def __call__(cls, value: Union[str, int], *args, **kw):
        return super().__call__(cls._member_map_.get(value, value), *args, **kw)  # type: ignore [arg-type]
