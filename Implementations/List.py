# implementing List.py
from typing import TypeVar, Generic

from numpy import unsignedinteger
try: 
  from .functions import visit
except: 
  from functions import visit

Rank = int
T = TypeVar("T")
class ListNode(Generic[T]):
  _data : T
  _pred : 'ListNode[T]'
  _succ : 'ListNode[T]'
   
  def __init__(self, e: 'T' = None, p : 'ListNode[T]' = None, s: 'ListNode[T]' = None) -> None:
    """"""
    self._data = e
    self._pred = p
    self._succ = s

  def insertAsPred(self, e: 'T') -> 'ListNode[T]':
    """ insert node imediately before current node"""
    newNode = ListNode[T](e, self._pred, self)
    self._pred._succ = newNode
    self._pred = newNode
    return newNode
    
  def insertAsSucc(self, e: 'T') -> 'ListNode[T]':
    """ insert node immediately after current node"""
    newNode = ListNode[T](e, self, self._succ)
    self._succ._pred = newNode
    self._succ = newNode

# ListNodePosi = ListNode[T]tre
class List(Generic[T]):
  """ """
  # private
  _size : int = 0
  _header : 'ListNode[T]'
  _trailer : 'ListNode[T]'

  def __init__(self, *args) -> None:
    """"""
    if len(args) == 0: # default
      self._init()
    elif len(args) == 1: # copy whole list L
      """"""
    elif len(args) == 2: # copy n elements starting from rank r
      """"""
    else: # copy n elements starting from rank r of list L
      """"""
  
  # protected
  def _init(self) -> None:
    """"""
    self._header = ListNode[T]()
    self._trailer = ListNode[T]()
    self._header._succ = self._trailer
    self._trailer._pred = self._header
    self._size = 0

  def _clear(self) -> int:
    """ clear all nodes """
    oldSize = self._size
    while 0 < self._size:
      self.remove(self._header._succ)
    return oldSize
    
  def _copyNodes(self, p: 'ListNode[T]', n : 'int') -> None:
    """ copy n items from position p in the list"""
# TODO
  def _merge(self, p: 'ListNode[T]', n : 'int', l : 'List[T]', q : 'ListNode[T]', m :'int') -> 'ListNode[T]':
    """ merge two lists """
