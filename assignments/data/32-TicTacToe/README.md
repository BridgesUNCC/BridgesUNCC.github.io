Assignment 32 - Tic Tac Toe
===========================

## Image

<img src="./figures/icon.png" alt="drawing" width="350"></img>

Goals
-----

The purpose of the assignment is to learn to

1. Create games using `NonBlockingGame`
2. Manage a datastructure of values.

Programming part
----------------

#### Tasks

- Initialize a 3x3 empty board to `Bridges`
- Display numbers on each square from 1 in the top left to 9 in the bottom right.
- Take user input from the console about the location of their next move (1-9).
- Validate the user input is inside boundaries, is an integer, and is a valid space.
- Place the users mark on the space.
- Check for a win codition with 3 in a row of the same mark.
- Go to the next player and repeat from taking user input.

#### Setup

To start simple initialize a grid which is 3 by 3. Display the numbers 1-9 in the grid like the following.

1   | 2   | 3
--- | --- | ---
4   | 5   | 6
7   | 8   | 9

#### User Input

Take an integer input from the user that matches the above grid (1-9). If the input is invalid display a message to the player and 
skip their turn. Otherwise place a mark on the position the player specified. Use a different mark for each player.

### Help
#### For C++

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Python

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
