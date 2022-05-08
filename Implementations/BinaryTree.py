# implementing a binary search tree in python
from typing import TypeVar, Generic
from enum import Enum
try: # when working from different filepaths 
  from .functions import visit
except: 
  from functions import visit

from Queue import Queue
from Stack import StackList, StackVector

# bin node status and type macros
def isRoot(x: 'BinNode'):
  return not x.parent
def isLeftChild(x: 'BinNode'):
  return (not isRoot(x)) and (x == x.parent.left_child) 
def isRightChild(x: 'BinNode'):
  return (not isRoot(x)) and (x == x.parent.right_child) 
def hasParent(x: 'BinNode'):
  return not isRoot(x)
def hasLeftChild(x: 'BinNode'):
  return x.left_child
def hasRightChild(x: 'BinNode'):
  return x.right_child
def hasChild(x: 'BinNode'):
  return hasLeftChild(x) or hasRightChild(x)
def hasBothChild(x: 'BinNode'):
  return hasLeftChild(x) and hasRightChild(x)
def isLeaf(x: 'BinNode'):
  return not hasChild(x)
def sibilings(p : 'BinNode'):
  if isLeftChild(p):
    return p.parent.right_child
  return p.parent.left_child
def uncle(x: 'BinNode'):
  return sibilings(x.parent)
def FromParentTo(x: 'BinNode'):
  if isRoot(x):
    return "root"
  else:
    if isLeftChild(x):
      return x.parent.left_child
    else:
      return x.parent.right_child

# 
def stature(p : 'BinNode', isRedBlackTree=False):
  # The black height of the red-black tree node (NULL is regarded as an external node, corresponding to 0)
  # Height of nodes in the rest of the BST (NUll is treated as an empty tree, corresponding to -1)
  val = 0 if isRedBlackTree else -1
  return p.height if p else val

# avl macros
def balanced(x: 'BinNode'):
  return stature(x.left_child) == stature(x.right_child)
def balFac(x: 'BinNode'): # balanced factor
  return stature(x.left_child) - stature(x.right_child)
def avlBalanced(x: 'BinNode'): # conditions for balanced
  return (( -2 < balFac(x)) and (balFac(x) < 2))

# red black macros
def isBlack(p : 'BinNode'):
  return (not p) or (RBColor.RB_BLACK == p.color) # external nodes are also black
def isRed(p : 'BinNode'):
  return not isBlack(p) # if not black, then red
def blackHeightUpdated(x : 'BinNode'): # rb tree height new condition
  return (stature(x.left_child, isRedBlackTree=True) == stature(x.right_child, isRedBlackTree=True)) and \
    x.height == (stature(x.left_child, isRedBlackTree=True) if isRed(x) else stature(x.left_child) + 1)
 
# vst = virtual suffix tree
# Generics
T = TypeVar("T") # equivalent to c++ template T

class RBColor(Enum):
  RB_RED = 1
  RB_BLACK = 2

class BinNode(Generic[T]): 
  """ binary tree node """
  data : 'T' = None 
  left_child: 'BinNode'  = None
  right_child: 'BinNode' = None
  parent: 'BinNode' = None
  height: int = 0
  null_path_length: int = 0
  color : 'RBColor'= None # red or black for rb trees

  def __init__(self, parent = None, left_child = None, right_child = None, data = None, height = 0, npl = 0, color = None ):
    self.data = data
    self.parent = parent
    self.left_child = left_child
    self.right_child = right_child
    self.height = height
    self.null_path_length = npl
    self.color = color
  
  def size(self) -> int:
    s = 1 # count itself
    if self.left_child:
      s += self.left_child.size()
    if self.right_child:
      s += self.right_child.size()
    return s

  def insert_as_left_child(self, data) -> 'BinNode':
    self.left_child = BinNode(data=data)
    return self.left_child
  
  def insert_as_right_child(self, data) -> 'BinNode':
    self.right_child = BinNode(data=data)
    return self.right_child

  def succ(self) -> 'BinNode':
    """ find direct successor to node """
    s = self # records subsequent temporary variables
    if self.right_child: # if there is a right child, then the direct successor must be in right subtree
      s = self.right_child  # right subtree
      while s.left_child:  # leftmost leaf of right subtree (smallest value)
        s = s.left_child
    else:  # else, the immediate direct successor is the "lowest ancestor that contains the current node to its left"
      while isRightChild(s): 
        s = s.parent # reverse right branch, keep moving toward upper left
      s = s.parent # finally, move one more step towards upper right, i.e, arrive at the direct successor (if there is one)
    return s # if it is biggest value (furthest right), it will return root node
         
  def travel_level(self): 
    """ travel level using implemented queue """
    q = Queue[BinNode[T]]()
    q.enqueue(self) # root
    while not q.empty():
      x = q.dequeue()
      visit(x.data)
      if hasLeftChild(x):
        q.enqueue(x.left_child)
      if hasRightChild(x):
        q.enqueue(x.right_child)

  def travel_preorder(self):
    """ """
    # version 1: iterative 
    s = StackList[BinNode[int]]()
    if self:
      s.push(self) # root node
    while not s.empty():
      x = s.pop()
      visit(x.data)
      if hasRightChild(x):
        s.push(x.right_child)
      if hasLeftChild(x):
        s.push(x.left_child)
    
  def travel_inorder(self, node: 'BinNode'): 
    """ recursive method for traveling inorder """
    # recursive method
    if node is None: 
      return
    self.travel_inorder(node.left_child)
    visit(node.data)
    self.travel_inorder(node.right_child)
    # iteratve method 1
    # iterative method 2
    # iterative method 3
    # iterative method 4
  

  def travel_postorder(self, node: 'BinNode'):
    """ recursive method for traveling post order"""
    if node is None:
      return
    self.travel_postorder(node.left_child)
    self.travel_postorder(node.right_child)
    visit(node.data)
    # iterative method 1

  # overload operators
  def __lt__(self, node: 'BinNode'):
    if isinstance(node, BinNode): # avoid == None
      return self.data < node.data 
  
  def __eq__(self, node: 'BinNode'):
     if isinstance(node, BinNode): # avoid == None
      return self.data == node.data 

