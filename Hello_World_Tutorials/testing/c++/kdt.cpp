#include "Bridges.h"
#include "KdTreeElement.h"

using namespace bridges;

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");

	bridges->setTitle("A Kd Tree Example");

	KdTreeElement<int, int> *t0 = new KdTreeElement<int, int>(50, 0);
	KdTreeElement<int, int> *t1 = new KdTreeElement<int, int>(25, 1);
	KdTreeElement<int, int> *t2 = new KdTreeElement<int, int>(75, 1);
	KdTreeElement<int, int> *t3 = new KdTreeElement<int, int>(20, 0);
	KdTreeElement<int, int> *t4 = new KdTreeElement<int, int>(30, 0);
	KdTreeElement<int, int> *t5 = new KdTreeElement<int, int>(60, 0);
	KdTreeElement<int, int> *t6 = new KdTreeElement<int, int>(80, 0);

	t0->setLeft(t1);
	t0->setRight(t2);
	t1->setLeft(t3);
	t1->setLabel("X");
	t1->setRight(t4);
	t2->setLeft(t5);
	t2->setRight(t6);

	t0->setLabel("X");
	t1->setLabel("Y");
	t2->setLabel("Y");
	t3->setLabel("X");
	t4->setLabel("X");
	t5->setLabel("X");
	t6->setLabel("X");

	t0->getVisualizer()->setColor(Color("red"));
	// color the leaf nodes that represent the code letters
	t1->getVisualizer()->setColor(Color("orange"));
	t4->getVisualizer()->setColor(Color("orange"));
	t5->getVisualizer()->setColor(Color("orange"));
	t6->getVisualizer()->setColor(Color("orange"));

	// provide BRIDGES the  handle to the tree structure
	bridges->setDataStructure(t0);

	bridges->visualize();

	return 0;
}
