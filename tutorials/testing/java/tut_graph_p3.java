import java.util.ArrayList;
import java.util.Iterator;
import java.lang.String;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;

// In Part 3 of this tutorial will demonstrate some advanced features
// of adjacency list // based graphs in BRIDGES, such as graph traversal
// and iterators that make it more convenient.
//
// We will continue using the same graph of actors
//
// References: GraphAdjList class

public class tut_graph_p3 {
	public static void main(String[] args) throws Exception {

		// initialize Bridges, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set a title
		bridges.setTitle("A Simple Adjacency list based Graph Example.");

		// set  description
		bridges.setDescription("Demonstrate advanced features of graphs, traversal of adjacency lists, use of iterators");

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

		// Next, we illustrate traversing the adacency list  in different ways

		// using core BRIDGES classes to print the movies that Kevin Bacon is adjacent to
		System.out.println("Using core Bridges classes:");
		for (SLelement<Edge<String, String>> sle =
				graph.getAdjacencyList(kevin_bacon);
			sle != null; sle = sle.getNext()) {
			Edge<String, String> edge = sle.getValue();
			System.out.println("\t" + edge.getFrom() +  " --> " +  edge.getTo() );
		}

		// using iterators to print the movies Kevin Bacon is adjacent to
		System.out.println("Using iterators");
		for (Edge<String, String> edge : graph.outgoingEdgeSetOf(kevin_bacon)) {
			System.out.println("\t" + edge.getFrom() + "-->" + edge.getTo());
		}

		// finally, list the vertices of the graph, using iterators
		System.out.println("Using iterators to print the graph vertices[Method 1]:");
		Iterator it = graph.getVertices().keySet().iterator();
		while (it.hasNext())
			System.out.println("\t" + it.next());

		System.out.println("Using iterators to print the graph vertices[Method 2]:");
		for (String actor : graph.getVertices().keySet())
			System.out.println("\t" + actor);

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(graph);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
