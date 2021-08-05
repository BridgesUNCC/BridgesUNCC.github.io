import java.lang.String;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Amenities;
import bridges.data_src_dependent.AmenityData;

public class osm_amenity_snippet {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("An Open Street Map Example");

		// get the OSM data
		DataSource ds = bridges.getDataSource();
		AmenityData amenity_data = ds.getAmenityData(38.77657, -77.20918, 39.03198, -76.8999, "food");

		System.out.println("Total Points: " + amenity_data.getCount());
		System.out.println("ID: " + amenity_data.getAmenities().get(0).getId());
		System.out.println("Name: " + amenity_data.getAmenities().get(0).getName());
		System.out.println("Lat: " + amenity_data.getAmenities().get(0).getLat());
		System.out.println("Lon: " + amenity_data.getAmenities().get(0).getLon());

	}
}
