### Create a new .java file

### Imports

-   We need to include these Bridges files to give access to all the classes/methods needed to interact with Bridges
-   In your .java file, enter the following code snippets:

	import java.util.ArrayList;
	import java.lang.String;
	import bridges.base.Element;
	import bridges.base.SLelement;
	import bridges.base.GraphAdjList;
	import bridges.base.Edge;
	import bridges.connect.Bridges;
	import bridges.data\_src\_dependent.ActorMovieIMDB;

### Main Exception

-   By adding a throw exception we can forgo messy try/catch blocks in our code for our Bridges calls
-   In your .java file, add a throw exception to the main function so it looks like this:

	public static void main(String\[\] args) throws Exception

### Inside our Main

-   First we need to create our Bridges object and initialize our Bridges Credentials

	Bridges bridges = new Bridges(5, "YOUR\_USER\_ID", "YOUR\_API\_KEY");

**Note that you must replace the above strings with your BRIDGES credentials.**-   Then we can create our GraphAdjList

	GraphAdjList<String,String> g = new GraphAdjList<String, String>();

-   Set a title for the visualization.

			// set a title for the visualization
	bridges.setTitle("A Simple Graph Example using IMDB Actor/Movie Data");

-   We will illustrate an example graph using part of the IMDB actor-movie data. Specifically we will illustrate the movies in which Kevin Bacon and Denzel Washington appear. First we will retrieve the IMDB actor-movie dataset through the BRIDGES API; the returned ArrayList is used as the data source for this example

	ArrayList actor\_movie\_data =
		(ArrayList) bridges.getActorMovieIMDBData("IMDB", 1800);

-   Next we construct the graph creating nodes for the two actors and retrieving the movies they appear in, which are also nodes connected to the actors.

			// create an adjacency list based graph
	GraphAdjList<String, String> g = new GraphAdjList<String, String>();

			// first create vertices for two actors and add them to the graph
	String a1 = "Kevin\_Bacon\_(I)", a2 = "Denzel\_Washington";
	g.addVertex(a1, ""); g.addVertex(a2, "");

			// add an edge between the two actors a1 and a2,
			// the third parameter is the edge weight
	g.addEdge(a1, a2, 1);

			// color the two actor nodes
	g.getVertices().get("Kevin\_Bacon\_(I)").getVisualizer().setColor("red");
	g.getVertices().get("Denzel\_Washington").getVisualizer().setColor("red");
			// make them a bit bigger
	g.getVertices().get("Kevin\_Bacon\_(I)").getVisualizer().setSize(20);
	g.getVertices().get("Denzel\_Washington").getVisualizer().setSize(20);

			// get their nodes
	Element v1 = g.getVertices().get(a1);
	Element v2 = g.getVertices().get(a2);

			// we will find the first 15 immediate neighbors of of the two actors
			// and color those links and nodes by followng their adjacency lists
	int cnt1 = 0, cnt2 = 0;
	for (int k = 0; k < actor\_movie\_data.size(); k++) {
			// from the actor movie data, get an actor-movie pair
		String a = actor\_movie\_data.get(k).getActor();
		String m = actor\_movie\_data.get(k).getMovie();

		if (a.equals("Kevin\_Bacon\_(I)") && cnt1 < 15) {

				// add vertices for this movie  and an edge for the link
			g.addVertex(m, "");
			g.addEdge(a1, m, 1); g.addEdge(m, a1, 1);

				// make the movie node a bit transparent
			g.getVertices().get(m).getVisualizer().setOpacity(0.5f);
			cnt1++;
		}
		else if (a.equals("Denzel\_Washington") && cnt2 < 15){
					// add vertices for this movie  and an edge for the link
			g.addVertex(m, "");
			g.addEdge(a2, m, 1); g.addEdge(m, a2, 1);
					// make the movie node a bit transparent
			g.getVertices().get(m).getVisualizer().setOpacity(0.5f);
			cnt2++;
		}
	}

