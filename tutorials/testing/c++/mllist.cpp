
#include "Bridges.h"
#include "MLelement.h"

using namespace bridges;

int main(int argc, char **argv)  {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// create  the list nodes

	MLelement<int> *el0 = new MLelement<int>("0");
	MLelement<int> *el1 = new MLelement<int>("1");
	MLelement<int> *el2 = new MLelement<int>("2");
	MLelement<int> *el3 = new MLelement<int>("3");
	MLelement<int> *el4 = new MLelement<int>("4");
	MLelement<int> *el5 = new MLelement<int>("5");
	MLelement<int> *el6 = new MLelement<int>("6");
	MLelement<int> *el7 = new MLelement<int>("7");
	MLelement<int> *el8 = new MLelement<int>("8");
	MLelement<int> *el9 = new MLelement<int>("9");
	MLelement<int> *el10 = new MLelement<int>("10");
	MLelement<int> *el11 = new MLelement<int>("11");

	// create the main list: 1, 2, 3, 4
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);

	// create a sublist from 2 to 5, 6, 7
	el2->setSubList(el5);
	el5->setNext(el6);
	el6->setNext(el7);

	// create a second sublist from 6 to 10, 11
	el6->setSubList(el10);
	el10->setNext(el11);

	//create a third sublist from 3 to 8, 9
	el3->setSubList(el8);
	el8->setNext(el9);

	// some visual attributes
	el0->setSize (40);
	el0->setColor(Color("red"));

	// set sublist origins to be green and size 30
	el2->setColor(Color("green"));
	el3->setColor(Color("green"));
	el6->setColor(Color("green"));
	el3->setSize (30);
	el6->setSize (30);
	el2->setSize (30);

	el0->getLinkVisualizer(el1)->setColor("red");
	el0->getLinkVisualizer(el1)->setThickness(3);
	el1->getLinkVisualizer(el2)->setColor("blue");
	el1->getLinkVisualizer(el2)->setThickness(3);
	el2->getLinkVisualizer(el3)->setThickness(3);


	//set visualizer type
	bridges.setDataStructure(el0);

	// visualize the list
	bridges.visualize();

	//freeing memory
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
	delete el5;
	delete el6;
	delete el7;
	delete el8;
	delete el9;
	delete el10;
	delete el11;
					
	
}
