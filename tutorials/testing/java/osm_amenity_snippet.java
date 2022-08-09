import java.lang.String;
import java.util.Vector;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Amenity;

public class osm_amenity_snippet {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("An Open Street Map Example");

		// get the OSM data
		DataSource ds = bridges.getDataSource();
		Vector<Amenity>  amenities = ds.getAmenityData(38.77657, -77.20918, 39.03198, -76.8999, "food");

		System.out.println("Printing the first 5 amenities..");
		for (int k = 0; k < 5; k++) {
			System.out.println("\tID: " + amenities.get(k).getId());
			System.out.println("\tName: " + amenities.get(k).getName());
			System.out.println("\tLat: " + amenities.get(k).getLat());
			System.out.println("\tLon: " + amenities.get(k).getLon());
		System.out.println("\n");
		}

	}
}
