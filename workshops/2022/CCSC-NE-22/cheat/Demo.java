import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;
import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;


public class Demo {
	public static void main(String[] args) throws Exception {
		//create the Bridges object
		Bridges bridges = new Bridges(1, "kalpathi60", "486749122386");

		bridges.setTitle("CCSC NE 2022 demo!!");
		bridges.setDescription("Let's go Hollywood");

		    
		// Get a List of ActorMovieIMDB objects from Bridges
		DataSource ds = bridges.getDataSource();
		List<ActorMovieIMDB> mylist = ds.getActorMovieIMDBData(1813);

		// Create empty graph
		GraphAdjListSimple<String> graph = new GraphAdjListSimple<String>();
		
		for (ActorMovieIMDB pair : mylist) {
		    System.out.println(pair.getActor());
		    System.out.println(pair.getMovie());
		    
		    if (graph.getVertex(pair.getActor()) == null) //avoid multi insertion
			graph.addVertex(pair.getActor(), pair.getActor());

		    if (graph.getVertex(pair.getMovie()) == null)
			graph.addVertex(pair.getMovie(), pair.getMovie());

		    graph.addEdge(pair.getActor(), pair.getMovie());
		}

		// Let's get styling
		graph.getVertex("James_Earl_Jones").setShape("square");
		graph.getVertex("James_Earl_Jones").setSize(49);
		graph.getVertex("James_Earl_Jones").setColor("red");
		graph.getLinkVisualizer("James_Earl_Jones", "City_Limits_(1985)").setColor("orange");
		graph.getLinkVisualizer("James_Earl_Jones", "City_Limits_(1985)").setThickness(10.);

		// push to server
		bridges.setDataStructure(graph);
		bridges.visualize();
	}
}
