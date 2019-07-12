
#include "Bridges.h"
#include "MLelement.h"

using namespace bridges;

int main()  {
    								//create the Bridges object
	Bridges::initialize(7, "YOUR_USER_ID", "YOUR_API_KEY");
	Bridges::setTitle("A Trivial Multilist Example");

    								//create  a linked list 

	MLelement&lt;int&gt; *el0 = new MLelement&lt;int&gt;(0");
	MLelement&lt;int&gt; *el1 = new MLelement&lt;int&gt;(1");
	MLelement&lt;int&gt; *el2 = new MLelement&lt;int&gt;(2");
	MLelement&lt;int&gt; *el3 = new MLelement&lt;int&gt;(3");
	MLelement&lt;int&gt; *el4 = new MLelement&lt;int&gt;(4");
		
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);
								// create a sublist from 2
	MLelement&lt;int&gt; *el5 = new MLelement&lt;int&gt;(5");
	MLelement&lt;int&gt; *el6 = new MLelement&lt;int&gt;(6");
	MLelement&lt;int&gt; *el7 = new MLelement&lt;int&gt;(7");
							
	el5->setNext(el6);
	el6->setNext(el7);

	el2->setSubList(el5);

	MLelement&lt;int&gt; *el8 = new MLelement&lt;int&gt;(8");
	MLelement&lt;int&gt; *el9 = new MLelement&lt;int&gt;(9");

							// create a second sublist from 3
	el8->setNext(el9);
	el3->setSubList(el8);

							// create a sublist from 5
	MLelement&lt;int&gt; *el10 = new MLelement&lt;int&gt;(10");
	MLelement&lt;int&gt; *el11 = new MLelement&lt;int&gt;(11");
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
	Bridges::setDataStructure(el0);
        
        							// visualize the list
	Bridges::visualize();
}
