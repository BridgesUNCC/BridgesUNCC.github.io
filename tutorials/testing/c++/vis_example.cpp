
#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A Visualization Attributes Related Example Using Doubly Linked List");

	// set description

	// create some elements
	DLelement<string>  *el0 = new DLelement<string> ("element0", "Element 0");
	DLelement<string>  *el1 = new DLelement<string> ("element1", "Element 1");

	// create the list
	el0->setNext(el1);
	el1->setPrev(el0);

	// node properties

	// set color, size , shape for list elements - see the Color class for supported colors
	el0->setColor("red");
	el0->setSize(20.);
	el1->setShape(DIAMOND);

	// set node transparency
	el0->setOpacity (0.3f);

	// color the links - must specify a valid terminating element
	// color the link from el0 to el1
	el0->getLinkVisualizer(el1)->setColor("green");

	// color the link from el1 to el0, using rgb color 
	el1->getLinkVisualizer(el0)->setColor(Color(255, 0, 255));

	// adjust link thickness
	el0->getLinkVisualizer(el1)->setThickness(2.0f);
	el1->getLinkVisualizer(el0)->setThickness(4.0f);

	// set link label
	el0->getLinkVisualizer(el1)->setLabel("Link Label");

	bridges.setDataStructure(el0);
	bridges.visualize();

	//freeing memory
	delete el0;
	delete el1;
	
	return 0;
}
