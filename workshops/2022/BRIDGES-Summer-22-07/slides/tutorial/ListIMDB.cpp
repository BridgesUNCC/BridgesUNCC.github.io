#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"


using namespace bridges;

int main() {
	//create the Bridges object, set credentials
	Bridges bridges(1, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
	bridges.setTitle("Singly Liked List using IMDB Actor Movie Data");
	DataSource ds;
	std::vector< ActorMovieIMDB > am_list = ds.getActorMovieIMDBData(100);
	//building linked list
	SLelement<ActorMovieIMDB>* head = nullptr;
	for (auto im : am_list) {
		SLelement<ActorMovieIMDB>* am_node = new SLelement<ActorMovieIMDB> (
			im, im.getActor() + " - " + im.getMovie());
		am_node->setNext(head);
		// style nodes related to Cary Grant
		if (im.getActor() == "Cary_Grant") {
			am_node->setColor(Color("cyan"));
			am_node->setSize(30.);
			am_node->setShape(SQUARE);
		}
		head = am_node;
	}
	// style beginning node of list
	head->setColor(Color("red"));
	head->setSize(49.0);
	// send data structure to server, visualize
	bridges.setDataStructure(head);
	bridges.visualize();

	return 0;
}
