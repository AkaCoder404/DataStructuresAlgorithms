from List import List, T

# list implementation of queue
class Queue(List[T]):
  def __init__(self, *args) -> None:
      super().__init__(*args)
  def enqueue(self, e : T) -> None:
    super().insertAsLast(e)
  def dequeue(self) -> T:
    return super().remove(super().first())
  def front(self) -> T:
    return super().first()._data