
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/MovieActorWikidata.h"

using namespace bridges;

// This program fragment illustrates how to access and read the Wikidata actor/movie data
int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("Accessing Wikidata Movie/Actor Data");

	// create data source object
	DataSource ds (&bridges);

	// get the actor movie Wikidata data through the BRIDGES API for 1955.
	// data are available from the early 20th century to now.
	std::vector<MovieActorWikidata> v = ds.getWikidataActorMovie(1955, 1955);

	// print out the first record of the dataset
	cout << "Actor-Movie Data:" << endl
	     << "\tMovie: " << v[0].getMovieURI() << " \""<<v[0].getMovieName()<< "\"\n"
	     << "\tActor: " << v[0].getActorURI() << " \""<<v[0].getActorName() << "\"\n";

	return 0;
}

