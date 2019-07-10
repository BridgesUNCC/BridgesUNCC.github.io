
Assignment 13 - Infinite Runner
===========================
 Goals
 -----
 The purpose of this assignment is to learn to
 - Handle collision of objects on a 2D grid
 - Implement core functionality in a base class and use inheritance

Programming
-----------
### Tasks
- Create a base object that gets called every game update
- Create a player, collectable, and enemy object

### Player
The player object starts near the left side of the screen. It should check for jump input every update and if it is colliding with the ground it should move away from the ground for several turns then fall back to the ground and stop. If the player overlaps with a collectable it should be removed and points added. If colliding with an enemy then a life should be taken away and the enemy removed.
### Collectable
The goal of the game is to get as many collectables as possible. The collectables start on the right side of the screen at a random y position that the player can reach and move left every update. If the player overlaps the collectable should be removed and points added. If the collectable reaches the other side of the screen a life is removed from the player.
### Enemy
Enemies sometimes spawn along with the collectables on the right side of the screen and move left every update the same as the collectable. If they player collides with an enemy then the enemy should be removed and a life removed from the player.
