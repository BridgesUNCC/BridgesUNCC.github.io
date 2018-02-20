#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "BSTElement.h"


using namespace bridges;

int main() {


	Bridges::initialize(10, "kalpathi60", "486749122386"); 
//	Bridges::initialize(10, "bridges_public", "997924677918");

	BSTElement<int, string> *tle0 = new BSTElement<int, string>(10, "10", "10");
	BSTElement<int, string> *tle1 = new BSTElement<int, string>(5, "5", "5");
	BSTElement<int, string> *tle2 = new BSTElement<int, string>(3, "3", "3");
	BSTElement<int, string> *tle3=  new BSTElement<int, string>(20, "20","20");
	BSTElement<int, string> *tle4=  new BSTElement<int, string>(1, "1","1");

	tle0->setLeft(tle1);
	tle0->setRight(tle3);
	tle1->setLeft(tle2);
	tle2->setLeft(tle4);

	tle0->getVisualizer()->setColor(Color("red"));
	tle1->getVisualizer()->setColor(Color("green"));
	tle2->getVisualizer()->setColor(Color("blue"));
	tle3->getVisualizer()->setColor(Color("yellow"));

	tle0->getLinkVisualizer(tle1)->setColor(Color("red"));
	tle1->getLinkVisualizer(tle2)->setColor(Color("green"));
	tle0->getLinkVisualizer(tle3)->setColor(Color("blue"));

	Bridges::setTitle("Binary Search Tree Example");
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(tle0);


	Bridges::visualize();

	return 0;
}
