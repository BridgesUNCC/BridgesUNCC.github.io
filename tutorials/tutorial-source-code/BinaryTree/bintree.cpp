#include "Bridges.h"
#include "BinTreeElement.h"

using namespace bridges;

int main() {

	Bridges::initialize(9, "YOUR_USER_ID", "YOUR_API_KEY"); 

	Bridges::setTitle("A Huffman Coding Tree Example");
	Bridges::setDescription("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2");


	BinTreeElement&lt;int&gt; *t0 = new BinTreeElement&lt;int&gt;(0, "306");
	BinTreeElement&lt;int&gt; *t1 = new BinTreeElement&lt;int&gt;(1, "120\\nE");
	BinTreeElement&lt;int&gt; *t2 = new BinTreeElement&lt;int&gt;(2, "186");
	BinTreeElement&lt;int&gt; *t3 = new BinTreeElement&lt;int&gt;(3, "79");
	BinTreeElement&lt;int&gt; *t4 = new BinTreeElement&lt;int&gt;(4, "37\\nU");
	BinTreeElement&lt;int&gt; *t5 = new BinTreeElement&lt;int&gt;(5, "42\\nD");
	BinTreeElement&lt;int&gt; *t6 = new BinTreeElement&lt;int&gt;(6, "42\\nL");
	BinTreeElement&lt;int&gt; *t7 = new BinTreeElement&lt;int&gt;(7, "107");
	BinTreeElement&lt;int&gt; *t8 = new BinTreeElement&lt;int&gt;(8, "65");
	BinTreeElement&lt;int&gt; *t9 = new BinTreeElement&lt;int&gt;(9, "32\\nC");
	BinTreeElement&lt;int&gt; *t10 = new BinTreeElement&lt;int&gt;(10, "33");
	BinTreeElement&lt;int&gt; *t11 = new BinTreeElement&lt;int&gt;(11, "9");
	BinTreeElement&lt;int&gt; *t12 = new BinTreeElement&lt;int&gt;(12, "2\\nZ");
	BinTreeElement&lt;int&gt; *t13 = new BinTreeElement&lt;int&gt;(13, "7\\nK");
	BinTreeElement&lt;int&gt; *t14 = new BinTreeElement&lt;int&gt;(14, "24\\nM");

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
