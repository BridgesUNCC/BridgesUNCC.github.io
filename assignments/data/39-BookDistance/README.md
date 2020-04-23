Book Distance
=============

Overview
--------

Using a simple metric, compute the distance between books using
Dictionary data structure. Then find clusters of books.

Principle
---------

Tasks
-----

### Access a book through BRIDGES API

for instance a shakespeare poem is good to start with

### Compute the Word frequency vector of the book

#### Compute word occurence vector

Simply count how many time each words appear

#### Compute word frequency vector

1. count how many words in the document

2. Divide all counts by the total number of words to get a frequency vector.

### Compare two books

1. Access two books

2. Derive word frequency vectors

3. Compute L2 distance between the two vectors

4. Observe how two close books are more similar than two distant book
(say 2 books by shakespeare and a book by Shakespear and one by Mark
Twain)


#### Variants

1. use tfidf
2. use cosine similarity

### Implement your own Dictionary

#### Using an Array

#### Using a Sorted Array

#### Using a Linked List

#### Using a BST

#### Using a HashMap

#### Implement multiple Dictionary and compare their performance

### Island Clustering

1. For all books available, compute all pairwise distance

2. Build an islanding graph, aka, a graph where
  1. Each Book is a different vertex.
  2. There is an edge between two books if their distance is smaller than T (a user specified threshold)
  3. Build the graph using Bridges Adjacency List interface

3. Visualize the graph in BRIDGES

4. Observe how the graph change when the threshold varies. Do cluster
appear? Do they make sense?