BinNodePosi = BinNode[T] # for better understanding as the position of the bin node
class BinTree(Generic[T]):
  """"""
  _size: int
  _root: 'BinNode[T]' 

  def __init__(self) -> None:
    self._size = 0
    self._root = None

  def updateHeight(self, x : 'BinNode[T]') -> int:
    x.height = 1 + max(stature(x.left_child), stature(x.right_child)) # specific rules vary from tree to tree
    return x.height
    
  def updateHeightAbove(self, x : 'BinNode[T]') -> None:
    while x:
      self.updateHeight(x)
      x = x.parent # cover successive generations of ancestors from x

  def size(self) -> int:
    return self._size 

  def empty(self) -> bool:
    return not self._root

  def insert(self, e : 'T', left_child: 'BinNode[T]' = None, right_child: 'BinNode[T]' = None) -> 'BinNode[T]': 
    """ insert node, insert left child, insert right child """
    if left_child is None and right_child is None: # insert root node
      self._size = 1
      self._root = BinNode[T](data=e)
      return self._root

    elif right_child is None: # right child is None, set left child
      self._size += 1
      left_child.insert_as_left_child(e)
      self.updateHeightAbove(left_child)
      return left_child.left_child

    else: 
      self._size += 1 
      right_child.insert_as_right_child(e)
      self.updateHeightAbove(right_child)
      return right_child.right_child

  def attach(self, s: 'BinTree[T]' = None,  left_subtree : 'BinNode[T]' =  None, right_subtree : 'BinNode[T]' = None) -> 'BinNode[T]': 
    """ attach left subtree, attach right child """
    # add S to the binary tree as the left subtree of node x, S itself is empty
    if right_subtree is None: # insert as left subtree
      left_subtree.left_child = s._root
      if left_subtree.left_child: # attach
        left_subtree.left_child.parent = left_subtree 
        self._size += s._size # update size and height of left_subtree
        self.updateHeightAbove(left_subtree)
        s = None
        return left_subtree # return attached position      
    # add S to the binary tree as the right subtree of node x, S itself is empty
    else: # insert as right subtree
      right_subtree.right_child = s._root
      if right_subtree.right_child:
        left_subtree.right_child.parent = left_subtree # attach
        self._size += s._size # update size and height of left_subtree
        self.updateHeightAbove(right_subtree)
        s = None

  def remove(self, x : 'BinNode[T]') -> int:
    """ remove subtree """
    # delete the node and its descendants at position x in the binary tree, and return value of deleted node
    if isRoot(x):
      self._root = None
    else:
      if isLeftChild(x):
        x.parent.left_child = None
      else:
        x.parent.right_child = None
    self.updateHeightAbove(x.parent)
    n = self.removeAt(x)
    self._size -= n
    return n

  def removeAt(self, x : 'BinNode[T]') -> int:
    if not x:  
      return 0 # return if empty tree
    n = 1 + self.removeAt(x.left_child) + self.removeAt(x.right_child)
    return n

  def secede(self, x : 'BinNode[T]') -> 'BinNode[T]':
    """ detach subtree and return seceding subtree """
    # cut off pointer from parent node
    if isRoot(x):
      self._root = None
    else:
      if isLeftChild(x):
        x.parent.left_child = None
      else:
        x.parent.right_child = None
    self.updateHeightAbove(x) # update the heights of all ancestors of the original tree
    s = BinTree[T]() # new tree with root x
    s._root = x 
    x.parent = None 
    s._size = x.size() 
    self._size -= s._size 
    return s

  def travel_level(self) -> None:
    if self._root:
      self._root.travel_level()
  def travel_preorder(self) -> None:
    if self._root:
      self._root.travel_preorder()
  def travel_inorder(self) -> None:
    if self._root:
      self._root.travel_inorder(node=self._root)
  def travel_postorder(self) -> None:
    if self._root:
      self._root.travel_postorder(node=self._root)

  def zig(): 
    pass
  def zag():
    pass

  def stretch_by_zag(self, x: 'BinNode[T]') -> None:
    pass
  def stretch_by_zig(self, x: 'BinNode[T]') -> None:
    pass
  
  def __lt__(self, t : 'BinTree[T]') -> bool:
    return self._root and t._root and self._root < t._root

  def __eq__(self, t : 'BinTree[T]') -> bool:
    return self._root and t._root and self._root == t._root

  


  