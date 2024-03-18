# GeologicalSurvey - 38

![Geological](./figures/icon.png)


## Learning Outcomes

## Goals

You are a geologist and you want to survey the location of recent
earthquake. Find a route through all the earthquake site to minimize
total distance travelled.


## Description

### Tasks
1. Get location of recent earthquake using Bridges API.

2. Use an array of boolean to record whether a location has been visited or not.

3. Assume we start at earthquake 0.

4. Write a function that returns the earthquake that has not been
visited and which is the closest to a location.

5. Write the code to compute a tour using the greedy principle.


## Extensions

* Brute Force

* Integer Linear Programming

* Branch and Bound

* Christofides
    * A 2-approximation based on building spanning trees

* 3/2 approximation
    * A refinement of Christofides based on spanning trees and matching

* Meta Heuristics

## Help

### For C++
[Graph Visualization Documentation](https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_graph_adj_list.html)
[Earthquake Documentation](https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_earthquake_u_s_g_s.html)

### For Java
[Graph Visualization Documentation](https://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_graph_adj_list.html)
[Earthquake Documentation](https://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_earthquake_u_s_g_s.html)

### For Python
[Graph Visualization Documentation](https://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1graph__adj__list_1_1_graph_adj_list.html)
[Earthquake Documentation](https://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1data__src__dependent_1_1earthquake__usgs_1_1_earthquake_u_s_g_s.html)