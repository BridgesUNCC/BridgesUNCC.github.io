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
	bridges.setDescription("This AVL tree has six elements.  The root is magenta color and has three nodes on its left and two nodes on its right. The values from lower left to the root, 20, 40, 30, 50. And from lower right to root, 90, 70, 50. Hit the 'l' key to see the balance factors displayed at the nodes.");

	AVLTreeElement<int, string> *avl_root =
		new AVLTreeElement<int, string>(50, "50", "50");
	AVLTreeElement<int, string> *avl2 =
		new AVLTreeElement<int, string>(30, "30", "30");
	AVLTreeElement<int, string> *avl3 =
		new AVLTreeElement<int, string>(70, "70", "70");
	AVLTreeElement<int, string> *avl4 =
		new AVLTreeElement<int, string>(20, "20", "20");
	AVLTreeElement<int, string> *avl5 =
		new AVLTreeElement<int, string>(40, "40", "40");
	AVLTreeElement<int, string> *avl6 =
		new AVLTreeElement<int, string>(90, "90", "90");

	//  link the nodes
	avl_root->setLeft(avl2);
	avl_root->setRight(avl3 );
	avl2->setLeft(avl4);
	avl2->setRight(avl5);
	avl3->setRight(avl6);

	// set attributes
	avl_root->setColor("magenta");

	avl_root->getLinkVisualizer(avl2)->setColor("cyan");
	avl_root->getLinkVisualizer(avl3)->setColor("blue");

	// illustrate balance factors in the node labels
	avl_root->setBalanceFactor(0);
	avl2->setBalanceFactor(0);
	avl3->setBalanceFactor(1);
	avl4->setBalanceFactor(0);
	avl5->setBalanceFactor(0);
	avl6->setBalanceFactor(0);

	// display the balance factors (on mouseover)
	avl_root->setLabel(std::to_string(avl_root->getBalanceFactor()));
	avl2->setLabel(std::to_string(avl2->getBalanceFactor()));
	avl3->setLabel(std::to_string(avl3->getBalanceFactor()));
	avl4->setLabel(std::to_string(avl4->getBalanceFactor()));
	avl5->setLabel(std::to_string(avl5->getBalanceFactor()));
	avl6->setLabel(std::to_string(avl6->getBalanceFactor()));

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(avl_root);

	bridges.visualize();

	// deallocating memory
	
	delete avl_root;
	delete avl2;
	delete avl3;
	delete avl4;
	delete avl5;
	delete avl6;
	
	return 0;
}
