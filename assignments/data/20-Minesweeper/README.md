# Assignment 20 - Minesweeper Game

## Example Output

<img src="./Minesweeper.png" alt="image" width="550"></img>


## Learning Outcomes

1. Loops
2. 2D Arrays
3. Recursion


## Goals

 The purpose of this assignment is to learn to
 1. How to maintain states of multiple 2D arrays.
 2. Test conditions between multiple arrays.
 3. Improve efficiency in using loops and switch statements.


## Description

### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors of your mines, the layer covering the mines, the players carrot.
- Create an input handling function that read keypress events so that the players carrot moves around the screen.
- Add additional input to allow the player to select or flag a tile.
- Add conditions for a tile selection that contains a bomb or does not.
- If there is no bomb the game of minesweeper generally reveals some of the spaces around the empty space that was selected.
- Add a replay and a quit button.

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

#### Key Press Events - Blocking Games
- getKeyPress(); Returns a string.
- "ArrowLeft"
- "ArrowRight"
- "ArrowUp"
- "ArrowDown"
- "w"
- "s"
- "a"
- "d"
- etc...

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

#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)