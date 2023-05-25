Snake Game With Queues
======================

The classic game of Snake. Move a "snake" (line of sprites) along a 2D grid attempting to run over a randomly placed objects (apple, bombs) to help it grow or shrink.
If the snake  runs into itself the game is over and the player has lost.
The objective  of the game is to make the snake as big as possible.

Learning Goals
--------------
1. Loops, Conditionals and minimally struct/classes
2. Linked lists
3. Queues (to change the snake size) 
4. Detect collisions

Programming
-----------
### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors of your background, snake, and object.
- Create a function that makes the snake move continuously forward (4 possible directions),
 	and controls the snake's body insuring it trails along behind its head.
- Functions to locate and detect objects in the grid (apple, bomb).
- Functions to grow or shrink the snake size 
- Implement a condition which triggers a game over if the snakes head collides 
	with its body.

More Details to Get You Started
-------------------------------
###Key Press Events - NonBlocking Games
- keyUp()
- keyDown()
- keyLeft()
- keyRight()


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
[NamedSymbols](http://bridgesuncc.github.io/doc/java-api/current/html/enumbridges_1_1base_1_1_named_symbol.html)

[NamedColors](http://bridgesuncc.github.io/doc/java-api/current/html/enumbridges_1_1base_1_1_named_color.html)

[NonBlockingGame](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)

#### For C++
[NamedColor](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1game.html#afaa832a4322b25b6a4ebfba832f10f26)

[NamedSymbol](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1game.html#ab9a19c7ab6e2ebac2f95180e21733487)

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Python
[NamedColor](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1named__color_1_1_named_color.html)

[NamedSymbol](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1named__symbol_1_1_named_symbol.html)

[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
