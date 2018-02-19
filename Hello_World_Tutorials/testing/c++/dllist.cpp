#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "DLelement.h"


using namespace bridges;

int main() {


	Bridges::initialize(4, "kalpathi60", "486749122386");
//	Bridges::initialize(4, "bridges_public", "997924677918");

	DLelement<string> *dl0 = new DLelement<string>("0", "5");
	DLelement<string> *dl1 = new DLelement<string>("1", "0");
	DLelement<string> *dl2 = new DLelement<string>("2", "1");
	DLelement<string> *dl3 = new DLelement<string>("3", "2");
        
	dl0->setNext(dl1);
	dl1->setNext(dl2);
	dl2->setNext(dl3);
	dl3->setPrev(dl2);
	dl2->setPrev(dl1);
	dl1->setPrev(dl0);


	dl0->getVisualizer()->setColor(Color("red"));
	dl1->getVisualizer()->setColor(Color("green"));
	dl2->getVisualizer()->setColor(Color("blue"));
	dl3->getVisualizer()->setColor(Color("yellow"));

	dl0->getLinkVisualizer(dl1)->setColor(Color("red"));
	dl1->getLinkVisualizer(dl2)->setColor(Color("green"));
	dl2->getLinkVisualizer(dl3)->setColor(Color("blue"));
	dl3->getLinkVisualizer(dl2)->setColor(Color("cyan"));
	dl2->getLinkVisualizer(dl1)->setColor(Color("magenta"));
	dl1->getLinkVisualizer(dl0)->setColor(Color("yellow"));

	Bridges::setTitle("Doubly Linked List Example");
	Bridges::setDataStructure(dl0);

	Bridges::visualize();

	return 0;
}
