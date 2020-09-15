Snake Game
============

Goals
 -----
 The purpose of this assignment is to learn to
 1. The classic game of Snake. Move a "snake" (line of sprites) along a 2D grid attempting to run over a randomly placed object to help it grow.
 2. If it runs into itself the game is over and the player has lost.
 3. The object of the game is to make the snake as big as possible.

Programming
-----------
### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors of your background, snake, and object.
- Create a function that makes the snake move continuously forward, and controls the snake's body insuring it trails along behind its head.
- Create a function that allows the player to control the direction of the snakes head.
- Create a function that generates the snakes food object into a random cell on the grid.
- Create a function that handles the condition of the snakes head interacting with the food object. Make sure the snakes body grows and the object is gone after a collision.
- Implement a condition which triggers a game over if the snakes head collides with its body.

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

###Key Press Events - Blocking Games
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
#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)
#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
