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

	AVLTreeElement<int, string> *avl_root =
		new AVLTreeElement<int, string>(50, "50", "50");
	AVLTreeElement<int, string> *tle1 =
		new AVLTreeElement<int, string>(30, "30", "30");
	AVLTreeElement<int, string> *tle2 =
		new AVLTreeElement<int, string>(70, "70", "70");
	AVLTreeElement<int, string> *tle3 =
		new AVLTreeElement<int, string>(20, "20", "20");
	AVLTreeElement<int, string> *tle4 =
		new AVLTreeElement<int, string>(40, "40", "40");
	AVLTreeElement<int, string> *tle5 =
		new AVLTreeElement<int, string>(90, "90", "90");

	//  link the nodes
	avl_root->setLeft(tle1);
	avl_root->setRight(tle2);
	tle1->setLeft(tle3);
	tle1->setRight(tle4);
	tle2->setRight(tle5);

	// set attributes
	avl_root->setColor("red");

	avl_root->getLinkVisualizer(tle1)->setColor("red");
	avl_root->getLinkVisualizer(tle2)->setColor("green");

	// illustrate balance factors in the node labels
	avl_root->setBalanceFactor(0);
	tle1->setBalanceFactor(0);
	tle2->setBalanceFactor(1);
	tle3->setBalanceFactor(0);
	tle4->setBalanceFactor(0);
	tle5->setBalanceFactor(0);

	// display the balance factors (on mouseover)
	avl_root->setLabel(std::to_string(avl_root->getBalanceFactor()));
	tle1->setLabel(std::to_string(tle1->getBalanceFactor()));
	tle2->setLabel(std::to_string(tle2->getBalanceFactor()));
	tle3->setLabel(std::to_string(tle3->getBalanceFactor()));
	tle4->setLabel(std::to_string(tle4->getBalanceFactor()));
	tle5->setLabel(std::to_string(tle5->getBalanceFactor()));

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(avl_root);

	bridges.visualize();

	return 0;
}
