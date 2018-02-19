#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "BinTreeElement.h"

using namespace bridges;

int main() {


	Bridges::initialize(9, "kalpathi60", "486749122386"); 
//	Bridges::initialize(9, "bridges_public", "997924677918");

	BinTreeElement<string> *tle0 = new BinTreeElement<string>("10", "10");
	BinTreeElement<string> *tle1 = new BinTreeElement<string>("5", "5");
	BinTreeElement<string> *tle2 = new BinTreeElement<string>("3", "3");
	BinTreeElement<string> *tle3=  new BinTreeElement<string>("20","20");

	tle0->setLeft(tle1);
	tle0->setRight(tle3);
	tle1->setLeft(tle2);
	tle0->getVisualizer()->setColor(Color("red"));
	tle1->getVisualizer()->setColor(Color("green"));
	tle2->getVisualizer()->setColor(Color("blue"));
	tle3->getVisualizer()->setColor(Color("yellow"));

	tle0->getLinkVisualizer(tle1)->setColor(Color("red"));
	tle1->getLinkVisualizer(tle2)->setColor(Color("green"));
	tle0->getLinkVisualizer(tle3)->setColor(Color("blue"));

	Bridges::setTitle("Binary Tree Example");
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(tle0);


	Bridges::visualize();

	return 0;
}
