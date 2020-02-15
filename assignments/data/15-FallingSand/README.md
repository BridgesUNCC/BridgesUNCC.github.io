Assignment 15 : Falling Sand
============================

Source
------

This is a nifty assignment from 2017 proposed by Dave Feinberg.
[Source](http://nifty.stanford.edu/2017/feinberg-falling-sand/)


Goals
-----
The purpose of this assignment is to learn to 
 - Organize data in two-dimensional arrays
 - Use data from arrays to control conditional statements
 - Practice recursion
 - Practice simulation techniques
 - Practice debuging using real-time interactions with visualizations

Programming
-----------
#### Tasks
 - Use loops to populate and update a grid with values that represent multiple elements.
 - Define the behavior of a grid cell that contains a water, metal, sand, or empty spaces.
 - Use keypress events to change the type of element that is selected.
 - Indicate the currently selected element by chaning the color of the cursor cell.
 - Update the color of the grid cell when the elemental values change.
 - Draw metal containers within the grid to test waters reaction. Water should fill closed containers and fall over the side when full.
 - Make sand fall through the water and increase the waters height.

#### Water
Water falls down when the space below is empty, if the space below is sand, metal or the bottom of the container the water should test if there is also a solid on either side of it or if it should flow left or right.
#### Sand
Sand falls through water and down through empty spaces. It makes water rise as well. It wont fall through metal or the bottom of the container though. If sand is stacked more than three cells high then it will fall left or right depending on if there is water or an empty space next to it.
#### Metal
None of the other basic elements go through metal. Metal also doesn't fall when placed even if there's an empty space under it. Metal can be used as a container higher up in the grid.
#### Additional
Students can define the behavior of different types of elements not described in the original problem. Using over 100 colors and symbols to represent these elements in a grid. For example, lava is an element which could move through metal and also evaporate water turning it into steam which would react differently to the other elements.
### Help
#### For C++
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1game_1_1_non_blocking_game.html)
#### For Python
[NonBlockingGame documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1non__blocking__game_1_1_non_blocking_game.html)
