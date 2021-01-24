
#include <string>
#include "Bridges.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;

// Part 2 of this tutorial will illustrate the use of the BRIDGES in styling
// nodes and links of binary search trees.  For instance you might want to
// illustrate the nodes and links that were visited during an insertion 
// operation. Or color the tree based on a particular type of traversal.

// We will use the same tree as in Part 1 and illustrate styling.

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title, description
	bridges.setTitle("A Simple  Binary Search Tree Example");
	bridges.setDescription("This example illustrates styling a binary search tree nodes and links using BRIDGES");

	// we will create the tree manually in this example

	// create the nodes
	BSTElement<int, string> *root = new BSTElement<int, string>(100);
	BSTElement<int, string> *node1 = new BSTElement<int, string>(50);
	BSTElement<int, string> *node2 = new BSTElement<int, string>(200);
	BSTElement<int, string> *node3 = new BSTElement<int, string>(250);
	BSTElement<int, string> *node4 = new BSTElement<int, string>(75);
	BSTElement<int, string> *node5 = new BSTElement<int, string>(33);

	// construct the tree
	root->setLeft(node1);
	root->setRight(node2);
	node2->setRight(node3);
	node1->setRight(node4);
    node1->setLeft(node5);

	// style the nodes and links. Nodes have properties of label shape, size,
	// color and opacity. Links have properties of a label, color and thickness

	root->setColor("red");
	root->setSize (40);

	// path to largest key
	node2->setShape(SQUARE);
	node3->setShape(SQUARE);
	node2->setColor("magenta");
	node3->setColor("magenta");

	//style link from root to node2
	root->getLinkVisualizer(node2)->setThickness(3.0f);
	root->getLinkVisualizer(node2)->setColor("orange");

	//style link from node2 to node3
	node2->getLinkVisualizer(node3)->setThickness(3.0f);
	node2->getLinkVisualizer(node3)->setColor("orange");

	// path to smallest key
	node1->setShape(TRIANGLE);
	node5->setShape(TRIANGLE);
	node5->setColor("cyan");
	node5->setColor("cyan");

	//style link from root to node2
	root->getLinkVisualizer(node1)->setThickness(2.0f);
	root->getLinkVisualizer(node1)->setColor("purple");

	//style link from node2 to node3
	node1->getLinkVisualizer(node5)->setThickness(2.0f);
	node1->getLinkVisualizer(node5)->setColor("purple");

	//deemphasize node 4, make it a bit transparent
	node4->setOpacity(0.2f);

	// privide BRIDGES a handle to the root of the tree
	bridges.setDataStructure(root);

	// visualize the binary search tree
	bridges.visualize();

	//cleaning up
	delete root;
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	
	return 0;
}
