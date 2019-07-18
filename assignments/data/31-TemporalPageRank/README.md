Is Kevin Bacon the center of Hollywood?
=======================================

Goals
-----

The [Bacon
Number](https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon) of
an actor is the number of step it takes to go from an actor to Kevin
Bacon by only going from an actor to an other one that played together
in a movie. Computing the Bacon number of an actor boils down to
computing BFS in an Actor-Movie graph.

However, the Bacon number of an actor decreases as time passes, since
more movies are made. The purpose of this assignment is to track the
Bacon number of some actors over time. This means that at some point
Kevin Bacon was not the center of Hollywood. Then who was it?

We will use a centrality measure, namely
[PageRank](https://en.wikipedia.org/wiki/PageRank), to compute who the
most prominent actor of Hollywood are at different point of time.

We will also study the time it takes to answer the question when the
graph gets bigger as more movies are made.


PageRank
--------

PageRank is a very popular graph centrality measure to establish which
vertex is the most important. It is typically computed by using an
iterator process is initialized with.

PR[v] = 1/|V| for all vertices v in the graph

Then, compute

newPR[v] = (1-lambda)/|V| + lambda * sum (PR[x]/degree(x)) for all x a neighboor of v

lambda is a parameter of the algorithm between 0 and 1, and typically set to 0.85.

degree(x) is the number of neighboor of vertex x.

Tasks
-----

1. Get the Movie Actor data for year interval from wikidata using the
Bridges API: DataSource.getWikidataActorMovie()

2. Construct a graph where vertices are Movie and Actors, and there is
an edge between a movie and an actor if the actor played in the movie.

3. Compute the PageRank of the vertices in that graph.

4. For a 20-years large moving windows from 1910 to 2019, compute the
PageRank of all vertices and report who the most prominent actors
are. You can use a LineChart to show the page rank of the 10 most
prominent actors for a 20-year window.

5. Measure the time each of the BFS calculation takes. Use LineChart
to show the time it takes to compute BFS as a function of the time
range, the number of vertices in the graph, and the number of edges in
the graph. You can use LineChart to plot some data. You can build
larger and large graphs by increasing the size of the graphs, the
dataset as data from 1910 to 2019.

Variants
--------

We used a graph where the vertices are Movies and Actors, but one
could directly build a graph of actors with an edge between them if
they played in the same Movie. Would that be faster? Implement the
problem using a graph of Actors (not including Movies) and confirm (or
infirm) your intuition.


One can answer the same question by using different centrality
measures. [Closeness
Centrality](https://en.wikipedia.org/wiki/Closeness_centrality) is a
popular measure since it represents the average distance to the rest
of the graph, and therefore is a proxy for being a good "Kevin
Bacon".