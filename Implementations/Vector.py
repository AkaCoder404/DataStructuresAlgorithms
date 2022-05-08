# implementing Vector.py
from typing import TypeVar, Generic
try: 
  from .functions import visit
except: 
  from functions import visit


Rank = int # 
T = TypeVar("T") # equivalent to c++ template

class Vector(Generic[T]):
  DEFAULT_CAPACITY = 3
  _size : 'Rank' = 0
  _capacity : 'Rank' = 0
  _elem : 'list[T]' = [] # lists are actually arrays https://stackoverflow.com/questions/12274060/does-python-use-linked-lists-for-lists-why-is-inserting-slow#:~:text=As%20Greg%20Hewgill%20has%20already,characteristics%20of%20a%20linked%20list.

  def __init__(self, *args) -> None:
    # (capacity, size, element)
    if isinstance(args[0], int) and len(args) == 3:
      self._elem = [0] * args[0]
      self._size = args[1]
      for element in range(0, self._size):
        self._elem[element] = args[2]   
    # TODO
    # other types of constructors 
    # 1. copy entire array
    # 2. copy range of array
    # 3. copy entire vector
    # 4. copy range of vector

  # protected
  def _copyFrom(self, A : 'list[T]', lo : 'Rank', hi : 'Rank'): 
    """ copy array """

  def _expand(self) -> None: 
    """ expand array """
    if self._size < self._capacity: # no need to return 
      return 
    if self._capacity < self.DEFAULT_CAPACITY :  # set default capacity
      self._capacity = self.DEFAULT_CAPACITY
    oldElements = self._elem # store old elements
    self._capacity = (self._capacity << 1) # expand 2x
    self._elem = [0] * (self._capacity) 
    for i in range(0, self._size):  # copy elements over 
      self._elem[i] = oldElements[i]

  def _shrink(self) -> None:
    """ shrink array when amount of elements is way less than capcacity """
    if self._capacity < ( self.DEFAULT_CAPACITY << 1 ):
      return
    if (self._size << 2) > self._capacity: # greater than 25 percent
      return  
    oldElements = self._elem
    self._capacity = (self._capacity >> 1) # expand 2x
    self._elem = [0] * (self._capacity) 
    for i in range(0, self._size):  # copy elements over 
      self._elem[i] = oldElements[i]

  def _maxItem(self, lo: 'Rank' = None, hi: 'Rank' = None) -> Rank:
    """ return maximum item """
    if lo is None and hi is None:
      lo = 0
      hi = self.size()
    max : 'Rank' = hi
    while (lo < hi): # search backwards
      hi = hi - 1
      if self._elem[max] < self._elem[hi] :
        max = hi
      
    return max # return location of max element

  def _minItem(self, lo: 'Rank' = None, hi: 'Rank' = None) -> Rank:
    if lo is None and hi is None:
      lo = 0
      hi = self.size()
    """ return minimum item """
    min : 'Rank' = hi
    while (lo < hi): # search backwards
      hi = hi - 1
      if self._elem[min] > self._elem[hi] :
        min = hi
      
    return min # return location of min element

  def _bubble(self, lo: 'Rank' = 0, hi: 'Rank' = _size) -> bool: 
    """ scan swap"""

  def _bubbleSort(self, lo: 'Rank' = None, hi: 'Rank' = None) -> None:
    """ bubble sort """
    if lo is None and hi is None: # default
      lo = 0
      hi = self._size
    hi = hi - 1
    while lo < hi: # repeated bubble
      for i in range(lo, hi): # 
        if self._elem[i] > self._elem[i + 1]: # if wrong order
          self._elem[i], self._elem[i+1] = self._elem[i+1], self._elem[i]
      hi = hi - 1

  def _selectionSort(self, lo: 'Rank' = None, hi: 'Rank' = None) -> None:
    if lo is None and hi is None: # default
      lo = 0
      hi = self._size
    hi = hi - 1 # 
    while lo < hi:
      # swap [hi] with the biggest value between [lo, hi]
      maxItem = self._maxItem(lo, hi)
      self._elem[maxItem], self._elem[hi] = self._elem[hi], self._elem[maxItem]
      hi = hi - 1

