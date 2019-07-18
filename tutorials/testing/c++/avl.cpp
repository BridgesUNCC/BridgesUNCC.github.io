#include <string>
#include "Bridges.h"
#include "AVLTreeElement.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
	// set title, description
	bridges.setTitle("AVL Tree Example");
	bridges.setDescription("This AVL tree has six elements.  The root is magenta color and has three nodes on its left and two nodes on its right. The values from lower left to the root, 20, 40, 30, 50. And from lower right to root, 90, 70, 50. The node labels also illustrate the balance factors");

	AVLTreeElement<int, string> *tle0 =
		new AVLTreeElement<int, string>(10, "10", "10");
	AVLTreeElement<int, string> *tle1 =
		new AVLTreeElement<int, string>(5, "5", "5");
	AVLTreeElement<int, string> *tle2 =
		new AVLTreeElement<int, string>(3, "3", "3");
	AVLTreeElement<int, string> *tle3 =
		new AVLTreeElement<int, string>(20, "20", "20");

	//  link the nodes
	tle0->setLeft(tle1);
	tle0->setRight(tle3);
	tle1->setLeft(tle2);

	// set attributes
	tle0->setColor("red");
	tle1->setColor("green");
	tle2->setColor("blue");
	tle3->setColor("yellow");

	tle0->getLinkVisualizer(tle1)->setColor("red");
	tle1->getLinkVisualizer(tle2)->setColor("green");
	tle0->getLinkVisualizer(tle3)->setColor("blue");

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

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(tle0);

	bridges.visualize();

	return 0;
}
