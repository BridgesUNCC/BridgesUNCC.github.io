Race Car Game
=============

Goals
-----
 The purpose of this assignment is to learn to
 1. Create a game where the player drives a car around an ever-changing track.

Programming
-----------
### Tasks
- Initialize a 2D array the size of your game grid.
- Initialize the NamedColors and symbols for your car, walls and background.
- Create a function that places a wall on the left and right of your grid that outlines the road.
- Add additional conditions to your wall creation function to make the walls move closer to each other every few seconds.
- Add additional conditions to your wall creation function so that the walls move side to side every few seconds making it seem as though the road is turning.
- Create a function that allows the player to move the car left and right on the road.
- Create a function that checks for a collision between the car and the wall and triggers a game over.
- Create a function that places random objects that the player could crash into and trigger a game over.
- Create a win scenario.

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
- drawSymbol(column, row, NamedSymbol, NamedColor);
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