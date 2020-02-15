Assignment 32 - Temporal Page Rank
==================================

This assignment is a more advanced version of [Bacon
Number](http://bridgesuncc.github.io/assignments/data//3-GraphBaconNumber/README.html)

Goals
-----

1. Construct a `GraphAdjList` using wikidata.
2. Organize the data by page rank using `PageRankBenchmark`.
3. Visualize wikidata using `Bridges`.

Tasks
-----

1. Get the Movie Actor data for year interval from wikidata using the Bridges API: DataSource.getWikidataActorMovie()
2. Construct a graph where vertices are Movie and Actors, and there is an edge between a movie and an actor if the actor played in the movie.
3. Calculate the page rank of the data

### Help

#### For C++
[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)

[PageRankBenchmark documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1benchmark_1_1_page_rank_benchmark.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_line_chart.html)

#### For Java
[Bridges documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

[PageRankBenchmark documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1benchmark_1_1_page_rank_benchmark.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_line_chart.html)

#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/namespacebridges_1_1bst__element.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1line__chart_1_1_line_chart.html)