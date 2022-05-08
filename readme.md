# Data Structures and Algorithms
A repository containing my journey with data structures and algorithms.

## Implementations
Implementing different data structures and their basic functionality by hand (mostly in python). For example, the linked list data structure is implemented in `Implementation\List.py` and can be declared as such

```python
myList = List[int]() # declare and be able to handle generics/typing
for i in range(0, 20): # generate random numbers
  n = random.randint(1,100)
  myList.insertAasLast(e)

test.traverse() # print out unsorted
test._radixSort() # use radix sort
test.traverse() # print out sorted
```

or BST data structure

```python
myBST = BST[int]() # declare BST
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
```

Data structures implemented so far
1. List
2. Vector
3. Stack (using List and Vector)
4. Queue (using List)
3. Binary Tree and Binary Search Tree

Data structures to be implemented
4. BST - AVL, Red Black, BT, Splay
5. Graphs

### Things Learned
1. TypeVar, Genrics, and typing in Python 
2. Python Classes and Inheritance

## Visualizations
Visualizing data structures and algorithms. For example, visualizing linked list sorting algorithms is implemented in `Visualization\ListSorting.py` and is implemented using Pygame, it is a very basic implementation

![ListSorting](/Images/ListSorting.mp4)

### Things Learned
1. Pygame 
2. Generators in Python
3. Networkx, Graphviz, and Matplotlib

## Leetcode
Using the leetcode extension of vscode to keep track of my progress in completing leetcode problems.

### Things Learned