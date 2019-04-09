BRIDGES associates _visual attributes_ with all of its elements, so as make visualizations appealing, and highlight important aspects of the data structure. For instance, you might want to show the path traversed in a binary search tree, the shortest path in an implementation of Dijkstra's algorithm, the Minimum Spanning Tree of a graph. Alternately, an application specific dataset might dictate what needs to be highlighted, for instance, display all of you friends in a Twitter graph, earthquakes that happened in the last week or in a particular area of the world, etc.

## Changing Element visualization properties

Each Element contains properties that control how its visualization looks. You can change how an Element is visualized by interacting with these properties. You can use them to change the size, shape, color, and opacity of each Element.

## Changing Edge visualization properties

Each Element also contains a LinkVisualizer class that controls how the edges between itself and the node it is connected to appears. You can change how an edge is visualized by interacting with that Element's LinkVisualizer. You can use the LinkVisualizer to change the thickness, color and opacity of each edge:

Note that because Element is the superclass of all other element types, that these same methods will also apply to them as well.

## Visualization Syntax

[](./Java_Visual.html)[](./Cpp_Visual.html)

### Bridges Visualization

-   Here is a comparison of the element with default properties to your changed element
-   It should look something like this:

<iframe src="https://bridges-cs.herokuapp.com/assignments/6/bridges_public">

Well done! You’ve just changed an Element's visual properties!