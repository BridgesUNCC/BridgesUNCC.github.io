
#include "Bridges.h"
#include "MLelement.h"

using namespace bridges;

int main(int argc, char **argv)  {
	Bridges *bridges =  new Bridges(107, "YOUR_USER_ID", "YOUR_API_KEY");


	bridges->setTitle("A Trivial Multilist Example");

	//create  a linked list

	MLelement<int> *el0 = new MLelement<int>("0");
	MLelement<int> *el1 = new MLelement<int>("1");
	MLelement<int> *el2 = new MLelement<int>("2");
	MLelement<int> *el3 = new MLelement<int>("3");
	MLelement<int> *el4 = new MLelement<int>("4");

	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);
	// create a sublist from 2
	MLelement<int> *el5 = new MLelement<int>("5");
	MLelement<int> *el6 = new MLelement<int>("6");
	MLelement<int> *el7 = new MLelement<int>("7");

	el5->setNext(el6);
	el6->setNext(el7);

	el2->setSubList(el5);

	MLelement<int> *el8 = new MLelement<int>("8");
	MLelement<int> *el9 = new MLelement<int>("9");

	// create a second sublist from 3
	el8->setNext(el9);
	el3->setSubList(el8);

	// create a sublist from 5
	MLelement<int> *el10 = new MLelement<int>("10");
	MLelement<int> *el11 = new MLelement<int>("11");
	el10->setNext(el11);
	el6->setSubList(el10);

	el0->getVisualizer()->setSize (40);
	el0->getLinkVisualizer(el1)->setColor(Color("red"));
	el0->getLinkVisualizer(el1)->setThickness(3);
	el1->getLinkVisualizer(el2)->setColor(Color("blue"));
	el1->getLinkVisualizer(el2)->setThickness(3);
	el2->getLinkVisualizer(el3)->setColor(Color("cyan"));
	el2->getLinkVisualizer(el3)->setThickness(3);

	el0->getVisualizer()->setColor(Color("red"));
	//set visualizer type
	bridges->setDataStructure(el0);

	// visualize the list
	bridges->visualize();
}
