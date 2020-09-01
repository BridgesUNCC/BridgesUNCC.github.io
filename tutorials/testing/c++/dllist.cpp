
#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

// helper function

DLelement<string> *insertFront(DLelement<string> *front,
	DLelement<string> *new_el);

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("A doubly Linked List Example");

	// set description
	bridges.setDescription("This list has five nodes all linked to the nodes before and after them and illustrates visual attributes. ");


	// create some elements
	DLelement<string>  *el0 = new DLelement<string> ("Gretel Chaney", "Gretel Chaney");
	DLelement<string>  *el1 = new DLelement<string> ("Lamont Kyler", "Lamont Kyler");
	DLelement<string>  *el2 = new DLelement<string> ("Gladys Serino", "Gladys Serino");
	DLelement<string>  *el3 = new DLelement<string> ("Karol Soderman", "Karol Soderman");
	DLelement<string>  *el4 = new DLelement<string> ("Starr McGinn", "Starr McGinn");

	// create the list
	el0->setNext(el1);
	el1->setPrev(el0);
	el1->setNext(el2);
	el2->setPrev(el1);
	el2->setNext(el3);
	el3->setPrev(el2);
	el3->setNext(el4);
	el4->setPrev(el3);

	// test the iterators in DLelement
	DLelement_List<string> list(el0);

	cout <<  "Forward Iteration:" << endl;
	for (auto iter = list.begin(); iter != list.end(); iter++)
		cout << "\t" << *iter << endl;
	cout <<  "Reverse Iteration:" << endl;
	for (auto iter = list.rbegin(); iter != list.rend(); iter--)
		cout << "\t" << *iter << endl;

	// add  element colors
	// set colors for list elements - see the Color class for supported colors
	el0->setColor("red");
	el2->setColor("aliceblue");

	// color the links - must specify a valid terminating element
	el0->getLinkVisualizer(el1)->setColor("green");
	// color the reverse link
	el1->getLinkVisualizer(el0)->setColor("magenta");

	// adjust link thickness
	el3->getLinkVisualizer(el4)->setThickness(3.0f);
	el4->getLinkVisualizer(el3)->setThickness(6.0f);

	// set link label
	el2->getLinkVisualizer(el3)->setLabel("Link Label");

	// set node transparency
	el4->setOpacity (0.5f);

	// set node size
	el0->setSize (20);

	bridges.setDataStructure(el0);
	bridges.visualize();

	//freeing memory
	delete el0;
	delete el1;
	delete el2;
	delete el3;
	delete el4;
		
	return 0;
}

DLelement<string> *insertFront(DLelement<string> *front, DLelement<string> *new_el) {
	if (front == nullptr)
		return new_el;

	new_el->setNext(front);
	front->setPrev(new_el);

	return new_el;
}
