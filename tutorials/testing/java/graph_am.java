import java.util.ArrayList;
import java.lang.String;
import java.util.Map;
import java.util.HashMap;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjMatrixSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_am {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		//  title, description
		bridges.setTitle("A Simple Graph (Adjacency Matrix)  Example using IMDB Actor/Movie Data");
		bridges.setDescription("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
			+	"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");

		DataSource ds = bridges.getDataSource();
		ArrayList<ActorMovieIMDB>  actor_movie_data =
			(ArrayList<ActorMovieIMDB>) ds.getActorMovieIMDBData(1813);

		// create an adjacency matrix based graph
		GraphAdjMatrixSimple<String> graph = new GraphAdjMatrixSimple<String>();

		// first create vertices for two actors and add them to the graph
		String a1 = "Kevin_Bacon_(I)", a2 = "Denzel_Washington";
		graph.addVertex(a1, "");
		graph.addVertex(a2, "");

		// add an edge between the two actors a1 and a2,
		// the third parameter is the edge weight
		graph.addEdge(a1, a2, 1);

		// color the two actor nodes
		graph.getVertices().get("Kevin_Bacon_(I)").setColor("red");
		graph.getVertices().get("Denzel_Washington").setColor("red");

		// make them a bit bigger
		graph.getVisualizer("Kevin_Bacon_(I)").setSize(20);
		graph.getVisualizer("Denzel_Washington").setSize(20);

		// we will find the first 15 immediate neighbors of of the two actors
		// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor_movie_data.size(); k++) {
			// from the actor movie data, get an actor-movie pair
			String a = actor_movie_data.get(k).getActor();
			String m = actor_movie_data.get(k).getMovie();

			if (a.equals("Kevin_Bacon_(I)") && cnt1 < 15) {

				// add vertices for this movie  and an edge for the link
				graph.addVertex(m, "");
				graph.addEdge(a1, m, 1);
				graph.addEdge(m, a1, 1);

				// make the movie node a bit transparent
				graph.getVisualizer(m).setOpacity(0.5f);
				cnt1++;
			}
			else if (a.equals("Denzel_Washington") && cnt2 < 15) {
				// add vertices for this movie  and an edge for the link
				graph.addVertex(m, "");
				graph.addEdge(a2, m, 1);
				graph.addEdge(m, a2, 1);
				// make the movie node a bit transparent
				graph.getVisualizer(m).setOpacity(0.5f);
				cnt2++;
			}
		}

		// Next, we illustrate traversing the adacency list and color the
		// movie nodes adjacent to the Kevin Bacon node.

		// first get the adjacency list for Kevin Bacon
		HashMap<String, Integer> bacon_row =
			graph.getAdjacencyMatrix("Kevin_Bacon_(I)");
		for (Map.Entry<String, Integer> entry : bacon_row.entrySet()) {
			if (!entry.getKey().equals("Denzel_Washington") &&
				entry.getValue() != 0)
				graph.getVisualizer(entry.getKey()).setColor ("green");
		}
		// Pass the graph object to BRIDGES
		bridges.setDataStructure(graph);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
