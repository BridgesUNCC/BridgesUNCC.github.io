/**
 * Created by Kalpathi Subramanian, 2/20/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircDLelement.h"
#include "StudentInfo.h"


using namespace bridges;

							// helper function
CircDLelement&lt;StudentInfo&gt; *insertFront(
			CircDLelement&lt;StudentInfo&gt; *tailElement,
			CircDLelement&lt;StudentInfo&gt; *newElement);

int main() {
	Bridges::initialize(6, "YOUR_USER_ID", "YOUR_API_KEY");

	Bridges::setTitle("An Example Circular Doubly Linked List");

         					// create the linked list elements with 
							// student data 
	CircDLelement&lt;StudentInfo&gt; *students[] = {
		new CircDLelement&lt;StudentInfo&gt;(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				 9.0
			), ""),
		new CircDLelement&lt;StudentInfo&gt;(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				 11.0
			), ""),
		new CircDLelement&lt;StudentInfo&gt;(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				 12.0
			), ""),
		new CircDLelement&lt;StudentInfo&gt;(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"blue",
				"magenta",
				 9.0
			), ""),
		new CircDLelement&lt;StudentInfo&gt;(
			StudentInfo(
				"00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"yellow",
				 15.0
			), "") 
		};

	CircDLelement&lt;StudentInfo&gt; *head =  nullptr;

	int num_students = 5;
	for(int i = 0; i < num_students; i++) {
		if (i)
			head = insertFront(head, students[i]);
		else 
			head = students[i];
	}

       					//  add visual attributes
	CircDLelement&lt;StudentInfo&gt; *current = head;
	StudentInfo si;
	do {
		si = current-&gt;getValue();
		current->setLabel(si.getStudentLabel());
		current->getVisualizer()->setColor(si.getFavoriteColor());

		current->getLinkVisualizer(current->getNext())->setColor(si.getDislikeColor());
		current->getLinkVisualizer(current->getNext())->setThickness(si.getStudentCreditHours()*.5);

		current->getLinkVisualizer(current->getPrev())->setColor(si.getDislikeColor());
		current->getLinkVisualizer(current->getPrev())->setThickness(si.getStudentCreditHours()*.5);

		current = current->getNext();
	}  while (current != head);

						// set data structure to point to head
	Bridges::setDataStructure(head);
						// visualize the circular list
	Bridges::visualize();

	return 0;
}

CircDLelement&lt;StudentInfo> *insertFront(
			CircDLelement&lt;StudentInfo> *tailElement,
			CircDLelement&lt;StudentInfo> *newElement) {

	CircDLelement&lt;StudentInfo> *tailNextElement = tailElement->getNext();

	newElement->setNext(tailNextElement);
	newElement->setPrev(tailElement);

	tailNextElement->setPrev(newElement);
	tailElement->setNext(newElement);

	return tailElement;
}
