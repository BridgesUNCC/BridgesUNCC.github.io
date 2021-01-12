#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

// This tutorial creates a number of BRIDGES doubly linked list elements, 
// links them into a list and displays them

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A doubly Linked List Example");

	// set description
	bridges.setDescription("Create a doubly linked  list of five nodes and display it");


	// create the nodes
	DLelement<string>  *el0 = new DLelement<string> ("Gretel Chaney");
	DLelement<string>  *el1 = new DLelement<string> ("Lamont Kyler");
	DLelement<string>  *el2 = new DLelement<string> ("Gladys Serino");
	DLelement<string>  *el3 = new DLelement<string> ("Karol Soderman");
	DLelement<string>  *el4 = new DLelement<string> ("Starr McGinn");

	// set the names to be the label (for seeing it in the visualization)
	el0->setLabel("Gretal Chaney");
	el1->setLabel("Lamont Kyler");
	el2->setLabel("Gladys Serino");
	el3->setLabel("Karol Soderman");
	el4->setLabel("Starr McGinn");

	// create the list
	el0->setNext(el1);
	el1->setPrev(el0);
	el1->setNext(el2);
	el2->setPrev(el1);
	el2->setNext(el3);
	el3->setPrev(el2);
	el3->setNext(el4);
	el4->setPrev(el3);


	// provide BRIDGES the head of the list
	bridges.setDataStructure(el0);

	// visualize
	bridges.visualize();

	// cleanup
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
		
	return 0;
}
