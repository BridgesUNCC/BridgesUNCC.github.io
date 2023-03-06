#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"
#include "ColorGrid.h"
#include <sstream>
#include <string>

using namespace bridges;

// This program fragment illustrates how to access and retrieve the song lyrics data
int main(int argc, char* argv[]) {

	//create the Bridges object, set credentials
	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("Accessing Song Data");

	// create data source object
	DataSource ds (&bridges);

	// Get Song data
	Song s = ds.getSong("Harder Faster Better Stronger", "Daft Punk");

	// print lyrics
	std::cout << s.getLyrics() << std::endl;

	return 0;
}
