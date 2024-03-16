# Assignment 12 - A* Maze

## Source

This is a nifty assignment from 2008 proposed by Don Blaheta.
[Source](http://nifty.stanford.edu/2008/blaheta-maze/)


## Learning Outcomes

1. Stacks
2. Queues
3. Shortest Path
4. Graphing


## Goals

 The purpose of this assignment is to learn to
 1. Generate a random maze on a 2D Grid
 2. Write the A* algorithm for traversing a grid 
 3. Display the algorithm at each step to the grid as it traverses the maze


## Description

#### Tasks
- Create a maze on a 2D grid. There are many maze algorithms 
- Write a pathfinder using the A* algorithm to traverse the 2D grid
- Choose two points on opposite sides of the grid and use the pathfinder get from point a to b. 
- During each step in the algorithm color in the pathfinder's current position
- After the goal is reached pop back and display the full path.
 
#### Create the maze
There are plenty of algorithms for generating a maze. Prims algorithms is a good place to start. Then create a grid to display the maze and keep track of the open positions and walls on the grid.

#### Create the pathfinder
Create a pathfinder that uses the A* algorithm to traverse the grid towards a goal point.


## Extensions


## Help

#### For Java
[AStar Explanation(Geeks for Geeks](https://www.geeksforgeeks.org/a-search-algorithm/)

[NonBlockingGame](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)

[Maze Algorithms(Wikipedia)](https://en.wikipedia.org/wiki/Maze_generation_algorithm)

#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
