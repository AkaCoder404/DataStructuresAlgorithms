import random
from List import List
from Vector import Vector
from Stack import StackList, StackVector
from BST import BST



def vector_test():
  # capacity, size, initial value
  # test = Vector[int](10, 5, 0)
  test = Vector[int](10, 0, 0)
  randomList = []
  for i in range(0, 20):
    n = random.randint(1,100)
    randomList.append(n)

  for e in randomList:
    test.insert(e)

  test.traverse()
  # test._bubbleSort(0, 20)
  # test._selectionSort(0, 20)
  test._selectionSort(0, 20)
  test.traverse()
  # test.unsort(0, 5)
  # test.traverse()
  test.uniquify()
  test.traverse()
def list_test():
  # generate random list of nodes a
  test = List[int]()
  randomList = []
  for i in range(0, 20):
    n = random.randint(1,100)
    randomList.append(n)

  for e in randomList:
    test.insertAsLast(e)

  test.traverse()
  test._radixSort()
  test.traverse()
def stack_test():
  myStackList = StackList[int]()
  myStackList.push(5)
  myStackList.push(4)
  myStackList.push(3)
  myStackList.traverse()
  myStackList.pop()
  print(myStackList.top())

  myStack = StackVector[int](0, 0, 0)
  myStack.push(5)
  myStack.push(4)
  myStack.push(3)
  myStack.traverse()
  myStack.pop()
  myStack.traverse()
  print(myStack.top())

def bst_test():
  myBST = BST[int]()
  myBST.insert(10)
  myBST.insert(5)
  myBST.insert(15)
  myBST.insert(20)
  myBST.insert(0)
  myBST.insert(7)
  myBST.insert(13)
  myBST.insert(6)
  myBST.insert(9)
  myBST.travel_inorder() # in order tree traversal
  print("\nSize", myBST.size()) # tree size
  print("Height", myBST._root.height) # tree height

  myBST.secede(myBST.search(15)) # secede tree with root 15
  myBST.remove(5) # remove tree with node 5
  myBST.search(10).data # search tree for node 5
  myBST.travel_inorder()
def bt_test():
  pass





if __name__ == "__main__":
  bst_test()