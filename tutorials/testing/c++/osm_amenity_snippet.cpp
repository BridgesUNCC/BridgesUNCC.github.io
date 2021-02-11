#include "Bridges.h"
#include "DataSource.h"
#include <iostream>
#include <string>
#include "data_src/Amenities.h"
#include "data_src/AmenityData.h"

// An example illustrating how to extract amenity attributes from OpenStreetMap datasets
 
using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	DataSource ds(bridges);
	AmenityData amenity_data = ds.getAmenityData(38.77657, -77.20918, 39.03198, -76.8999, "food");
//	AmenityData amenity_data = ds.getAmenityData("Charlotte, North Carolina", "food");

	cout << "Total Amenities: " <<  amenity_data.getCount() << "\n";

	vector<Amenities> amenities = amenity_data.getAmenities();
	cout << "The first 5 amenities:\n";

	for (int k = 0; k < 5; k++) {
		cout << "[" << k <<  "]:\n";
		cout << "\tName: " <<  amenities[k].getName() << "\n";
		cout << "\tId: " <<  amenities[k].getId() << "\n";
		cout << "\tName: " <<  amenities[k].getName() << "\n";
		cout << "\tLatitude: " <<  amenities[k].getLat() << "\n";
		cout << "\tLongitude: " <<  amenities[k].getLon() << "\n";
	}
	
	return 0;
}
