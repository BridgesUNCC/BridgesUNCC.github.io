import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_map_test {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		// set a title for the visualization
		bridges.setTitle("Graphs with Map Overlays");

		// create an adjacency list based graph
		GraphAdjListSimple<String> g = new GraphAdjListSimple<String>();

		for (int i = 0; i < 10; i++) {
			g.addVertex("node" + i, "node" + i);
			if (i > 0) {
				g.addEdge("node" + i, "node" + (i - 1));
			}
		}

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

		// visualize SVG AlbersUSA map
		bridges.setCoordSystemType("albersusa");
		bridges.setMapOverlay(true);
		bridges.visualize();

		// visualize SVG World map
		bridges.setCoordSystemType("equirectangular");
		bridges.setMapOverlay(true);
		bridges.setTitle("SVG World Map");
		bridges.visualize();


		// CANVAS VERSIONS (add >100 nodes)
		for (int i = 10; i < 110; i++) {
			g.addVertex("node" + i, "node" + i);
			if (i > 0) {
				g.addEdge("node" + i, "node" + (i - 1));
			}
		}

		// fix a node over Charlotte, NC
		g.getVertex("node6").setLocation(-80.8431, 35.2271);
		g.getVertex("node6").setColor("red");

		// visualize Canvas AlbersUSA map
		bridges.setCoordSystemType("albersusa");
		bridges.setMapOverlay(true);
		bridges.setTitle("Canvas USA Map");
		bridges.visualize();

		// fix a node over London
		g.getVertex("node10").setLocation(-0.1278, 51.5074);
		g.getVertex("node10").setColor("red");

		// visualize Canvas World map
		bridges.setCoordSystemType("equirectangular");
		bridges.setMapOverlay(true);
		bridges.setTitle("Canvas World Map");
		bridges.visualize();
	}
}
