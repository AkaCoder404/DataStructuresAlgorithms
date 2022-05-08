from List import List
from Vector import Vector
from typing import TypeVar

T = TypeVar("T")
# Stack implemented using List
class StackList(List[T]):
  def __init__(self, *args) -> None:
      super().__init__(*args)
  
  def push(self, e : 'T') -> None:
    super().insertAsLast(e)
  def pop(self) -> 'T':
    return super().remove(super().last())
  def top(self) -> 'T':
    return super().last()._data

class StackVector(Vector[T]):
    def __init__(self, *args) -> None:
        super().__init__(*args)
    def push(self, e: 'T') -> None:
      super().insert(e)
    def pop(self) -> 'T':
      return super().remove(super().size() - 1)
    def top(self) -> 'T':
      return self[super().size() - 1]



