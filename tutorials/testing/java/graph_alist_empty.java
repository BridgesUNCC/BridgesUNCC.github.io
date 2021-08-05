import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_alist_empty {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
		bridges.setDescription("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
			+	"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");

		// create an adjacency list based graph
		GraphAdjListSimple<String> g = new GraphAdjListSimple<String>();

		String kevin_bacon = "Kevin_Bacon_(I)", denzel_washington = "Denzel_Washington", noone = "NoOne";
		g.addVertex(kevin_bacon, "");
		g.addVertex(denzel_washington, "");
		g.addVertex(noone, "");

		g.addEdge(kevin_bacon, denzel_washington);

		for (Edge<String, String> edge : g.outgoingEdgeSetOf(kevin_bacon)) {
			String from = edge.getFrom(), to = edge.getTo();
		}

		for (Edge<String, String> edge : g.outgoingEdgeSetOf(denzel_washington)) {
			String from = edge.getFrom(), to = edge.getTo();
		}

		for (Edge<String, String> edge : g.outgoingEdgeSetOf(noone)) {
			String from = edge.getFrom(), to = edge.getTo();
		}


	}
}
