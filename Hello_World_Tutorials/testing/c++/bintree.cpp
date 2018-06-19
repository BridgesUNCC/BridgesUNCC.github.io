#include "Bridges.h"
#include "BinTreeElement.h"

using namespace bridges;

int main() {

	Bridges::initialize(9, "kalpathi60", "486749122386");

	Bridges::setTitle("A Huffman Coding Tree Example");
	Bridges::setDescription("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2");


	BinTreeElement<int> *t0 = new BinTreeElement<int>(0, "306");
	BinTreeElement<int> *t1 = new BinTreeElement<int>(1, "120\\nE");
	BinTreeElement<int> *t2 = new BinTreeElement<int>(2, "186");
	BinTreeElement<int> *t3 = new BinTreeElement<int>(3, "79");
	BinTreeElement<int> *t4 = new BinTreeElement<int>(4, "37\\nU");
	BinTreeElement<int> *t5 = new BinTreeElement<int>(5, "42\\nD");
	BinTreeElement<int> *t6 = new BinTreeElement<int>(6, "42\\nL");
	BinTreeElement<int> *t7 = new BinTreeElement<int>(7, "107");
	BinTreeElement<int> *t8 = new BinTreeElement<int>(8, "65");
	BinTreeElement<int> *t9 = new BinTreeElement<int>(9, "32\\nC");
	BinTreeElement<int> *t10 = new BinTreeElement<int>(10, "33");
	BinTreeElement<int> *t11 = new BinTreeElement<int>(11, "9");
	BinTreeElement<int> *t12 = new BinTreeElement<int>(12, "2\\nZ");
	BinTreeElement<int> *t13 = new BinTreeElement<int>(13, "7\\nK");
	BinTreeElement<int> *t14 = new BinTreeElement<int>(14, "24\\nM");

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


	t0->getVisualizer()->setColor(Color("red"));
	// color the leaf nodes that represent the code letters
	t1->getVisualizer()->setColor(Color("orange"));
	t4->getVisualizer()->setColor(Color("orange"));
	t5->getVisualizer()->setColor(Color("orange"));
	t6->getVisualizer()->setColor(Color("orange"));
	t9->getVisualizer()->setColor(Color("orange"));
	t12->getVisualizer()->setColor(Color("orange"));
	t13->getVisualizer()->setColor(Color("orange"));
	t14->getVisualizer()->setColor(Color("orange"));

	// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(t0);

	Bridges::visualize();

	return 0;
}
