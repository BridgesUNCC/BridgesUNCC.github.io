#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/CancerIncidence.h"

using namespace bridges;

// This program fragment illustrates how to access the IGN Game data
int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("How to access the IGN Game Data");

	// read the IGN game data
	DataSource ds (&bridges);
	vector<CancerIncidence> ca = ds.getCancerIncidenceData();

	cout << ca.size() << "\n";

	// Print a single record of the data for illustration
	cout << "Incident 0:" << endl;
	CancerIncidence& c = ca[0];

	cout << "\tType: " << c.getEventType() << "\n"
		<< "\tYear: " << c.getYear() << "\n"
		<< "\tPopulation: " << c.getPopulation() << "\n"
		<< "\tRace: " << c.getRace() << "\n"
		<< "\tGender: " << c.getGender() << "\n"
		<< "\tCrudeRate: " << c.getCrudeRate() << "(more rate information available) \n"
		<< "\tLocation: " << c.getLocationX() << ", " << c.getLocationY() << "\n"
		<< "\tCount: " << c.getCount() << endl;

	return 0;
}
