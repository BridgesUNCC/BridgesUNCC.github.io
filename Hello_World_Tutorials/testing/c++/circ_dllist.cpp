#include <iostream>
#include <string>

#include "Bridges.h"
#include "CircDLelement.h"

using namespace std;
using namespace bridges;


int main() {
	Bridges::initialize(6, "kalpathi60", "486749122386");
//	Bridges::initialize(6, "bridges_public", "997924677918");

	Bridges::setTitle("An Example Circular Doubly Linked List");
						// create list nodes
	CircDLelement<int> *el0 = new CircDLelement<int>(0, "0");
	CircDLelement<int> *el1 = new CircDLelement<int>(1, "1");
	CircDLelement<int> *el2 = new CircDLelement<int>(2, "2");
	CircDLelement<int> *el3 = new CircDLelement<int>(3, "3");
       					// link nodes 
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el0);

	el0->setPrev(el3);
	el1->setPrev(el0);
	el2->setPrev(el1);
	el3->setPrev(el2);

						// set color of nodes
/*
	el0->getVisualizer()->setColor("red");
	el1->getVisualizer()->setColor("green");
	el2->getVisualizer()->setColor("blue");
	el3->getVisualizer()->setColor("yellow");
						// set link colors
	el0->getLinkVisualizer(el1)->setColor("cyan");
	el1->getLinkVisualizer(el2)->setColor("magenta");
	el2->getLinkVisualizer(el3)->setColor("green");
						// set link thickness
	el0->getLinkVisualizer(el1)->setThickness(3);
*/
						// provide Bridges handle to data structure
	Bridges::setDataStructure(el0);
						// visualize the data structure
	Bridges::visualize();

	return 0;
}
