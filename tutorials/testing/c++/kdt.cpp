#include "Bridges.h"
#include "KdTreeElement.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
	bridges.setTitle("A Kd Tree Example");
	bridges.setDescription("A three-level tree with partitioners cycling between X and Y. The root node color is set to red while the leaf nodes that represent code letters are set to orange.");

	// create nodes
	KdTreeElement<int, int> *t0 = new KdTreeElement<int, int>(50, 0);
	KdTreeElement<int, int> *t1 = new KdTreeElement<int, int>(25, 1);
	KdTreeElement<int, int> *t2 = new KdTreeElement<int, int>(75, 1);
	KdTreeElement<int, int> *t3 = new KdTreeElement<int, int>(20, 0);
	KdTreeElement<int, int> *t4 = new KdTreeElement<int, int>(30, 0);
	KdTreeElement<int, int> *t5 = new KdTreeElement<int, int>(60, 0);
	KdTreeElement<int, int> *t6 = new KdTreeElement<int, int>(80, 0);

	// form the links
	t0->setLeft(t1);
	t0->setRight(t2);
	t1->setLeft(t3);
	t1->setLabel("X");
	t1->setRight(t4);
	t2->setLeft(t5);
	t2->setRight(t6);

	// set partitioning dimension
	t0->setLabel("X");
	t1->setLabel("Y");
	t2->setLabel("Y");
	t3->setLabel("X");
	t4->setLabel("X");
	t5->setLabel("X");
	t6->setLabel("X");

	// set visual attributes
	t0->setColor("red");

	// color the leaf nodes that represent the code letters
	t1->setColor("orange");
	t4->setColor("orange");
	t5->setColor("orange");
	t6->setColor("orange");

	// provide BRIDGES the  handle to the tree structure and visualize
	bridges.setDataStructure(t0);
	bridges.visualize();

	// Reclaiming memory
	delete t0;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	
	return 0;
}
