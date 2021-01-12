#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

// Part 2 of the tutorial illustrates styling features in a doubly linked list
// Uses the same list as part 1

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A doubly Linked List Example");

	// set description
	bridges.setDescription("Illustrates styling features in a doubly linked list");


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

	// link the elements, create the list
	el0->setNext(el1);
	el1->setPrev(el0);
	el1->setNext(el2);
	el2->setPrev(el1);
	el2->setNext(el3);
	el3->setPrev(el2);
	el3->setNext(el4);
	el4->setPrev(el3);

	// style the nodes and links in the list 

	// color the elements
	el0->setColor("red");
	el1->setColor("green");
	el2->setColor("blue");
	el3->setColor("cyan");
	el4->setColor("yellow");

	// element size
	el0->setSize(40);
	el1->setSize(40);

	// element opacity
	el1->setOpacity(0.2f);
	el3->setOpacity(0.2f);

	// shape
	el2->setShape(TRIANGLE);
	el3->setShape(SQUARE);

	// thickness
	el3->getLinkVisualizer(el4)->setThickness(6.0f);
    el4->getLinkVisualizer(el3)->setThickness(6.0f);

	// link color
	el3->getLinkVisualizer(el4)->setColor("orange");
    el4->getLinkVisualizer(el3)->setColor("orange");

	// link label
	el0->getLinkVisualizer(el1)->setLabel("Chaney-->Kyler");
	el1->getLinkVisualizer(el0)->setLabel("Kyler-->Chaney");


	// provide BRIDGES the head of the list
	bridges.setDataStructure(el0);

	// visualize -- hit the 'l' key in the visualization to see the labels
	bridges.visualize();

	// cleanup
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
		
	return 0;
}
