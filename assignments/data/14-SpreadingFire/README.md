Assignment 14 - Spreading Fire
==============================

Source
------

This is a nifty assignment from 2007 proposed by Angela B. Shiflet.
[Source](http://nifty.stanford.edu/2007/shiflet-fire/)

Goals
-----
The purpose of this assignment is to learn to 
 - Organize data in two-dimensional arrays
 - Use data from arrays to control conditional statements
 - Practice recursion
 - Practice simulation techniques
 - Implement probabilities in code

Programming
-----------
### Tasks
 - Use loops to populate and update a grid with values that represent trees, empty spaces, and fire.
 - Define the behavior of a grid cell that contains a fire, trees, or an empty space.
 - Update the color of the grid cell when the values change.
 - Continue updating the grid until all trees are burned out or the fire has gone out.
 - Try different probabilities to see the different behaviors of fire depending on the location of empty spaces, fire, and trees. For example, try making an X across the grid with empty spaces. Or make a grid with empty spaces around the edges.

### Empty spaces
Empty spaces are represented with a yellow color and will not catch fire.
### Trees
Trees are represented with green and can catch fire if there is a fire in an adjacent cell. However, the condition for catching fire is not only touching fire. There should also be a probability test that determines if it will ignite.
### Fire
After a certain amount of time, a fire should go out and become an empty cell.

### Help
#### For C++

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Python

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)