# TODO
  def _merge(self, lo, mi, hi) -> None:
    """ merge algorithm """

  def _mergeSort(self, lo: 'Rank', hi: 'Rank') -> None:
    """ merge sort algorithm """

  def _heapSort(self, lo: 'Rank' = 0, hi: 'Rank' = _size) -> None:
    """ heap sort algorithm """

  def _partition(self, lo: 'Rank' = 0, hi: 'Rank' = _size) -> Rank:
    """ create partitions for quicksort """

  def _quickSort(self, lo: 'Rank' = 0, hi: 'Rank' = _size) -> None:
    """ quicksort algorithm """

  def _shellSort(self, lo: 'Rank' = 0, hi: 'Rank' = _size) -> None:
    """ shell sort algorithm """

  # Generators 
  def bubbleSortGenerator(self, lo: 'Rank' = None, hi: 'Rank' = None) -> None:
    if lo is None and hi is None: # default
      lo = 0
      hi = self._size
    hi = hi - 1
    while lo < hi: # repeated bubble
      for i in range(lo, hi): # 
        if self._elem[i] > self._elem[i + 1]: # if wrong order
          self._elem[i], self._elem[i+1] = self._elem[i+1], self._elem[i]
      hi = hi - 1
      yield True
  def selectionSortGenerator(self, lo: 'Rank' = None, hi: 'Rank' = None) -> None:
    if lo is None and hi is None: # default
      lo = 0
      hi = self._size
    hi = hi - 1 # 
    while lo < hi:
      maxItem = self._maxItem(lo, hi)
      self._elem[maxItem], self._elem[hi] = self._elem[hi], self._elem[maxItem]
      hi = hi - 1
      yield True
    
  def mergeSortGenerator(self) -> None:
    pass
  def heapSortGenerator(self) -> None:
    pass
  def quickSortGenerator(self) -> None:
    pass
  def shellSortGenerator(self) -> None:
    pass


  # public read interface
  def size(self) -> int:
    return self._size
  
  def empty(self) -> bool:
    return not self._size

  def find(self, e : 'T', lo: 'Rank', hi: 'Rank') -> Rank:
    """ search through unsorted vector """
    while lo < hi and e != self._elem[hi]: # search hi to low
      hi = hi - 1 
    return hi # if hi < lo, still haven't found, otherwise hi is the element found
  
  # TODO
  def search(self, e : 'T', lo : 'Rank', hi: 'Rank') -> Rank:
    """ search through sorted vector """
    # randomly select binary or fib search
    
  # public write interface
  # T& operator[] (Rank r);
  def __getitem__(self, r : 'Rank') -> 'T':
    """ overload the subscript operator to refer to each element as if it were array"""
    return self._elem[r]

  # const T& operator[] (Rank r) const 
  # only overload versions that do rvalues

  # Vector<T> & operator = (Vector<T> const&)
  # overload the assignment operator in order to clone the vector directly

  def remove(self, r : 'Rank') -> 'T':
    """ delete element with rank r """
    e = self._elem[r] 
    self.removeInterval(r, r + 1)
    return e # return removed node

  def removeInterval (self, lo: 'Rank', hi: 'Rank') -> 'Rank':
    """ delete elements in range [lo, hi)"""
    if lo == hi: 
      return 0
    while hi < self._size: # between [hi, _size]
      self._elem[lo] = self._elem[hi] # move hi - l elements after hi forward
      lo = lo + 1
      hi = hi + 1
    self._size = lo # ignore everthing from [lo, _size = hi]
    self._shrink() # shrink if needed
    return hi - lo # return number of removed nodes

  def insert(self, e : 'T', r : 'Rank' = None) -> 'Rank': 
    """ insert element at rank r """
    if r is None:
      r = self.size()

    self._expand() # expand if needed
    i = self._size
    while r < i:  # from end to front
      self._elem[i] =  self._elem[i - 1] # move units back one
      i = i - 1
    self._elem[r] = e # set new value
    self._size = self._size + 1 # increase size
    return r
    
# TODO
  def sort(self, lo : 'Rank' = 0, hi : 'Rank' = _size) -> None:
    """ sort from low to high"""
    # select random sort between bubble, selection, merge, heap, quick, and shell

  def unsort(self, lo : 'Rank' = 0, hi: 'Rank' = _size) -> None:
    """ unsort vector in [low, high) range """
    V = self._elem[lo:] # subvector _elem[lo, hi) is treated as another vector V[0, hi - lo)
    # in python however, can't create sublist without copying https://stackoverflow.com/questions/28354960/python-create-sublist-without-copying
    i = hi - lo
    while i > 0:
      rand = random.randint(0, i)
      V[i - 1], V[rand] = V[rand], V[i - 1] # swap V[i - 1] with a value between V[0, i)
      i = i - 1

    # copy unsorted to self._elem
    for e in range(lo, hi):
      self._elem[e] = V[e - lo]

  def deduplicate(self) -> Rank:
    """ removed duplicates from unsorted """
    oldSize = self._size
    i = 1
    while i < self._size: # search from begging 
      if self.find(self._elem[i], 0, i < 0) < 0:  # find similarity inbetween [0, i]
        i = i + 1 # not found
      else: 
        self.remove(i) # delete 
    return oldSize - self._size

  def uniquify(self) -> Rank:
    """ remove duplciates from sorted """
    i = 0 #  rank of each pair of distinct "adjacent" elements
    j = 1 
    while j < self._size: 
      if self._elem[i] != self._elem[j]: # skip identical
        i = i + 1
        self._elem[i] = self._elem[j]
      j = j + 1
    i = i + 1
    self._shrink() # shrink if deleted enough elements
    self._size = i
    return j - i # return total amount of deleted elements

  # traverse
  def traverse(self):
    """"""
    for i in range(0, self._size):
      visit(self._elem[i])
    print()
  # template <typename VST> void traverse ( VST& ); //遍历（使用函数对象，可全局性修改）