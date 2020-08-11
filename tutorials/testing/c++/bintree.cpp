#include "Bridges.h"
#include "BinTreeElement.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title, description
	bridges.setTitle("A Huffman Coding Tree Example");
	bridges.setDescription("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2 "
		"Root is set to red and leaf nodes are set to orange.");


	// create the nodes - manually created huffman coding tree
	BinTreeElement<int> *t0 = new BinTreeElement<int>(0, "306");
	BinTreeElement<int> *t1 = new BinTreeElement<int>(1, "120\nE");
	BinTreeElement<int> *t2 = new BinTreeElement<int>(2, "186");
	BinTreeElement<int> *t3 = new BinTreeElement<int>(3, "79");
	BinTreeElement<int> *t4 = new BinTreeElement<int>(4, "37\nU");
	BinTreeElement<int> *t5 = new BinTreeElement<int>(5, "42\nD");
	BinTreeElement<int> *t6 = new BinTreeElement<int>(6, "42\nL");
	BinTreeElement<int> *t7 = new BinTreeElement<int>(7, "107");
	BinTreeElement<int> *t8 = new BinTreeElement<int>(8, "65");
	BinTreeElement<int> *t9 = new BinTreeElement<int>(9, "32\nC");
	BinTreeElement<int> *t10 = new BinTreeElement<int>(10, "33");
	BinTreeElement<int> *t11 = new BinTreeElement<int>(11, "9");
	BinTreeElement<int> *t12 = new BinTreeElement<int>(12, "2\nZ");
	BinTreeElement<int> *t13 = new BinTreeElement<int>(13, "7\nK");
	BinTreeElement<int> *t14 = new BinTreeElement<int>(14, "24\nM");

	// form the links
	t0->setLeft(t1);
	t0->setRight(t2);
	t2->setLeft(t3);
	t2->setRight(t7);
	t3->setLeft(t4);
	t3->setRight(t5);
	t7->setLeft(t6);
	t7->setRight(t8);
	t8->setLeft(t9);
	t8->setRight(t10);
	t10->setLeft(t11);
	t10->setRight(t14);
	t11->setLeft(t12);
	t11->setRight(t13);


	t0->setColor("red");
	// color the leaf nodes that represent the code letters
	t1->setColor("orange");
	t4->setColor("orange");
	t5->setColor("orange");
	t6->setColor("orange");
	t9->setColor("orange");
	t12->setColor("orange");
	t13->setColor("orange");
	t14->setColor("orange");

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(t0);

	// visualize
	bridges.visualize();

	// freeing memory
	delete t0;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	delete t7;
	delete t8;
	delete t9;
	delete t10;
	delete t11;
	delete t12;
	delete t13;
	delete t14;
	
	return 0;
}
