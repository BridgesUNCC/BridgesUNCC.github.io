#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"


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
	vector<Game> game_list = ds.getGameData();

	// Print a single record of the data for illustration
	cout << "Game 0:" << endl;
	cout << "\tTitle: " << game_list[0].getTitle() << endl
		<< "\tPlatform Type: " << game_list[0].getPlatformType() << endl
		<< "\tRating: " << game_list[0].getRating() << endl <<
		"\tGenres: ";
	for (auto& s : game_list[0].getGameGenre())
		cout << s << "," << endl;

	return 0;
}
