
#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"


using namespace bridges;

int max_quakes = 100;

// This program fragment illustrates how to access the USGS earthquake data
int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
	// set title
	bridges.setTitle("Accessing USGIS Earthquake Data (USGIS Data)");

	// read the earth quake  data
	DataSource ds (&bridges);
	vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(max_quakes);

	// print the first quake record
	for (int k = 0; k < 10; k++) {
		cout << "Earthquake " << k << ": \n";
		cout << "\tMagnitude:" << eq_list[0].getMagnitude() << endl
		<< "\tDate:" << eq_list[0].getDateStr() << endl
		<< "\tLocation: " <<  eq_list[0].getLocation() << endl
		<< "\tLat/Long:"  << eq_list[0].getLatit() << "," <<
		eq_list[0].getLongit() << endl;
	}


	return 0;
}
