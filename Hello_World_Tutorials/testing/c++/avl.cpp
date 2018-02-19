#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "AVLTreeElement.h"

#define LOCAL_SERVER 0

using namespace bridges;

int main() {


	Bridges::initialize(11, "kalpathi60", "486749122386"); 
//	Bridges::initialize(11, "bridges_public", "997924677918");

	AVLTreeElement<int, string> *tle0 = 
				new AVLTreeElement<int, string>(10, "10", "10");
	AVLTreeElement<int, string> *tle1 = 
				new AVLTreeElement<int, string>(5, "5", "5");
	AVLTreeElement<int, string> *tle2 = 
				new AVLTreeElement<int, string>(3, "3", "3");
	AVLTreeElement<int, string> *tle3=  
				new AVLTreeElement<int, string>(20, "20","20");

					 //  link the nodes
	tle0->setLeft(tle1);
	tle0->setRight(tle3);
	tle1->setLeft(tle2);

					// set attributes
	tle0->getVisualizer()->setColor(Color("red"));
	tle1->getVisualizer()->setColor(Color("green"));
	tle2->getVisualizer()->setColor(Color("blue"));
	tle3->getVisualizer()->setColor(Color("yellow"));

	tle0->getLinkVisualizer(tle1)->setColor(Color("red"));
	tle1->getLinkVisualizer(tle2)->setColor(Color("green"));
	tle0->getLinkVisualizer(tle3)->setColor(Color("blue"));

					// illustrate balance factors in the node labels
	tle0->setBalanceFactor(-1);
	tle1->setBalanceFactor(-1);
	tle2->setBalanceFactor(0);
	tle3->setBalanceFactor(0);

					// display the balance factors (on mouseover)
	tle0->setLabel(std::to_string(tle0->getBalanceFactor()));
	tle1->setLabel(std::to_string(tle1->getBalanceFactor()));
	tle2->setLabel(std::to_string(tle2->getBalanceFactor()));
	tle3->setLabel(std::to_string(tle3->getBalanceFactor()));

	Bridges::setTitle("AVL Tree Example");
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(tle0);


	Bridges::visualize();

	return 0;
}
