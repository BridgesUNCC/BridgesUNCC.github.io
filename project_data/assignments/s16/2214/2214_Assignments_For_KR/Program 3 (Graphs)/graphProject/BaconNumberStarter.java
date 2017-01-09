import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map.Entry;
import java.lang.String;

import bridges.base.SLelement;
import bridges.base.Element;
import bridges.base.Edge;
import bridges.base.GraphAdjList;
import bridges.connect.Bridges;

/* *
 * 	BaconNumber Starter is the skeleton code for Program 3.0 in ITCS 2214
 * 	David Burlinson
 * 
 * 		As it stands, the program reads a datafile of IMDB actor/movie pairs and builds a graph
 * 		Students should closely follow the comments and pseudocode to implement the baconNumber method
 * 
 */
public class BaconNumberStarter {
	private static String FILE_NAME = "./large_imdb.txt";
	
	public static void main(String[] args) throws Exception {
		
		// initialize Bridges object and Bridges Graph
		Bridges bridges = new Bridges(,,);
		GraphAdjList<String, String>  graph_al = new GraphAdjList<String, String>();
			
		/* Read file and build graph */
		String line;	// holds line from file
		File f = new File(FILE_NAME);	// set up file
		BufferedReader reader = new BufferedReader(new FileReader(f));	// open reader 
		line = reader.readLine();

		while(line != null) {
			String[] actor_movie = line.split(" ");
			
			// insert actor if it doesn't exist
			if (!graph_al.getVertices().containsKey(actor_movie[0])) {
				graph_al.addVertex(actor_movie[0], actor_movie[0]);
			}
			// insert movie if it doesn't exist
			if (!graph_al.getVertices().containsKey(actor_movie[1])) {
				graph_al.addVertex(actor_movie[1], actor_movie[1]);
			}
			// link actor and movie
			graph_al.addEdge(actor_movie[0], actor_movie[1], 1);
			graph_al.addEdge(actor_movie[1], actor_movie[0], 1);

			line = reader.readLine();
		}

		// visualize graph
		bridges.setDataStructure(graph_al);
		bridges.visualize();

//		System.out.println("Distance is :" + baconNumber(graph_al, "Kevin_Bacon_(I)", "Denzel_Washington"));
//		
//		bridges.setDataStructure(graph_al);
//		bridges.visualize();

	}		
		
//	public static int baconNumber (GraphAdjList<String, String> graph, String src_actor, String dest_actor) {
		
//		HashMap<String, String> mark = new HashMap<>();		// store 'VISITED' or 'UNVISITED' for every vertex
//		HashMap<String, Integer> dist = new HashMap<>();	// store an integer distance for every vertex
//		HashMap<String, String> parent = new HashMap<>();	// store the name of the parent node for every vertex
		// for every vertex in the graph,
			// set vertex in mark as 'UNVISITED'
			// set vertex in dist as Integer.MAX_VALUE
			// set vertex in parent as "NONE"

//		LQueue<String> Q = new LQueue<String>();			// Facilitate breadth-first search
		
		// enqueue src_actor
		// mark src_actor as VISITED
		// set src_actor distance to 0
		
		
		// while queue Q contains values,
			// set v equal to the front of the queue (dequeue a vertex) 
			
			// for every vertex w reachable from v, 
				// set vertex w's color to show that the algorithm examines it
				
				// if mark for w is UNVISITED,
					// set mark for w as VISITED
					// enqueue w
					// set dist for w as (dist of v + 1)
					// set parent for w to be u

					// if w is the dest_actor, 
						// we've found the destination, now let's trace back the path
										
						// set child = dest_actor
						// while parent of child isn't NONE, 
							// set visual property of node to highlight shortest path
							// set parent = parent of child
							
							// if parent isn't NONE
								// set visual property of link between parent and child
						
	
						// return the distance for the dest_actor

		// return -1 for failure
	//}
}
