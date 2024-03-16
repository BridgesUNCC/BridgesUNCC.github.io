# Assignment 19 - Bugstomp Game

## Example Output

<img src="./Bugstomp.png" alt="image" width="550"></img>


## Learning Outcomes

1. Loops
2. 2D Arrays
3. Conditional Statements


## Goals

The purpose of this assignment is to learn to
1. Move a character sprite around a 2D grid to step on randomly generated bug sprites.
2. Use loops, 2D arrays, and conditional statements to move the character and check if he has stepped on a bug sprite.


## Description

### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors of your character, bugs, and background.
- Determine the starting point of your character on the grid.
- Create a function that uses keypress events to move the character around.
- Create a function that will generate bugs in a random place on your grid.
- Create a function that will check if the character has collided with a bug.
- Create a function that removes bugs after some amount of time.
- Create a win condition.

### More Details to Get You Started
#### Key Press Events - NonBlocking Games
- keyUp()
- keyDown()
- keyLeft()
- keyRight()
- keyQ()
- keySpace()
- keyW()
- keyS()
- keyA()
- keyD()

#### Variables, Colors, and Sprite Symbols
- NamedSymbol.symbolname;
- NamedColor.colorname;
- drawSymbol(column, row, NamedSymbol, NamedColor);
- setBGColor(column, row, NamedColor);

#### Important Functions
- The gameLoop() function loops until the game is over.
- quit() stops the game.
- start() starts the game and calls the initialize() function once before it starts the gameLoop() function.
- render() sends your updated game grid to the server once. This is a blocking game function.


## Extensions


## Help
#### For Java
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)

[NamedColor Documentation](http://bridgesuncc.github.io/doc/java-api/current/html/enumbridges_1_1base_1_1_named_color.html)

[NamedSymbol Documentation](http://bridgesuncc.github.io/doc/java-api/current/html/enumbridges_1_1base_1_1_named_symbol.html)

#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

[NamedColor Documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1game.html#afaa832a4322b25b6a4ebfba832f10f26)

[NamedSymbol Documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1game.html#ab9a19c7ab6e2ebac2f95180e21733487)

#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)

[NamedColor Documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1named__color_1_1_named_color.html)

[NamedSymbol Documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1named__symbol_1_1_named_symbol.html)
