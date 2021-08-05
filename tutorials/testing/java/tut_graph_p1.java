import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;

// This tutorial will demonstrate how to build an adjacency list based graph
// using BRIDGES and display it.
// References: GraphAdjList classes

public class tut_graph_p1 {
	public static void main(String[] args) throws Exception {

		// initialize Bridges, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set a title
		bridges.setTitle("A Simple Adjacency list based Graph Example.");

		// set  description
		bridges.setDescription("Demonstrate how to create a graph with a few nodes and display it");

		// create an adjacency list based graph
		GraphAdjListSimple<String> graph = new GraphAdjListSimple<String>();

		// create some actor names to be added to the graph
		String  kevin_bacon = "Kevin Bacon",
				denzel_washington = "Denzel Washington",
				morgan_freeman = "Morgan Freeman",
				tom_cruise = "Tom Cruise",
				angelina_jolie = "Angelina Jolie",
				amy_adams = "Amy Adams",
				brad_pitt = "Brad Pitt";

		// add them to the graph
		graph.addVertex(kevin_bacon, kevin_bacon);
		graph.addVertex(denzel_washington, denzel_washington);
		graph.addVertex(morgan_freeman, morgan_freeman);
		graph.addVertex(tom_cruise, tom_cruise);
		graph.addVertex(angelina_jolie, angelina_jolie);
		graph.addVertex(amy_adams, amy_adams);
		graph.addVertex(brad_pitt, brad_pitt);

		// add edges
		graph.addEdge(kevin_bacon, denzel_washington);
		graph.addEdge(kevin_bacon, morgan_freeman);
		graph.addEdge(kevin_bacon, angelina_jolie);
		graph.addEdge(amy_adams, angelina_jolie);
		graph.addEdge(tom_cruise, amy_adams);
		graph.addEdge(angelina_jolie, brad_pitt);
		graph.addEdge(brad_pitt, denzel_washington);

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(graph);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
