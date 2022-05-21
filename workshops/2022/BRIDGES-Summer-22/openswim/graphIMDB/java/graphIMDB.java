import java.util.List;
import java.lang.String;

import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.base.GraphAdjListSimple;
import bridges.data_src_dependent.ActorMovieIMDB;


public class graphIMDB {
	public static void main(String[] args) throws Exception {
		//create the Bridges object
		Bridges bridges = new Bridges(1, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

		bridges.setTitle("UNCC BRIDGES Workshop: May 2022");
	    bridges.setDescription("Drawing a graph using IMDB Actor-Movie Pairs");
		    
		// Get a List of ActorMovieIMDB objects from Bridges
		DataSource ds = bridges.getDataSource();
		List<ActorMovieIMDB> mylist = ds.getActorMovieIMDBData(1813);

		// Create empty graph
		GraphAdjListSimple<String> graph = new GraphAdjListSimple<String>();
		

		// TODO: You will build a graph that takes the actor-movie list (of 
  		// type ActorMoviIMDB) and build a graph that connects each actor to
  		// the corresponding movie and also the movie to the actor.
  		// Check the graph tutorial at 
  		// http://bridgesuncc.github.io/tutorials/Graph.html
  		// and the graph adjacency list documentation at
  		// http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_graph_adj_list.html
  		// for additional information

  		// Note: The actors and movies will occur multiple times. So before you 
  		// create a new movie or actor node, you must check if it has already 
  		// been created. You can use the getVertex() method to check to see if
  		// if an actor or movie exists in the graph (will return nullptr otherwise)


  		// IMDB graph has been created, give it to BRIDGES and visualize
		// bridges.setDataStructure(graph);
		// bridges.visualize();
	}
}
