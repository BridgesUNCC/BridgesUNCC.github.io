ColorEncoding
=============

This assignment let students explore the implication of encoding of
colors in graphics.

## Learning outcome

-write a basic image generation code
-interpolate values linearly
-understand the impact of bit-depth in color encoding
-using random dithering to combat discretization


## Steps

### Step 1

Write a code that create a Color Grid of a given size (say 800x800)
and which given two colors. (Say white and black.) creates a gradient
where the top left pixel is one color (say white) and the bottom right pixel
is the other color (say black). And that interpolate through all
shades (here of grey) in between.

A common way to do this is to first write a color interpolation
function that takes two colors and a blending parameter `b` in [0,1]
and that returns a color that takes a fraction `b` of its channel from
one color and `1-b` from the other.

Then for each pixel of the image, set its color to be the blended
color between the top left and the top right pixel, with a blending
parameter set to the distance between the pixel and top left to the
distance between teh top left pixel and the bottom right pixel.

### Step 2

Adjust the code to generate a color gradient from color rgb(24,24,24),
rgb(48,48,48).

Is there something off about the image you generated? Does it look
"banded" to you (you may need to adjust your screen's brightness to
see it.)

Why do you think this is happenning? Have you seen this effect before?
It is common in poorly compressed videos with dark scenes.

### Step 3

The problem comes from the rounding that happens, if a blended channel
should have value say `3.4`, it gets truncated to the lower integer
`3`, which makes a band all the pixels of blended value 3.0 up to
`3.9999` get rounded to `3`.

An idea to correct this effect is to round probabilistically so that a
channel of blended value `3.4` actually has an expected value of `3.4`
(instead of `3.0` in the previous version).

A way to do this is with a value of `x.y` to give value `x+1` with
probability `y` and `x` with probability `1-y`.

Implement this. Does this correct the visual bending effect?


## Help
### for C++

[ColorGrid documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)

### for Java

[ColorGrid documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

### for Python

[ColorGrid documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color__grid_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)
