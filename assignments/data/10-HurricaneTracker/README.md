# Assignment 10 - Hurricane Tracker

## Example Output

<img src="./hurricane.png" alt="image" width="550"></img>


### Source

This is a nifty assignment from 2018 proposed by Phil Ventura.
[Source](http://nifty.stanford.edu/2018/ventura-hurricane-tracker/nifty-hurricanes.html)


## Learning Outcomes

1. Reading and parsing data from a CSV file to display points on a map


## Goals

The purpose of this assignment is to learn to
1. Read and parse data from a csv file
2. Manipulate a GraphAdjList object
3. Display several points on a map


## Description

### Tasks
Read a csv file containing Hurricane position data such as the data given [here](https://www.wunderground.com/hurricane/atlantic/2017/hurricane-irma). Then map this data on a GridAdjList.

#### Read the csv File
Parse the csv file data and create a class for storing this data.

#### Build the Graph
- Create a `GraphAdjList`
- Add each data point to the graph as vertices if they are within a certain distance
- Change the color of the points based on the hurricane's category.
- Add edges between points in order from first to last.


## Extensions


## Help

#### For C++
[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)

[File I/O](http://www.cplusplus.com/doc/tutorial/files/)

[Element documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_element.html)

[GraphAdjList documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_graph_adj_list.html)

[ElementVisualizer documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_element_visualizer.html)

#### For Java
[Bridges documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

[Element documenation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_element.html)

[GraphAdjList documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_graph_adj_list.html)

[ElementVisualizer documenation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_element_visualizer.html)

#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)

[Element documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1element_1_1_element.html)

[GraphAdjList documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1graph__adj__list_1_1_graph_adj_list.html)

[ElementVisualizer documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1element__visualizer_1_1_element_visualizer.html)
