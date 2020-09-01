import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_alist {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
		bridges.setDescription("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
			+	"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");

		DataSource ds = bridges.getDataSource();
		ArrayList<ActorMovieIMDB>  actor_movie_data =
			(ArrayList<ActorMovieIMDB>) ds.getActorMovieIMDBData(1813);


		// create an adjacency list based graph
		GraphAdjListSimple<String> g = new GraphAdjListSimple<String>();

		// first create vertices for two actors and add them to the graph
		String kevin_bacon = "Kevin_Bacon_(I)", denzel_washington = "Denzel_Washington";
		g.addVertex(kevin_bacon, "");
		g.addVertex(denzel_washington, "");

		// color the two actor nodes
		g.getVertex(kevin_bacon).setColor("red");
		g.getVertex(kevin_bacon).setSize(30);
		g.getVertex(denzel_washington).setColor("red");
		g.getVertex(denzel_washington).setSize(30);

		// add an edge between the two actors kevin_bacon and denzel_washington,
		// the third parameter is the edge weight
		g.addEdge(kevin_bacon, denzel_washington);
		g.getLinkVisualizer(kevin_bacon, denzel_washington).setColor("magenta");
		g.getLinkVisualizer(kevin_bacon, denzel_washington).setThickness(4.0f);

		// get their nodes
		Element v1 = g.getVertex(kevin_bacon);
		Element v2 = g.getVertex(denzel_washington);

		// we will find the first 15 immediate neighbors of of the two actors
		// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor_movie_data.size(); k++) {
			// from the actor movie data, get an actor-movie pair
			String a = actor_movie_data.get(k).getActor();
			String m = actor_movie_data.get(k).getMovie();

			if (a.equals(kevin_bacon) && cnt1 < 15) {

				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(kevin_bacon, m);
				g.addEdge(m, kevin_bacon);

				// make the movie node a bit transparent
				g.getVertex(m).setOpacity(0.7f);
				cnt1++;
			}
			else if (a.equals(denzel_washington) && cnt2 < 15) {
				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(denzel_washington, m);
				g.addEdge(m, denzel_washington);
				// make the movie node a bit transparent
				g.getVertex(m).setOpacity(0.7f);
				cnt2++;
			}
		}

		// Next, we illustrate traversing the adjacency list and color the
		// movie nodes adjacent to the Kevin Bacon node.

		// first get the adjacency list for Kevin Bacon
		// traverse the adjacency list
		for (Edge<String, String> edge : g.outgoingEdgeSetOf(kevin_bacon)) {
			String from = edge.getFrom(), to = edge.getTo();
			if (!to.equals(denzel_washington))
				edge.setColor("turquoise");
		}
		for (Edge<String, String> edge : g.outgoingEdgeSetOf(denzel_washington)) {
			String from = edge.getFrom(), to = edge.getTo();
			if (!to.equals(kevin_bacon))
				edge.setColor("orange");
		}

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
