Bugstomp Game
============

Goals
 -----
 The purpose of this assignment is to learn to
 1. Move a character sprite around a 2D grid to step on randomly generated bug sprites.
 2. Use loops, 2D arrays, and conditional statements to move the character and check if he has stepped on a bug sprite.

Programming
-----------
### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors of your character, bugs, and background.
- Determine the starting point of your character on the grid.
- Create a function that uses keypress events to move the character around.
- Create a function that will generate bugs in a random place on your grid.
- Create a function that will check if the character has collided with a bug.
- Create a function that removes bugs after some amount of time.
- Create a win condition.

More Details to Get You Started
-------------------------------
###Key Press Events - NonBlocking Games
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

// Not Used Now //
####Key Press Events - Blocking Games
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
// Not Used Now //

###Variables, Colors, and Sprite Symbols
- NamedSymbol.symbolname;
- NamedColor.colorname;
- drawObject(column, row, NamedSymbol, NamedColor);
- setBGColor(column, row, NamedColor);

###Important Functions
- The gameLoop() function loops until the game is over.
- quit() stops the game.
- start() starts the game and calls the initialize() function once before it starts the gameLoop() function.
- render() sends your updated game grid to the server once. This is a blocking game function.

### Help
#### For Java
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)
#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)
#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
