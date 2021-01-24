#include <string>
#include "Bridges.h"
#include "TreeElement.h"

using namespace bridges;
using std::string;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	TreeElement<string> *t0 = new TreeElement<string>("Hello", "Hello");
	TreeElement<string> *t2 = new TreeElement<string>("This", "This");
	TreeElement<string> *t3 = new TreeElement<string>("is", "is");
	TreeElement<string> *t4 =  new TreeElement<string>("a", "a");
	TreeElement<string> *t5 =  new TreeElement<string>("generic", "generic");
	TreeElement<string> *t6 =  new TreeElement<string>("Tree", "Tree");
	TreeElement<string> *t7 =  new TreeElement<string>("Representation", "Representation");

	// add links to children

	t0->addChild(t2);
	t0->addChild(t3);
	t0->addChild(t4);
	t2->addChild(t5);
	t2->addChild(t6);
	t3->addChild(t7);

	// set some visual attributes

	t0->setColor("red");
	t0->setOpacity(0.3f);

	// link colors
	t0->getLinkVisualizer(t2)->setColor("green");
	t0->getLinkVisualizer(t2)->setThickness(2.0f);
	t0->getLinkVisualizer(t3)->setColor("blue");
	t0->getLinkVisualizer(t3)->setThickness(2.0f);
	t0->getLinkVisualizer(t4)->setColor("orange");
	t0->getLinkVisualizer(t4)->setThickness(2.0f);

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(t0);

	bridges.visualize();

	delete t0;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	delete t7;
	
	return 0;
}
