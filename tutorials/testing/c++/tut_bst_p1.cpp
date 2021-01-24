
#include <string>
#include "Bridges.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;

// Part 1 of this tutorial will illustrate the use of the BRIDGES in building
// binary search trees.  We will begin by constructing the tree manually and
// displaying it

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title, description
	bridges.setTitle("A Simple  Binary Search Tree Example");
	bridges.setDescription("This example illustrates a binary search tree built using BRIDGES");

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

	// label the nodes 
	root->setLabel ("Root");
	node1->setLabel ("Node1");
	node2->setLabel ("Node2");
	node3->setLabel ("Node3");
	node4->setLabel ("Node4");
	node5->setLabel ("Node5");

	// privide BRIDGES a handle to the root of the tree
	bridges.setDataStructure(root);

	// visualize the binary search tree
	// Hit the 'l' key to see the node labels
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