-   Next, we illustrate traversing the adacency list and color the movie nodes adjacent to the Kevin Bacon node.

				// first get the adjacency list for Kevin Bacon
	SLelement<Edge<String>>  head = g.getAdjacencyList().get("Kevin\_Bacon\_(I)");
				// traverse the adjacency list
	for (SLelement<Edge<String>> sle = head; sle != null; sle = sle.getNext() ) {
				// get the terminating vertex
		String term\_vertex = sle.getValue().getVertex();
				// find the corresponding element
		Element<String> el = g.getVertices().get(term\_vertex);
				// set the  color of the node except the Denzel W. node
		if (!term\_vertex.equals("Denzel\_Washington"))
			el.getVisualizer().setColor("green");
	}

-   Pass the graph object to BRIDGES

	bridges.setDataStructure(g);

-   Finaly we call the visualize function

    bridges.visualize();

-   Summary. Here is the full source to the example

import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.data\_src\_dependent.ActorMovieIMDB;

public class graph\_al {
	public static void main(String\[\] args) throws Exception {

					// initialize Bridges
		Bridges bridges = new Bridges(12, "YOUR\_API\_KEY", "YOUR\_USER\_ID");

					// set a title for the visualization
		bridges.setTitle("A Simple Graph Example using IMDB Actor/Movie Data");

		ArrayList<ActorMovieIMDB>  actor\_movie\_data =
				(ArrayList<ActorMovieIMDB>) bridges.getActorMovieIMDBData("IMDB", 1800);

					// create an adjacency list based graph
		GraphAdjList<String, String> g = new GraphAdjList<String, String>();

					// first create vertices for two actors and add them to the graph
		String a1 = "Kevin\_Bacon\_(I)", a2 = "Denzel\_Washington";
		g.addVertex(a1, ""); g.addVertex(a2, "");

					// add an edge between the two actors a1 and a2,
					// the third parameter is the edge weight
		g.addEdge(a1, a2, 1);

					// color the two actor nodes
		g.getVertices().get("Kevin\_Bacon\_(I)").getVisualizer().setColor("red");
		g.getVertices().get("Denzel\_Washington").getVisualizer().setColor("red");
					// make them a bit bigger
		g.getVertices().get("Kevin\_Bacon\_(I)").getVisualizer().setSize(20);
		g.getVertices().get("Denzel\_Washington").getVisualizer().setSize(20);

					// get their nodes
		Element v1 = g.getVertices().get(a1);
		Element v2 = g.getVertices().get(a2);

					// we will find the first 15 immediate neighbors of of the two actors
					// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor\_movie\_data.size(); k++) {
				// from the actor movie data, get an actor-movie pair
			String a = actor\_movie\_data.get(k).getActor();
			String m = actor\_movie\_data.get(k).getMovie();
	
			if (a.equals("Kevin\_Bacon\_(I)") && cnt1 < 15) {
	
					// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a1, m, 1); g.addEdge(m, a1, 1);

					// make the movie node a bit transparent
				g.getVertices().get(m).getVisualizer().setOpacity(0.5f);
				cnt1++;
			}
			else if (a.equals("Denzel\_Washington") && cnt2 < 15){
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
		SLelement<Edge<String>>  head = g.getAdjacencyList().get("Kevin\_Bacon\_(I)");
				// traverse the adjacency list
		for (SLelement<Edge<String>> sle = head; sle != null; sle = sle.getNext() ) {
					// get the terminating vertex
			String term\_vertex = sle.getValue().getVertex();
					// find the corresponding element
			Element<String> el = g.getVertices().get(term\_vertex);
					// set the  color of the node except the Denzel W. node
			if (!term\_vertex.equals("Denzel\_Washington"))
				el.getVisualizer().setColor("green");
		}

					// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

					// Finaly we call the visualize function
    	bridges.visualize();
	}
}