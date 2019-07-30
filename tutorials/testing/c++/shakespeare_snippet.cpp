#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Shakespeare.h"

using namespace bridges;


// This program fragment illustrates how to access and retrieve the Shakespeare data
int main(int argc, char **argv) {

	// create Bridges object

	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("Accessing Shakespeare Plays, Poems, Sonnets Dataset");

	// create a data source object
	DataSource ds (&bridges);

	// get the data
	vector<Shakespeare> shakespeare_data = ds.getShakespeareData();

	// print the first record
	cout << endl << "Shakespeare Data:" <<  endl <<
		"Title: " << shakespeare_data[0].getTitle()  <<  endl <<
		"Type: " << shakespeare_data[0].getType() <<  endl <<
		"Text: " << shakespeare_data[0].getText() << endl;


	return 0;
}
