#include <iostream>
#include <string>

#include "Bridges.h"
#include "CircSLelement.h"

using namespace std;
using namespace bridges;


int main() {
	Bridges::initialize(5, "kalpathi60", "486749122386");
//	Bridges::initialize(5, "bridges_public", "997924677918");

	Bridges::setTitle("An Example Circular Linked List");
						// create list nodes
	CircSLelement<int> *el0 = new CircSLelement<int>(0, "0");
	CircSLelement<int> *el1 = new CircSLelement<int>(1, "1");
	CircSLelement<int> *el2 = new CircSLelement<int>(2, "2");
	CircSLelement<int> *el3 = new CircSLelement<int>(3, "3");
       					// link nodes 
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el0);

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
