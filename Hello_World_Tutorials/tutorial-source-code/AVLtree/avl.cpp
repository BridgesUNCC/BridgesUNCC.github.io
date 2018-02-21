#include <string>
#include "Bridges.h"
#include "AVLTreeElement.h"


using namespace std;
using namespace bridges;

int main() {


	Bridges::initialize(11, "YOUR_USER_ID", "YOUR_API_KEY"); 

	AVLTreeElement&lt;int, string&gt; *tle0 = 
				new AVLTreeElement&lt;int, string&gt;(10, "10", "10");
	AVLTreeElement&lt;int, string&gt; *tle1 = 
				new AVLTreeElement&lt;int, string&gt;(5, "5", "5");
	AVLTreeElement&lt;int, string&gt; *tle2 = 
				new AVLTreeElement&lt;int, string&gt;(3, "3", "3");
	AVLTreeElement&lt;int, string&gt; *tle3=  
				new AVLTreeElement&lt;int, string&gt;(20, "20","20");

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
