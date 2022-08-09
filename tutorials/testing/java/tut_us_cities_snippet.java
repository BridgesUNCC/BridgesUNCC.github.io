import java.util.List;
import java.util.HashMap;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.City;

// This program fragment illustrates how to access the USGS earthquake data
public class tut_us_cities_snippet {
	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
		// read the earth quake  data and build the BST
		bridges.setTitle("Accessing US City Data)");

		DataSource ds = bridges.getDataSource();

		// Parameters to the query are through an unordered map
		// you may use any subset of parameters to filter the US city data
		// results will be filtered to satisfy all specified parameters
		// for example if you provide population ane elevation ranges, then only those
		// cities matching those ranges will be retrieved
		
		// Parameters include
		// population range - specify  min and max population values
		// elevation range - specify  min and max elevation values - note elevation can be
		//                  negative (below sealevel!
		// Lat/Long bounding box -- specified by minLatLong, maxLatLong pairs of values
		// state  - state name -- cities within that state will be retrieved
		// city   - city name  -- if it matches, it will be retrieved
		// limit  - limit the output to a specified number of cities
		// limit to at most  25 cities and population above 2M
		// - parameters are passed through a map

		// following example illustrates using the population, lat/long
		// and limit parameters to limit the cities returned

		// use a hashmap to specify the parameters to the query
		HashMap<String, String> map = new HashMap<String, String>();
			map.put ("min_pop", "200000");
			map.put ("max_pop", "1000000");
			map.put ("state", "NC");
			map.put ("limit", "25");

		// get the cities
		List<City> cities = ds.getUSCitiesData(map);
		System.out.println ("Upto 25 cities in North Carolina with population between 200K and 1M");

		// print the records
		System.out.println("US Cities Retrieved");
		for (int k = 0; k < cities.size(); k++)
			System.out.println ("\t" + cities.get(k).getCity() + 
				", " + cities.get(k).getState() + 
				":  Population: " + cities.get(k).getPopulation() + 
				", Elevation: " + cities.get(k).getElevation() + 
				", Lat/Long: " + cities.get(k).getLatitude() + "," +
						cities.get(k).getLongitude()
			);
	}
}
