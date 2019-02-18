#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include "BSTElement.h"
#include "BST.h"


using namespace bridges;


int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");


	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";

								// read the earth quake  data and build the BST

	bridges->setTitle("BST Example: IMDB Data");
    vector<ActorMovieIMDB> actor_list = DataSource::getActorMovieIMDBData2(10);

	BST<string, string> *bst = new BST<string, string> ();

	cout << "Size:" << actor_list.size() << endl;

					// store actors in a map and store all their movies 
	unordered_map<string, string> act_map; 
	for (int k = 0; k < actor_list.size(); k++) {
		ActorMovieIMDB a = actor_list[k];

		string actor = a.getActor(), movie = a.getMovie();
		if (act_map.find(actor) != act_map.end()) 
			act_map[actor] = act_map[actor] + "\\n" + movie + "  [Rating :" + to_string(a.getMovieRating()) + " ]";
		else 
			act_map[actor] = movie + "  [Rating :" + to_string(a.getMovieRating()) + " ]";  
	}
	for (auto& k : act_map) 
		bst->insert(k.first, k.second);

					// visualize the binary search tree
	bridges->setDataStructure(bst->getRoot());
	bridges->visualize();

	return 0;
}
