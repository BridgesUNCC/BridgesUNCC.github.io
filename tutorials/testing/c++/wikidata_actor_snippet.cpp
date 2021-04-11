
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

	// print the count of the records in 1955
	cout << "Data Records in 1955: " << v.size() << "\n";
	
	// print out the first 3 records of the dataset
	
	for (int k = 0; k < 3; k++)
		cout << "Actor-Movie Data:" << endl
	     << "\tMovie: " << v[k].getMovieURI() << " \""<<v[k].getMovieName()<< "\"\n"
	     << "\tActor: " << v[k].getActorURI() << " \""<<v[k].getActorName() << "\"\n";

	return 0;
}

