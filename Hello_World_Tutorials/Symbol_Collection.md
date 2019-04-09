The SymbolCollection class is a container for holding a variety of shapes that can be used to generate visualizations that does not directly fit a specific data structure, but assists illustrating its underlying concepts. For example, the Towers of Hanoi problem can be implemented using a set of simple shapes : 3 circles for the disks and 3 long thin rectangles to represent the towers. SymbolCollection works currently in BRIDGES with 4 shapes: Rectangle, Circle, Polygon and a Label (facilitates textual information on the visualization). See the associated help pages for the API. Each symbol has a name, location (where it will be placed on the display) and other common stylistic attributes. The subclasses of Symbol have more specific geometric properties (width, height for rectangle, radius for circle, list of points for Polygon, etc). The example below illustrates how to construct shapes and its corresponding visualization.

- - -

## SymbolCollection - Example BRIDGES Program - Illustraing the various shapes supported by BRIDGES

[](./Java_SC.html)[](./Cpp_SC.html)[

## Bridges Visualization

-   Once all your code is in order, run your file.
-   Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
-   Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
-   It should look something like this:

<p>Sorry, your browser doesn't seem to support iframes - <a href="http://bridges-clone.herokuapp.com/assignments/115/bridges_public" scrolling="no">Frame0 Link</a> </p>

Well done! You’ve just completed your Bridges Shape Collection project!

](./Python_SC.html)