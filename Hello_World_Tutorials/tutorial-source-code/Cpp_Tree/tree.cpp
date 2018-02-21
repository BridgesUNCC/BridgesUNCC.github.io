#include &lt;string&gt;
#include "Bridges.h"
#include "TreeElement.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(8, "YOUR_USER_ID", "YOUR_API_KEY"); 

	TreeElement&lt;string&gt; *tle0 = new TreeElement&lt;string&gt;(10", "10");
	TreeElement&lt;string&gt; *tle1 = new TreeElement&lt;string&gt;(5", "5");
	TreeElement&lt;string&gt; *tle2 = new TreeElement&lt;string&gt;(3", "3");
	TreeElement&lt;string&gt; *tle3=  new TreeElement&lt;string&gt;(20","20");
	TreeElement&lt;string&gt; *tle4=  new TreeElement&lt;string&gt;(50","50");
	TreeElement&lt;string&gt; *tle5=  new TreeElement&lt;string&gt;(100","100");

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
