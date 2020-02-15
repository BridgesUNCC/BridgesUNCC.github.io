Temporal Bacon Number
=====================

This assignment is a more advanced version of [Bacon
Number](http://bridgesuncc.github.io/assignments/data//3-GraphBaconNumber/README.html)

Goals
-----

The [Bacon
Number](https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon) of
an actor is the number of step it takes to go from an actor to Kevin
Bacon by only going from an actor to an other one that played together
in a movie.

Computing the Bacon number of an actor boils down to computing BFS in
an Actor-Movie graph. However, the Bacon number of an actor decreases
as time passes, since more movies are made. The purpose of this
assignment is to track the Bacon number of some actors over time.

We will also study the time it takes to answer the question when the
graph gets bigger as more movies are made.


Tasks
-----

1. Get the Movie Actor data for year interval from wikidata using the Bridges API: DataSource.getWikidataActorMovie()

2. Construct a graph where vertices are Movie and Actors, and there is an edge between a movie and an actor if the actor played in the movie.

3. Compute the BFS distance from Kevin Bacon to the rest of the graph.

4. Plot over time the Bacon Number of a few actors, for instance Idris Elba and Demi Moore.

5. Measure the time each of the BFS calculation takes. Use LineChart to show the time it takes to compute the BFSs as a function of the time range, the number of vertices in the graph, and the number of edges in the graph. You can use LineChart to plot some data.

Variants
--------

We used a graph where the vertices are Movies and Actors, but one
could directly build a graph of actors with an edge between them if
they played in the same Movie. Would that be faster? Implement the
problem using a graph of Actors (not including Movies) and confirm (or
infirm) your intuition.

### Help

#### For C++
[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_line_chart.html)

#### For Java
[Bridges documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_line_chart.html)

#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/namespacebridges_1_1bst__element.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1line__chart_1_1_line_chart.html)