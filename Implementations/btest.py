from turtle import right
from BinaryTree import BinTree, BinNode
from BinaryTree import *
from typing import TypeVar
from util import *

T = TypeVar("T")

# randomly generate a binary tree of height h
def randomBinTree(bt : 'BinTree[T]', x : 'BinNode[T]', h : int ) -> bool:
  if 0 >= h:
    return False
  if 0 < dice(h):
    randomBinTree(bt, bt.insert(e=x, right_child=dice(T(h*h*h))), h - 1)
  if 0 < dice(h):
    randomBinTree(bt, bt.insert(e=x, left_child=dice(T(h*h*h))), h - 1)
  return True

# randomly determine a node position in the binary tree
def randomPosiInBinTree(root : 'BinNode[T]'):
  if not hasChild(root):
    return root
  if not hasLeftChild(root):
    return randomPosiInBinTree(root.right_child) if dice(6) else root
  if not hasRightChild(root):
    return randomPosiInBinTree(root.left_child) if dice(6) else root
  return randomPosiInBinTree(root.left_child) if dice(2) else randomPosiInBinTree(root.right_child)

# test the binary tree
class testBinTree(Generic[T]):
  def __init__(self, h) -> None:
      print("Generate a binTree of height", h)
      bt : 'BinTree[T]' = BinTree[T]()
      # print(bt)
      bt.insert(dice(T(h*h*h)))
      # print(bt)
      randomBinTree(bt, bt.root(), h)
      # print(bt)
      print("Double and increase all nodes by traversal")
      print("Remove/release subtrees in the Tree")
      
def main():
  # size = input("Size of Test")
  # testBinTree[int](size)


  myTree = BinTree[int]()
  root = myTree.insert(10) # insert root
  # myTree._root = BinNode[int](data=10)
  # myTree._root.left_child = BinNode[int](data=5)
  # myTree._root.right_child = BinNode[int](data=15)
  myTree.insert(5, left_child=root) # insert to left child 
  myTree.insert(15, right_child=root) # insert to right child

  print("Travel Level")
  myTree.travel_level()

  print("\nTravel Preorder")
  myTree.travel_preorder()

  print("\nTravel Inorder")
  myTree.travel_inorder()

  print("\nTravel PostOrder")
  myTree.travel_postorder()

  print("\nSize", myTree.size())
  print("Height", myTree._root.height)


if __name__ == "__main__":
  main()