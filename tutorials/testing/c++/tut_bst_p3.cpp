
#include <string>
#include "Bridges.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;

// Part 3 of this tutorial will illustrate traversing a binary search tree
// to find a specific key value and mark it as well as style the path to it

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A Simple  Binary Search Tree Example");

	// set description
	bridges.setDescription("This example illustrates finding a key in a constructed binary search tree and styling the visited nodes and links");

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

	// traverse the tree to the largest node and style them to find 
	// key value 75
	BSTElement<int, string> *r  = root, *left, *right; 
	bool found = false;
	int search_key = 75;
	while (!found && r != nullptr) {
		// style the node
		if (r) {
			r->setColor("red");
			r->setShape(SQUARE);
			r->setShape(SQUARE);
			r->setSize(20);
		}
		int key = r->getKey();
		if (key  == search_key) { 	// found it
			found = true;
			r->setColor("orange");
			r->setSize(49);
			cout << "Yay!\n";
		}
		else if (search_key < key){  // go left
			left = r->getLeft();	
			if (left) {  // style link
				r->getLinkVisualizer(left)->setColor("cyan");
				r->getLinkVisualizer(left)->setThickness(5.0f);
			}
			r = left;
		}
		else {
			right = r->getRight();	
			if (right) { // style link
				r->getLinkVisualizer(right)->setColor("cyan");
				r->getLinkVisualizer(right)->setThickness(5.0f);
			}	
			r = right;
		}
	}

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
