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
		
		for (ActorMovieIMDB pair : mylist) {
		    
			String actor = pair.getActor();
			String movie = pair.getMovie();
			
			// check if actor or movie exists, if not add
		    if (graph.getVertex(actor) == null) //avoid multi insertion
				graph.addVertex(actor, actor);

		    if (graph.getVertex(pair.getMovie()) == null)
				graph.addVertex(movie, movie);

			// add edges both ways
		    graph.addEdge(actor, movie);
		    graph.addEdge(movie, actor);

			// styling two actors and the links to their movies
			if (actor.equals("Cate_Blanchett")) {
				graph.getVisualizer (actor).setColor ("red");
				graph.getLinkVisualizer (actor, movie).setColor ("red");
				graph.getVisualizer (movie).setColor ("red");
			}
			if (actor.equals("Kevin_Bacon_(I)")) {
				graph.getVisualizer (actor).setColor ("green");
				graph.getLinkVisualizer (actor, movie).setColor ("green");
				graph.getVisualizer (movie).setColor ("green");
			}
		}


		// push to server
		bridges.setDataStructure(graph);
		bridges.visualize();
	}
}
