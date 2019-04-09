import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_al {
	public static void main(String[] args) throws Exception {

					// initialize Bridges
		Bridges<String, String> bridges = 
				new Bridges<String, String>(12, "YOUR_API_KEY", "YOUR_USER_ID");

					// set a title for the visualization
		bridges.setTitle("A Simple Graph Example using IMDB Actor/Movie Data");

		ArrayList<ActorMovieIMDB>  actor_movie_data = 
				(ArrayList<ActorMovieIMDB>) bridges.getActorMovieIMDBData("IMDB", 1800);

					// create an adjacency list based graph
		GraphAdjList<String, String> g = new GraphAdjList<String, String>();

					// first create vertices for two actors and add them to the graph
		String a1 = "Kevin_Bacon_(I)", a2 = "Denzel_Washington";
		g.addVertex(a1, ""); g.addVertex(a2, "");

					// add an edge between the two actors a1 and a2,  
					// the third parameter is the edge weight
		g.addEdge(a1, a2, 1);

					// color the two actor nodes
		g.getVertices().get("Kevin_Bacon_(I)").getVisualizer().setColor("red");
		g.getVertices().get("Denzel_Washington").getVisualizer().setColor("red");
					// make them a bit bigger
		g.getVertices().get("Kevin_Bacon_(I)").getVisualizer().setSize(20);
		g.getVertices().get("Denzel_Washington").getVisualizer().setSize(20);

					// get their nodes
		Element v1 = g.getVertices().get(a1);
		Element v2 = g.getVertices().get(a2);

					// we will find the first 15 immediate neighbors of of the two actors 
					// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor_movie_data.size(); k++) {
				// from the actor movie data, get an actor-movie pair
			String a = actor_movie_data.get(k).getActor();
			String m = actor_movie_data.get(k).getMovie();
	
			if (a.equals("Kevin_Bacon_(I)") && cnt1 < 15) {
	
					// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a1, m, 1); g.addEdge(m, a1, 1);

					// make the movie node a bit transparent
				g.getVertices().get(m).getVisualizer().setOpacity(0.5f);
				cnt1++;
			}
			else if (a.equals("Denzel_Washington") && cnt2 < 15){
						// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a2, m, 1); g.addEdge(m, a2, 1);
						// make the movie node a bit transparent
				g.getVertices().get(m).getVisualizer().setOpacity(0.5f);
				cnt2++;
			}
		}

				// Next, we illustrate traversing the adacency list and color the 
				// movie nodes adjacent to the Kevin Bacon node.
	
				// first get the adjacency list for Kevin Bacon
		SLelement<Edge<String>>  head = g.getAdjacencyList().get("Kevin_Bacon_(I)");
				// traverse the adjacency list
		for (SLelement<Edge<String>> sle = head; sle != null; sle = sle.getNext() ) {
					// get the terminating vertex
			String term_vertex = sle.getValue().getVertex();
					// find the corresponding element
			Element<String> el = g.getVertices().get(term_vertex);
					// set the  color of the node except the Denzel W. node
			if (!term_vertex.equals("Denzel_Washington"))
				el.getVisualizer().setColor("green");
		}

					// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

					// Finaly we call the visualize function
    	bridges.visualize();
	}
}
