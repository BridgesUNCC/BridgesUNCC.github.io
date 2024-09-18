#include "Bridges.h"
#include "DataSource.h"
#include <iostream>
#include <string>
#include "data_src/ElevationData.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	//create the Bridges object, set credentials

	DataSource ds;
	dataset::ElevationData elev_data;

	// Get a List of Elevation data  records from Bridges
	try {
		elev_data = ds.getElevationData(41.03133177632377, -98.02593749997456, 
					42.508577297430456, -96.94531249997696);
	}
	catch (std::string s) {
		std::cerr << "Exception: " << s << "\n";
	}
	catch (char const* s) {
		std::cerr << "Exception: " << s << "\n";
	}

	
	// print the data dimensions  and the firs 10 elevation data values
	cout << "\tWidth: " << elev_data.getCols() << endl
		<< "\tHeight: " << elev_data.getRows() << endl
		<< "\tCell Size: " << elev_data.getCellSize() << endl
		<< "\tLower Left Corner: "  << elev_data.getxll()  << 
				 ", " <<  elev_data.getyll() <<endl;

	cout << "The first 10 elevation values.." << endl;
	for (int k = 0; k < 10; k++)
		cout << elev_data.getVal(0, k) << "  " << endl;
	cout << endl;

	return 0;
}
