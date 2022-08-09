#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/City.h"

using namespace bridges;

// this program illustrates how to access the data of the US and World 
//	city data
int main(int argc, char **argv) {

	// create bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	// set title
	bridges.setTitle("Accessing US City data");

	DataSource ds (&bridges);

	cout << "Retrieving a set of US cities" << endl;

	// Parameters to the query are through an unordered map
	// you may use any subset of parameters to filter the US city data
	// results will be filtered to satisfy all specified parameters
	// for example if you provide population ane elevation ranges, then only those
	// cities matching those ranges will be retrieved

	// Parameters include
	// population range - specify  min and max population values
	// elevation range - specify  min and max elevation values - note elevation can be
	//   				negative (below sealevel!
	// Lat/Long bounding box -- specified by minLatLong, maxLatLong pairs of values
	// state  - state name -- cities within that state will be retrieved
	// city   - city name  -- if it matches, it will be retrieved
	// limit  - limit the output to a specified number of cities


	// output upto 25 cities of North carolina  with a population ranging from 200K to 1M

	unordered_map<string, string> city_params {
			{"min_pop","100000"}, 
			{"max_pop","1000000"}, 
			{"state", "NC"},
			{"min_lat", "35.025348"},
			{"min_long", "-85.352783"},
			{"max_lat", "36.800488"},
			{"max_long", "-75.300293"},
			{"limit", "25"}
		};

	vector<City>  us_cities = ds.getUSCities(city_params);
	cout << "US Cities : \n";
	for (auto c : us_cities)
		cout << "\n" << c.getCity() << "," << c.getState() << ":" << 
			" Population: " <<  c.getPopulation()  << 
			", Elevation: "  <<  c.getElevation()
			<< ", Lat/Long: " << c.getLatitude() << "," << c.getLongitude(); 

	cout << "\n";

	return 0;
}