# TODO
  def _mergeSort(self, p : 'ListNode[T]', n : 'int') -> None:
    """ merge sort n nodes starting from p """

  def _selectionSort(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    """ selection sort n nodes starting from p"""
    if p is None and n is None: # default sort whole list
      p = self._header._succ
      n = self._size
    head = p._pred
    tail = p
    for i in range(0, n):
      tail = tail._succ # sort from (head, tail)

    while 1 < n: #  in the interval to be sorted before there are at least two nodes left
      # self.traverse()
      # print()
      max = self.selectMax(head._succ, n) # get max
      e = self.remove(max) # remove max from its position
      self.insertPredecessor(e, tail) # move to end of unordered interval
      tail = tail._pred
      n = n - 1

  def _insertionSort(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    """ insertion sort n nodes starting from p"""
    if p is None and n is None: # default sort whole list
      p = self._header._succ
      n = self._size

    for r in range(0, n):
      findSpot = self.search(p._data, r, p)
      self.insertSuccessor(p._data, findSpot)
      p = p._succ
      self.remove(p._pred)
        
  def selectionSortGenerator(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    if p is None and n is None: # default sort whole list
      p = self._header._succ
      n = self._size
    head = p._pred
    tail = p
    for i in range(0, n):
      tail = tail._succ # sort from (head, tail)
    while 1 < n: #  in the interval to be sorted before there are at least two nodes left
      # self.traverse()
      # print()
      max = self.selectMax(head._succ, n) # get max
      e = self.remove(max) # remove max from its position
      self.insertPredecessor(e, tail) # move to end of unordered interval
      tail = tail._pred
      n = n - 1
      
      yield True # return generator

  def insertionSortGenerator(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    if p is None and n is None: # default sort whole list
      p = self._header._succ
      n = self._size

    for r in range(0, n):
      findSpot = self.search(p._data, r, p)
      self.insertSuccessor(p._data, findSpot)
      p = p._succ
      self.remove(p._pred)

      yield True # return generator

# TODO  
  def _radixSort(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    """ radix sort n nodes starting from p"""
    if p is None and n is None: # default 
      p = self._header._succ
      n = self._size

    head = p._pred
    tail = p
  
    for i in range(0, n): # sort from 0 to 
      tail = tail._succ

    radixBit = 0x1
    count = 0
    getIntMax = self.selectMax()._data # find the largest element in advance and estimate the highest valid bit, thus saving useless sorting
    while radixBit < getIntMax and (p := head) : # sort from head for every bit
      for i in range(0, n): # sort all by first radixBit bit
        if (radixBit & p._succ._data):  
          self.insertPredecessor(self.remove(p._succ), tail)  # sort into suffix
        else: 
          p = p._succ # sort into prefix
      radixBit = radixBit << 1 # go to next increasing bit
      count = count + 1

  def radixSortGenerator(self, p : 'ListNode[T]' = None, n : 'int' = None) -> None:
    if p is None and n is None: # default 
      p = self._header._succ
      n = self._size

    head = p._pred
    tail = p
  
    for i in range(0, n): # sort from 0 to 
      tail = tail._succ

    radixBit = 0x1
    count = 0
    getIntMax = self.selectMax()._data 
    while radixBit < getIntMax and (p := head) : 
      for i in range(0, n):
        if (radixBit & p._succ._data):  
          self.insertPredecessor(self.remove(p._succ), tail)  
        else: 
          p = p._succ 
      radixBit = radixBit << 1 
      count = count + 1
      yield True

  # public read interface
  def size(self) -> 'Rank':
    return self._size

  def empty(self) -> bool: 
    return self._size <= 0

  def __getitem__(self, r : 'Rank') -> 'T':
    """ overload to support rank based access (inefficient)"""
    p : 'ListNode[T]' = self.first()
    while ( 0 < r ):
      p = p._succ
      r = r - 1
    return p._data

  def first(self) -> 'ListNode[T]':
    """ return first node """
    return self._header._succ

  def last(self) -> 'ListNode[T]':
    """ return last node """
    return self._trailer._pred

  def valid(self) -> bool: 
    """ determine whether or not position p is valid"""

  def find(self, e : 'T', n : 'int', p : 'ListNode[T]') -> 'ListNode[T]':
    """ unsorted search with range n starting from p """
    while 0 < n:
      p = p._pred
      if (e == p._data):
        return p
      n = n - 1
    return None

  def search(self,  e : 'T', n : 'int', p : 'ListNode[T]') -> 'ListNode[T]':
    """ sorted search with range"""
    p = p._pred # search right to left
    n = n - 1 
    while (-1 < n) and (e < p._data): # break when current is equal to or greater
      p = p._pred # compare from right to left
      n = n - 1
    return p 

  def selectMax(self, p: 'ListNode[T]' = None, n : int = None) -> 'ListNode[T]':
    """ select max of first n elements"""
    if p is None and n is None: # default case
      p = self._header._succ
      n = self._size
      
    max = p
    currentNode = p
    while 1 < n:
      currentNode = currentNode._succ
      if max._data <= currentNode._data :
          max = currentNode
      n = n - 1
    return max

  def selectMin(self, p: 'ListNode[T]' = None, n : int = None) -> 'ListNode[T]':
    """ select min of first n elements"""
    if p is None and n is None: # default case
      p = self._header._succ
      n = self._size
      
    min = p
    currentNode = p
    while 1 < n:
      currentNode = currentNode._succ
      if min._data >= currentNode._data :
          min = currentNode
      n = n - 1
    return min

  # public write interface
  def insertAsFirst(self, e : 'T') -> 'ListNode[T]':
    self._size = self._size + 1
    return self._header.insertAsSucc(e)
    """"""
  
  def insertAsLast(self, e: 'T') -> 'ListNode[T]':
    self._size = self._size + 1
    return self._trailer.insertAsPred(e)
    """"""

  def insertSuccessor(self, e: 'T', p : 'ListNode[T]') -> 'ListNode[T]':
    self._size = self._size + 1
    return p.insertAsSucc(e)
    """"""

  def insertPredecessor(self, e: 'T', p: 'ListNode[T]') -> 'ListNode[T]':
    self._size = self._size + 1
    return p.insertAsPred(e)
    """"""

  def remove(self, p : 'ListNode[T]') -> 'T':
    """ delete legal node at position p, return deleted node """
    e : 'T' = p._data
    p._pred._succ = p._succ
    p._succ._pred = p._pred
    self._size = self._size - 1
    return e

  def sort(self, p: 'ListNode[T]', n : 'int') -> None:
    """ select a random sorting method, and sort first n nodes"""

  def deduplicate(self) -> int:
    """ (unsorted) removal of duplicates"""
    oldSize : 'int' = self._size
    p : 'ListNode[T]' = self.first()
    r : 'Rank' = 0
    while p != self._trailer: 
      q = self.find(p._data, r, p) # find (backward) starting with p
      if q != None: 
        self.remove(q) # if q and p are the same
      else:
        r = r + 1
      p = p._succ
    return oldSize - self._size # return number of deleted elements

  def uniquify(self) -> int:
    """ (sorted) removal of duplicates """
    if self._size < 2:
      return 0

    oldSize : 'int' = self._size
    p : 'ListNode[T]' = self.first()
    q : 'ListNode[T]' = p
    while q != self._trailer:
      q = p._succ
      if ( p._data != q._data ): # if different, move to next pair
        p = q
      else: # if same, delete the successor
        self.remove(q)
    return oldSize - self._size # return number of deleted elements

# TODO
  def reverse(self) -> int:
    """ reverse list """

  # traverse
  def traverse(self) -> None:
   """"""
   p : 'ListNode[T]' = self._header._succ
   while p != self._trailer:
     visit(p._data)
     p = p._succ
   print()

