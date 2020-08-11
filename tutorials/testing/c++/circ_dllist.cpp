/**
 * Created by Kalpathi Subramanian, 2/20/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircDLelement.h"
#include <string>


using namespace bridges;
using std::string;


int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	CircDLelement<string>  *el0 = new CircDLelement<string> ("Gretel Chaney", "Gretel Chaney");
	CircDLelement<string>  *el1 = new CircDLelement<string> ("Lamont Kyler", "Lamont Kyler");
	CircDLelement<string>  *el2 = new CircDLelement<string> ("Gladys Serino", "Gladys Serino");
	CircDLelement<string>  *el3 = new CircDLelement<string> ("Karol Soderman", "Karol Soderman");
	CircDLelement<string>  *el4 = new CircDLelement<string> ("Starr McGinn", "Starr McGinn");

	// create the list
	el0->setNext(el1);
	el1->setPrev(el0);
	el1->setNext(el2);
	el2->setPrev(el1);
	el2->setNext(el3);
	el3->setPrev(el2);
	el3->setNext(el4);
	el4->setPrev(el3);

	// add the links to join the last and first nodes
	// must set the next and prev links
	el4->setNext(el0);
	el0->setPrev(el4);

	cout << "Testing forward list iterator.." << endl;
	CircDLelement_List<string> list(el0);
    auto iter = list.begin();
    do {
        cout << "\t" << *iter << endl;
        ++iter;
    } while (iter != list.end());

	cout << "Testing reverse list iterator.." << endl;
    iter = list.rbegin();
    do {
        cout << "\t" << *iter << endl;
        --iter;
    } while (iter != list.rend());

	// add  element colors
	// set colors for list elements - see the Color class for supported colors
	el0->setColor("red");
	el2->setColor("aliceblue");

	// color the links - must specify a valid terminating element
	el0->getLinkVisualizer(el1)->setColor("green");
	el3->getLinkVisualizer(el4)->setColor("magenta");

	// adjust link thickness
	el0->getLinkVisualizer(el1)->setThickness(2.0f);

	// set link label
	el2->getLinkVisualizer(el3)->setLabel("Link Label");

	// set node transparency
	el4->setOpacity (0.5f);

	// set node size
	el0->setSize (20);

	bridges.setDataStructure(el0);
	bridges.visualize();

	// freeing memory
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
				

	return 0;
}
