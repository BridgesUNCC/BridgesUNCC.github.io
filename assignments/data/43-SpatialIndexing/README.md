# Spatial Indexing - 43

## Example Images
<img src="./figures/fig1.png" alt="Example" width="550px"></img>
<img src="./figures/fig2.png" alt="Example" width="550px"></img>

## Goals

1. Working with OpenStreet Map Data
2. Given a map of locations and amenities, to find the closest point or
	amenity of that type
3. CS concepts: 2D array addressing, using acceleration structures 
	for efficient search


## Description
Given a 2D location, the goal is 
to find the closest point (or amenity).

You are given a dataset that represents a region of map data, from
OpenStreet Map. The data is in the form of a list of locations with
Lat/Long values. Your goal is, given a 2D location (X, Y), to find the
closest point on the map. Given that the data can contain tens of thousands
of locations, you will use a uniform grid to accelerate the search.

### Search Algorithm 
You want an algorithm that is scalable to very large datasets; hence you will
use a data structure to make this process efficient. A uniform grid overlaid
on the search area will be used to hold the location data. 

1. A uniform 2D grid of a  specified size will be used to store the 
location data. Each of the location will be inserted into its appropriate
2D cell of the grid and held in a list. Locations within the cell will need
to queried linearly.

2. Once the data is in the search structure, the algorithm starts by locating
the cell containing the query point. All points within the cell are queried
to compute the distance to the query point and the closest point and distance
is retained. Note that the cell may not contain any points.

3. The algorithm next identifies the cells neighboring the cell containing
	the query point. Points within these cells are searched for the closest
	point.

4. Step 3 can be furhter accelerated by firs determined the orthogonal
	distance  to neighboring cells (to row above and below, columns to the
	left and right) and only if this distance is smaller the currently 
	stored smallest distance would the correponding cells need to be searched.

5. As needed, the algorithm proceeds layer by layer starting from the query
cell. See the two figures above that illustrates the layers generated 
(step 3), displayed in a ColorGrid.

6. If a layer results in no updates to the closest point, then the algorithm
	can be terminated.

### Tasks

1. Get the OpenStreet map data. The BRIDGES API will be used to obtain this 
data. Note that the data size has limitations, requiring the bounding box
specified to be reduced.

2. Display the are using BRIDGES (this can be visualized as a graph).

3. Write a function to identify the cells of a layer. Layer 0 contains
	the cell of the query point, its immediate neighors (neighbors of 
	the red cell in the above figures) are layer 0, and its neighbors are 
	layer 1, etc.

4. Given the query point, write functions to compute the distance to 
the current layer's rows and columns. This will be needed to determine if
these cells need to be examined for closer points. Note that the row or column
might be outside the bounds of the grid and should be ignored in that case.

5. Combine steps 3 and 4 into the algorithm and return the closest point
and distance.

6. Verification: Write up a brute force algorithm, i.e., no uniform grid to
find the closest point to check to ensure your algorithm's output matches. 
Depending on the data size, this test might need to be done a smaller dataset.

7. [Optional:] You may augment your algorithm to display the cells 
queried by the algorithm by recording the cell indices and display them (colored cells) in a ColorGrid. This is also a good way to verify your layers are
being computed correctly (link to 2D assignment).


## Extensions

One can make extensions to this assignment: 

Instead of just looking at Lat/Long data, you might retrieve a set of
resturant locations (say Macdonald's) and look for the closest Macdonalds
from your location(home), or the nearest hospital, fire station, etc.

## Help

[BRIDGES Team:](http://bridgesuncc.github.io/) Contact the BRIDGES team for any 
issues with the BRIDGES API. This is an active project.


#### for Java

[OpenStreet Map Documentation](
http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_osm_data.html)

[OSMVertex] (http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_osm_vertex.html)

[OSMEdge] (http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_osm_edge.html)

[DataSource](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_data_source.html)

[ColorGrid documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

#### for C++
[OpenStreet Map Documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_o_s_m_data.html)

[OSMVertex](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_o_s_m_vertex.html)

[OSMEdge](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_o_s_m_edge.html)

[DataSource](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_data_source.html)

[ColorGrid documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color.html)

[Bridges Class documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)


#### for Python

[OSM Data Documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1data__src__dependent_1_1osm_1_1_osm_data.html)

[OSM Vertex Documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1data__src__dependent_1_1osm_1_1_osm_vertex.html)

[OSM Edge Documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1data__src__dependent_1_1osm_1_1_osm_edge.html)

[ColorGrid documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color__grid_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color_1_1_color.html)

[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)

[DataSource](http://bridgesuncc.github.io/doc/python-api/current/html/data__source_8py.html)
