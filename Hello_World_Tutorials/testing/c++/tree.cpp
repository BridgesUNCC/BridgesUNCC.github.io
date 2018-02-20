#include <string>
#include "Bridges.h"
#include "TreeElement.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(8, "kalpathi60", "486749122386"); 
//	Bridges::initialize(8, "bridges_public", "997924677918");

	TreeElement<string> *tle0 = new TreeElement<string>("10", "10");
	TreeElement<string> *tle1 = new TreeElement<string>("5", "5");
	TreeElement<string> *tle2 = new TreeElement<string>("3", "3");
	TreeElement<string> *tle3=  new TreeElement<string>("20","20");
	TreeElement<string> *tle4=  new TreeElement<string>("50","50");
	TreeElement<string> *tle5=  new TreeElement<string>("100","100");

	tle0->addChild(tle1);
	tle0->addChild(tle2);
	tle0->addChild(tle3);
	tle1->addChild(tle4);
	tle1->addChild(tle5);

	tle0->getVisualizer()->setColor(Color("red"));
	tle1->getVisualizer()->setColor(Color("green"));
	tle2->getVisualizer()->setColor(Color("blue"));
	tle3->getVisualizer()->setColor(Color("yellow"));

	tle0->getLinkVisualizer(tle1)->setColor(Color("red"));
	tle0->getLinkVisualizer(tle2)->setColor(Color("green"));
	tle0->getLinkVisualizer(tle3)->setColor(Color("blue"));
	tle1->getLinkVisualizer(tle4)->setColor(Color("cyan"));
	tle1->getLinkVisualizer(tle5)->setColor(Color("magenta"));

	Bridges::setTitle("A General Tree Example");
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(tle0);

	Bridges::visualize();

	return 0;
}
