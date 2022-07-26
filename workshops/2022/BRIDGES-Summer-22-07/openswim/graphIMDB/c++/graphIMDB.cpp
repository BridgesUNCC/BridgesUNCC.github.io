
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#include "Bridges.h"
#include "GraphAdjList.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

int  main() {

  // Initialize BRIDGES with your credentials
  Bridges bridges(103, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
  
  // set title, description for visualization
  bridges.setTitle("UNCC BRIDGES Workshop: May 2022");
  bridges.setDescription("Drawing a graph using IMDB Actor-Movie Pairs");

  // use an adjacency list based graph
  GraphAdjList<string> graph;

  // get the actor movie IMDB data through the BRIDGES API
  DataSource ds;
  vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1814);


  // TODO: You will build a graph that takes the actor-movie list (of 
  // type ActorMoviIMDB) and build a graph that connects each actor to
  // the corresponding movie and also the movie to the actor.
  // Check the graph tutorial at 
  // http://bridgesuncc.github.io/tutorials/Graph.html
  // and the graph adjacency list documentation at
  // http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_graph_adj_list.html
  // for additional information

  // Note: The actors and movies will occur multiple times. So before you 
  // create a new movie or actor node, you must check if it has already 
  // been created. You can use the getVertex() method to check to see if
  // if an actor or movie exists in the graph (will return nullptr otherwise)


  // graph has been created, give it to BRIDGES and visualize
  // bridges.setDataStructure(&graph);
  // bridges.visualize();

  return 0;
}
