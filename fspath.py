import abc
import typing as t


class PathLike(abc.ABC):

    """Abstract base class for implementing the file system path protocol."""

    @abc.abstractmethod
    def __fspath__(self) -> t.Union[str, bytes]:
        """Return the file system path representation of the object."""
        raise NotImplementedError


def fspath(path: t.Union[PathLike, str]) -> str:
    """Return the string representation of the path.

    If a string is passed in then it is returned unchanged.
    """
    if hasattr(path, '__fspath__'):
        path = path.__fspath__()
    if not isinstance(path, str):
        type_name = type(path).__name__
        raise TypeError("expected a str or path-like object, not " + type_name)
    return path