/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircSLelement.h"
#include <string>

using namespace bridges;
using namespace std;

int main (int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// create the linked list elements with student names
	CircSLelement<string>  *el0 = new CircSLelement<string> ("Gretel Chaney", "Gretel Chaney");
	CircSLelement<string>  *el1 = new CircSLelement<string> ("Lamont Kyler", "Lamont Kyler");
	CircSLelement<string>  *el2 = new CircSLelement<string> ("Gladys Serino", "Gladys Serino");
	CircSLelement<string>  *el3 = new CircSLelement<string> ("Karol Soderman", "Karol Soderman");
	CircSLelement<string>  *el4 = new CircSLelement<string> ("Starr McGinn", "Starr McGinn");

	//  link the elements
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);
	el4->setNext(el0);

	// test the element's iterators
	cout << "Testing list iterator.." << endl;
	CircSLelement_List<string> list(el0);
	auto iter = list.begin();
	do {
		cout << "\t" << *iter << endl;
		++iter;
	} while (iter != list.end());

	// connect the last element to the first element to form the circular list
	el4->setNext(el0);

	// set colors for list elements - see the Color class for supported colors
	el0->setColor("red");
	el2->setColor("aliceblue");

	// color the links - must specify a valid terminating element
	el0->getLinkVisualizer(el1)->setColor("green");
	el3->getLinkVisualizer(el4)->setColor("magenta");

	// adjust link thickness
	el0->getLinkVisualizer(el1)->setThickness(2.0f);

	// set node transparency
	el4->setOpacity (0.5f);


	// set node size
	el0->setSize (20);

	// set link label
	el2->getLinkVisualizer(el3)->setLabel("Gladys_to_Karol");

	bridges.setDataStructure(el0);
	bridges.visualize();

	//freeing memory
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
	  
}
