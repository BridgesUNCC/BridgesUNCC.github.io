Assignment 6 - Square Fill
==========================

Goals
-----

The purpose of this assignment is to learn to

1. Manipulate a ColorGrid object.
2. Generate colorful squares


You will generate a visualization that looks like [that](http://bridges-cs.herokuapp.com/assignments/6/bridges_workshop)!

Programming part
----------------

### Task

You will be drawing Square Fill using the following logic: (examples provided below.)

1. Start with an empty canvas.
2. Generate a random point that has not been painted yet. Paint it, that is a square of dimension 0.
3. If the outer layer of the square has not been painted yet (aka, if none of the pixel of the outer layer has been painted)
4. Paint it and go to the next layer.
5. Keep painting layers until you reach the border of the image, or one of the layer has a painted pixel.
6. Pick a new random point.

### Basic

1. Open your scaffolded code.
2. Plug in your credentials.
3. Complete the TODOs in the scaffoled code.
4. Run and visualize your code

### Build Square Fill 

1. Plug in your credentials
2. Observe how the code initizes the `ColorGrid`. The code provides a variable that represents a pixel is free, which is
 embedded into the `Color` objects alpha value. This allows for a much quicker check later on to see if a pixel is free,
 you may refactor this if you do not wish to use the alpha value for this purpose.
 
3. Provide the code necessary to generate a random point on the grid, check that point to make sure it is free, and then
 set that location to some random color.
 
4. An example snippet is provided in the next TODO that gives an example of how to set up some int's to keep track of each
  layers boundaries. Ensure that these points are not out of bounds before continuing.
  
5. In the first for loop, provide the logic for checking each point on the current layer to make sure it is free, if not
 break the loops to generate a new point on the grid to start from.
 
6. If the current layer has no collisions, generate a random color and then begin filling in the points along the current
 layer with the generated color.
 
7. Run and visualize the code.

### Help

#### for Java

[ColorGrid documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/namespacebridges_1_1base.html)

#### for C++

[ColorGrid documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_color.html)

[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1_bridges.html)

### Sample Output

![Example3](figures/GridFillExample3.png)
