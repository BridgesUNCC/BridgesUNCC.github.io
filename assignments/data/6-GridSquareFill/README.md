
Assignment 6 - Square Fill
====================

Goals
-----

The purpose of this assignment is to learn to

1. Manipulate a ColorGrid object.
2. Generate colorful squares


You will generate a visualization that looks like [that](http://bridges-cs.herokuapp.com/assignments/6/bridges_workshop)!

Programming part
----------------

###Task

You will be drawing Square Fill using the following logic: (examples provided below.)

- Start with an empty canvas.
- Repeat the following steps.
	1. Search the canvas for an empty pixel.
	2. Set the pixel to a random color.
	3. If the surrounding square of pixels are empty and not outside the canvas continue otherwise go back to step 1. 
	4. Color the surrounding square of pixels with a color.
	5. Expand the square by 1 and repeat step 3.
- Stop once the canvas is fully colored in.

Reference
------------

####  Java

[ColorGrid documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/namespacebridges_1_1base.html)

#### C++

[ColorGrid documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_color.html)

[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/namespacebridges_1_1_bridges.html)

#### Python

[ColorGrid documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color__grid_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color_1_1_color.html)

[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)
