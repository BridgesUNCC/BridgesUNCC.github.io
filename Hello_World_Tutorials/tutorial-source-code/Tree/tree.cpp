#include &lt;string&gt;
#include "Bridges.h"
#include "TreeElement.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(8, "YOUR_USER_ID", "YOUR_API_KEY"); 

	TreeElement&lt;string&gt; *t0 = new TreeElement&lt;string&gt;("Hello", "Hello");
	TreeElement&lt;string&gt; *t2 = new TreeElement&lt;string&gt;("This", "This");
	TreeElement&lt;string&gt; *t3 = new TreeElement&lt;string&gt;("is", "is");
	TreeElement&lt;string&gt; *t4=  new TreeElement&lt;string&gt;("a","a");
	TreeElement&lt;string&gt; *t5=  new TreeElement&lt;string&gt;("generic","generic");
	TreeElement&lt;string&gt; *t6=  new TreeElement&lt;string&gt;("Tree","Tree");
	TreeElement&lt;string&gt; *t7=  new TreeElement&lt;string&gt;("Representation","Representation");

                    // put in labels for each node; we simply use integers

	
	t0->setLabel(t0->getValue());
	t2->setLabel(t2->getValue());
	t3->setLabel(t3->getValue());
	t4->setLabel(t4->getValue());
	t5->setLabel(t5->getValue());
	t6->setLabel(t6->getValue());
	t7->setLabel(t7->getValue());

	                    // add links to children

	t0->addChild(t2);
	t0->addChild(t3);
	t0->addChild(t4);
	t2->addChild(t5);
	t2->addChild(t6);
	t3->addChild(t7);

						// set some visual attributes

	t0->getVisualizer()->setColor(Color("red"));
	t0->getVisualizer()->setOpacity(0.3f);

	Bridges::setTitle("A General Tree Example");
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(t0);

	Bridges::visualize();

	return 0;
}
