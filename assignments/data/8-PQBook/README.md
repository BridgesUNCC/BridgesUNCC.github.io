Assignment 8 - Priority Queue Book
==================================

Goals
-----

The purpose of this assignment is to learn to

1. Access Shakespear's work with BRIDGES
2. Write your own tree based data structure: A Binary Min-Heap

You will generate a visualization that looks like [that](http://bridges-cs.herokuapp.com/assignments/8/bridges_workshop)!


Programming part
----------------

### Task

The purpose of this assignment is to build a MinHeap in BRIDGES
represented as a binary tree (as opposed to the more common array
representation of a heap)

Recall that as a binary tree, a heap defined recursively as a root and
two subheaps. The invariant of a min heap is that the root of any heap
should have a lower (or equal) key than any node contained in the
heap.

### Getting Started

1. Open your scaffolded code.
2. Plug in your credentials.
3. Observe the `MyHeapElement` class that extends BRIDGES's `BinTreeElement`.
4. Observe the `MyHeap` class that provide Min Heap features. 

### Build a Binary Min Heap

1. Write the insert function in MyHeap. There are todos to guide you.

The algorithm for inserting in a heap is as follows. (This algorithm
ignores that there is a key and a value.) Note that it uses
information about the size of the subheaps being stored at each node
of the heap.

```algorithm
Heap {
  Key
  HeapLeft
  SizeHeapLeft
  HeapRight
  SizeHeapRight
}

insert (Heap h, k) {
  if (h is empty)
    return makenewheap (k)

  if (k < h.Key)
    swap k and h.Key

  if (SizeHeapLeft < SizeHeapRight)
    //push left
    SizeHeapLeft = SizeHeapLeft + 1
    HeapLeft = insert (h.HeapLeft, k)
  else
    //push right
    SizeHeapRight = SizeHeapRight + 1
    HeapRight = insert (h.HeapRight, k)

  return h
}
```

### If you have time

1. Use all of Shakespeare's works.
2. Change the location of the insert and pop in the main function to keep only the 100 most occuring words in the heap at any time.
3. Style the heap so that words with more than 1000 occurences are highlighted.

### Help

#### for Java

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)

[BinTreeElement documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_bin_tree_element.html)

[Shakespeare documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_shakespeare.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/namespacebridges_1_1base.html)

#### for C++

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color.html)

[BinTreeElement documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_bin_tree_element.html)

[DataSource documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_data_source.html)

[Shakespeare documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_shakespeare.html)


#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)

[Color documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color_1_1_color.html)

[BinTreeElement documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bin__tree__element_1_1_bin_tree_element.html)
