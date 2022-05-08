from BinaryTree import BinNode, BinTree, T
from typing import TypeVar, Generic
from BinaryTree import hasLeftChild, hasRightChild


class BST(BinTree[T]): 
  """"""
  _hot : 'BinNode[T]' = None

  def __init__(self, *args) -> None:
      super().__init__(*args)
  
  def _connect34(self) -> 'BinNode[T]':
    """according to "3 + 4" structure, connect 3 nodes and 4 subtrees """
  
  def _rotate_at(self, node: 'BinNode[T]') -> 'BinNode[T]':
    """make uniform rotation adjustments for x and his father and grandfather"""

  def search(self, e) -> 'BinNode[T]':
    """ search node with data value of e """
    if (not self._root) or (e == self._root.data): # if empty tree or match root
      self._hot = None
      return self._root
    self._hot = self._root
    while True:
      v = self._hot.left_child if e < self._hot.data else self._hot.right_child # go left if less, go right if more
      if (not v) or (e == v.data): # if hit or reach leaf node
        return v
      self._hot = v
      # print("hot", self._hot.data)
    # no mater if found or not, _hot represents v parent (if v is root, hot is None)
  
  def insert(self, e) -> 'BinNode[T]':
    """ insert node with data value of e"""
    x : 'BinNode[T]' # search for correct location
    isRoot = False
    if (not self._root) or (e == self._root.data): # if empty tree or match root
      self._hot = None
      x = BinNode[T](data=e,parent=self._hot)
      self._root = x
      isRoot = True
    if not isRoot: # if not root or empty, search children 
      self._hot = self._root
      while True:
        v = self._hot.left_child if e < self._hot.data else self._hot.right_child # go left if less, go right if more
        if (not v) or (e == v.data): # if hit or reach leaf node
          x = BinNode[T](data=e,parent=self._hot)
          if e < self._hot.data:
            self._hot.left_child = x
          else:
            self._hot.right_child = x
          break
        self._hot = v

    self._size = self._size + 1
    self.updateHeightAbove(x)
    
    return x
    # no mater if e exists in tree, always returns x.data == e

  # BST node deletion algorithm, delete the node pointed to by position x 
  # (global static template function, suitable for various BST< such as AVL, Splay, RedBlack)
  # The target x has been searched and located before, and thus is confirmed that it is not NULL, 
  # so it must be deleted successfully, different from searchIn, not necessary to empty _hot before calling
  # THe return value points to the successor of the actual deleted node, and hot points to the parent of 
  # the actual deleted node - both may be NULL
  def removeAt(self, x: 'BinNode[T]', hot: 'BinNode[T]') -> 'BinNode[T]':
    w : 'BinNode[T]' = x # the actual node to be removed 
    succ : 'BinNode[T]' =  None # the successor of the actual deleted node
    if not hasLeftChild(x): # if left child is empty
      succ = x = x.right_child # directly replace x with its right subtree
    elif not hasRightChild(x):
      succ = x = x.left_child
    # if bothleft and right subtree exist, select direct successor of x as the actual removed node
    else:
      w = w.succ() # x the direct successor
      x.data, w.data = w.data, x.data # swap the values
      u = w.parent # isolate node w
      if u == x:
        u.right_child = succ = w.right_child
      else:
        u.left_child = succ = w.right_child

    hot = w.parent # record parent of actual deleted node
    if succ: 
      succ.parent = hot
    return succ 
    
  def remove(self, e) -> bool:
    """ remove node with data value of e"""
    # x = self.search(e)
    x : 'BinNode[T]' = None# search for correct location
    isRoot = False
    if (not self._root) or (e == self._root.data): # if empty tree or match root
      self._hot = None
      x = self._root
      isRoot = True
    if not isRoot:
      self._hot = self._root
      while True:
        v = self._hot.left_child if e < self._hot.data else self._hot.right_child # go left if less, go right if more
        if (not v) or (e == v.data): # if hit or reach leaf node
          x = v
          break
        self._hot = v
    if not x: # not found
      return False
    self.removeAt(x, self._hot)
    self._size-=1
    self.updateHeightAbove(self._hot) # 
    return True

