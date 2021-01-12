/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "SLelement.h"
#include <string>

using namespace bridges;
using namespace std;

//
// In part 3 of this tutorial we demonstrate more advanced features such as 
// using iterators to traverse lists, which are more convenient than working
// with the underlying element objects. To keep the tutorial simple, we will ignore
// styling (that was illustrated in part 2).
//
// Reference Classes: SLelement, Bridges 
//
int main (int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
	// set title
	bridges.setTitle("A Singly Linked List Example");

	// set  description
	bridges.setDescription("Demonstrate advanced features, looping, iterators"); 

	// create the linked list elements with student names
	SLelement<string>  *st0 = new SLelement<string> ("Gretel Chaney");
	SLelement<string>  *st1 = new SLelement<string> ("Lamont Kyler");
	SLelement<string>  *st2 = new SLelement<string> ("Gladys Serino");
	SLelement<string>  *st3 = new SLelement<string> ("Karol Soderman");
	SLelement<string>  *st4 = new SLelement<string> ("Starr McGinn");

	// we want to see these names in the visualization so we will set them as
	// the nodes' labels. We will retrieve the nodes' generic data for the label
	st0->setLabel(st0->getValue());
	st1->setLabel(st1->getValue());
	st2->setLabel(st2->getValue());
	st3->setLabel(st3->getValue());
	st4->setLabel(st4->getValue());

	//  link the elements into a list
	st0->setNext(st1);
	st1->setNext(st2);
	st2->setNext(st3);
	st3->setNext(st4);

	// print the names of the students in the list using iteration

	// Using a regular for loop on BRIDGES elements
	cout << "Using a regular for loop..\n"; 
	for (auto el = st0; el != nullptr; el = el->getNext())
		cout << "\t" << el->getValue() << endl;

	cout << "Using a forward iterator..\n"; 
	SLelement_List<string> list(st0);
	for (auto iter = list.begin(); iter != list.end(); ++iter)
		cout << "\t" << *iter << endl;

	cout << "Using a range loop..\n"; 
	for (auto iter: list) {
		cout << "\t" << iter << endl;
	}

	// tell Bridges the head of the list
	bridges.setDataStructure(st0);

    // visualize the linked list (hit the key 'l' on the visualzation to see all labels
	bridges.visualize();

	//cleanup
	delete st0;
	delete st1;
	delete st2;
	delete st3;
	delete st4;
}
