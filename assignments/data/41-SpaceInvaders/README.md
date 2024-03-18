Assignment 41 - Space Invaders Game
============

Goals
-----
The purpose of this assignment is to learn to
 - Organize data in two-dimensional arrays
 - Use enums to store information
 - Practice using nested for loops
 - Use basic OOP techniques

Programming
-----------
### Tasks
 - Implement the generateBoardBackground() method such that each background tile is assigned a color. The color(s) you 
 use or any patterns you want to add are up to you.
 - Complete the movePlayer() method. The playerX and playerY variables should be updated according to the keys the 
 player presses. Ensure that the program does not crash if the player tries to move out of bounds. 
 - Complete the playerFire() method. When the player presses space, a new PlayerProjectile should be added to
 playerProjectiles.
 - Complete the moveEnemies() method. Each enemy should move in the direction described by the enemyMoveDirection 
 variable. If any enemy tries to move off the bottom of the board, the game should end.
 - Complete the enemyFire() method. A random enemy should be selected and an enemyProjectile should be created at their 
 position.
 - Complete the checkProjectileCollision() method. If a playerProjectile and an enemy are in the same location, delete 
 both. If an enemyProjectile and the player are in the same location, end the game.
 

### Important Functions
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
