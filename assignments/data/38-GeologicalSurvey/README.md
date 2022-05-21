Geological Survey
=================

Overview
--------

You are a geologist and you want to survey the location of recent
earthquake. Find a route through all the earthquake site to minimize
total distance travelled.

Greedy
------

We will use a greedy algorithm to solve the problem. That is to say,
when we are at a location, we will go next to the closest location
that has not been visited so far. A greedy algorithm will not return
the best route through all the locations, but it provides a decent
solution to the problem quickly.

Programming
-----------

1. Get location of recent earthquake using Bridges API.

2. Use an array of boolean to record whether a location has been visited or not.

3. Assume we start at earthquake 0.

4. Write a function that returns the earthquake that has not been
visited and which is the closest to a location.

5. Write the code to compute a tour using the greedy principle.

6. Display the tour using Bridges API. You can use the graph data structure to display the tour.

Variants
--------

### Brute Force

### Integer Linear Programming

### Branch and Bound

### Christofides

A 2-approximation based on building spanning trees

#### 3/2 approximation

A refinement of Christofides based on spanning trees and matching

### Meta Heuristics

