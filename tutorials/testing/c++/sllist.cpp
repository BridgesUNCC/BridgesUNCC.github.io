/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "SLelement.h"
#include <string>

using namespace bridges;
using namespace std;


int main (int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
	// set title
	bridges.setTitle("A Single Linked List Example");

	// set  description
	bridges.setDescription("A singly linked list of node with student names, where each node is linked only to the next node in the list. Illustrates Node and link coloring, node size, link thickness and opacity");

	// create the linked list elements with student names
	SLelement<string>  *el0 = new SLelement<string> ("Gretel Chaney", "Gretel Chaney");
	SLelement<string>  *el1 = new SLelement<string> ("Lamont Kyler", "Lamont Kyler");
	SLelement<string>  *el2 = new SLelement<string> ("Gladys Serino", "Gladys Serino");
	SLelement<string>  *el3 = new SLelement<string> ("Karol Soderman", "Karol Soderman");
	SLelement<string>  *el4 = new SLelement<string> ("Starr McGinn", "Starr McGinn");

	//  link the elements
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);

	// SLelement also has an iterator that can be used to iterate over the list
	SLelement_List<string> list(el0);
    
	// print the names of the students in the list using the iterator
    for (auto iter = list.begin(); iter != list.end(); ++iter)
        cout << *iter << endl;

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

	//freeing
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
}
