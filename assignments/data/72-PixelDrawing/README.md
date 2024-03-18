# Pixel Drawing

## Goals

The Assignment is a Sandbox game where you can draw anything in the grid that you think of. You will be writing the ability to save the game to a file and reload the game from that file. 

This Assignment will focus on:

1. FileIO
2. Loops and conditionals
3. Controlling values of Arrays

## Programming

This assignment uses the BRIDGES game API, implementing the class NonBlockingGame. 
The user interacts with the gameboard in the following ways
- Arrow keys for moving the cursor around the game board
- Space key for drawing the color where the cursor is
- Q key for changing the color the user is drawing with
- S key for saving the game board to a file
- D key for loading the game board from a file

### Tasks

- Save the state of the board to a file
- Load the state of the board from the same file

![Pixel Drawing !](./figures/PixelShot.PNG)

## Methods and Documentation To Help

### Variables and Classes

NamedColor // Used for drawing colors on board

### Functions

- GameLoop() // loops once per tick, for as long as the game runs
- Start() // Starts game, calls Initialize

### Java Documentation

[NonBlockingGames Documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)

[NamedColor Documentation](http://bridgesuncc.github.io/doc/java-api/current/html/enumbridges_1_1base_1_1_named_color.html)

### C++ Documentation

[NonBlockingGames Documentation](https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

[NamedColor Documentation](https://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1game.html#afaa832a4322b25b6a4ebfba832f10f26)

### Python Documentation

[NonBlockingGames Documentation](https://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)

[NamedColor Documentation](https://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1named__color_1_1_named_color.html)