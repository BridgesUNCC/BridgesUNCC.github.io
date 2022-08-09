Bridges Games Controls Tutorial Two
===================================

Goals
-----

To teach students the functions that allow them to interact with their games.
In tutorial two, students will move a sprite around the grid.

1. Understand the main variables used to run a bridges game.
2. Learn about the initialize() method.
3. Understand ways students can implement their own methods and how to traverse the grid using for loops.
4. Learn how to use the gameLoop() method to move a sprite around on the grid.
5. Prepare the main method and run a game.

Variables
---------

Sets the size of the students grid. Grids are limited to 1024 cells. The largest square grid available is 32 x 32.
- int gridColumns
- int gridRows

Variables that will change the color and symbols despalayed in the game.
- NamedColor myBackgroundColor
- NamedColor mySymbolColor
- NamedSymbol mySymbol

variables that will keep track of a sprites location
- int duckColumn
- int duckRow

Functions
---------

initialize()
- A required bridges function. This runs before the game loop begins allowing the students an oppertunity to set the colors and symbols of their game before it starts.

gameLoop()
- A required bridges function. A recursive method that will run until the game is over or is disconnected. Students can call their own methods here to make their games more complex.

Boolean values that are true when a specific key is being pressed.
- keyUp()
- keyDown()
- keyLeft()
- keyRight()
- keyW()
- keyS()
- keyA()
- keyD()
- keyQ()
- keySpace()

Main Method and Student Class Object
------------------------------------

Students must structure their class object to call "super" and pass the variables of their bridges account in order for the bridges server to visualize their game.
Within the Class object students can also set their games title and a short description of the game. They must ensure the start() function is called here.

Help
----

#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)

#### For Java
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1games_1_1_non_blocking_game.html)

#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)