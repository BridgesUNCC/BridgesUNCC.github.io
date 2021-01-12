#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

// Part 3 of this tutorial illustrates iterators that can be used to 
// traverse doubly linked lists
//
// We will continue to use the same list

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A doubly Linked List Example");

	// set description
	bridges.setDescription("Illustrate the user of iterators with doubly linked lists");


	// create the nodes
	DLelement<string>  *el0 = new DLelement<string> ("Gretel Chaney");
	DLelement<string>  *el1 = new DLelement<string> ("Lamont Kyler");
	DLelement<string>  *el2 = new DLelement<string> ("Gladys Serino");
	DLelement<string>  *el3 = new DLelement<string> ("Karol Soderman");
	DLelement<string>  *el4 = new DLelement<string> ("Starr McGinn");

	// set the names to be the label (for seeing it in the visualization)
	el0->setLabel("Gretal Chaney");
	el1->setLabel("Lamont Kyler");
	el2->setLabel("Gladys Serino");
	el3->setLabel("Karol Soderman");
	el4->setLabel("Starr McGinn");

	// link the elements, create the list
    el0->setNext(el1);
    el1->setPrev(el0);
    el1->setNext(el2);
    el2->setPrev(el1);
    el2->setNext(el3);
    el3->setPrev(el2);
    el3->setNext(el4);
    el4->setPrev(el3);

	// traversing the doubly linked list

	cout << "Traverse the list - using a normal for loop\n";

	for (DLelement<string> *dle = el0; dle != nullptr; dle = dle->getNext())
		cout << "\t " << dle->getLabel() << "\n";

    // set the list to use the iterator for the DLelement
	DLelement_List<string> dllist(el0);

	cout << "Traverse the list - using a forward iterator\n";
	for (auto iter = dllist.begin(); iter != dllist.end(); iter++)
		cout << "\t" << *iter << endl;

	cout << "Traverse the list - using a reverse iterator\n";
    for (auto iter = dllist.rbegin(); iter != dllist.rend(); iter--)
        cout << "\t" << *iter << endl;

	// create the list
	el0->setNext(el1);
	el1->setPrev(el0);
	el1->setNext(el2);
	el2->setPrev(el1);
	el2->setNext(el3);
	el3->setPrev(el2);
	el3->setNext(el4);
	el4->setPrev(el3);


	// provide BRIDGES the head of the list
	bridges.setDataStructure(el0);

	// visualize
	bridges.visualize();

	// cleanup
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
		
	return 0;
}
