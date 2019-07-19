
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

int main(int argc, char **argv) {
		
	// Initialize BRIDGES with your credentials
    Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");

    // set title for visualization
	bridges.setTitle("Accessing IMDB Data");


	// create data source object
	DataSource ds (&bridges);

	// get the actor movie IMDB data through the BRIDGES API
	vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1814);

	// print out the first record of the dataset

	cout << "Actor-Movie Data:" << endl 
		<< "\tActor: " << actor_list[0].getActor() << endl 
		<< "\tMovie: " << actor_list[0].getMovie() << endl;

	return 0;
}

