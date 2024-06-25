
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

  for (int  k = 0; k < actor_list.size(); k++) {
    string actor, movie;

    // get the actor and movie names
    actor = actor_list[k].getActor();
    movie = actor_list[k].getMovie();

    // our graph needs to have a unique set of actors and movies;
    // so create the actor and movie vertices only if they dont already
    // exit; use an STL map to check for that

	if (!graph.getVertex(actor))	// doesnt exist
		graph.addVertex(actor);

	if (!graph.getVertex(movie))	// doesnt exist
		graph.addVertex(movie);

	// add edge
	graph.addEdge (actor, movie);

    // TO DO : Highlight "Cate_Blanchett" node and the movie nodes she is
    // connected to  in "red" and do the same for "Kevin_Bacon_(I)" in "green"
    // specify colors by Color("red"), for example
    if (actor == "Cate_Blanchett") {
      graph.getVisualizer (actor)->setColor (Color("red"));
      graph.getLinkVisualizer (actor, movie)->setColor (Color("red"));
      graph.getVisualizer (movie)->setColor (Color("red"));
    }
    if (actor == "Kevin_Bacon_(I)") {
      graph.getVisualizer (actor)->setColor (Color("green"));
      graph.getLinkVisualizer (actor, movie)->setColor (Color("green"));
      graph.getVisualizer (movie)->setColor (Color("green"));
    }
  }
  bridges.setDataStructure(&graph);
  bridges.visualize();

  return 0;
}
