import java.lang.String;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.OsmData;
import bridges.data_src_dependent.OsmVertex;

public class osm {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("An Open Street Map Example");

		// get the OSM data
		DataSource ds = bridges.getDataSource();
		OsmData  osm_data = ds.getOsmData(35.28, -80.75, 35.32, -80.71);
		//		OsmData osm_data = ds.getOsmData(41.03133177632377, -98.02593749997456,
		//							42.008577297430456, -97.94531249997696);


		// get the graph of this dataset
		GraphAdjList<Integer, OsmVertex, Double> graph = osm_data.getGraph();

		// use webgl for rendering this large graph
		graph.forceLargeVisualization(true);

		bridges.setDataStructure(graph);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
