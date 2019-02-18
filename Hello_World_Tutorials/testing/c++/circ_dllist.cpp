/**
 * Created by Kalpathi Subramanian, 2/20/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircDLelement.h"
#include "StudentInfo.h"


using namespace bridges;

// helper function
CircDLelement<StudentInfo> *insertFront(
	CircDLelement<StudentInfo> *tailElement,
	CircDLelement<StudentInfo> *newElement);

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");



	bridges->setTitle("An Example Circular Doubly Linked List");

	// create the linked list elements with
	// student data
	CircDLelement<StudentInfo> *students[] = {
		new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				9.0
			), ""),
		new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				11.0
			), ""),
		new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				12.0
			), ""),
		new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"blue",
				"magenta",
				9.0
			), ""),
		new CircDLelement<StudentInfo>(
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

	CircDLelement<StudentInfo> *head =  nullptr;

	int num_students = 5;
	for (int i = 0; i < num_students; i++) {
		if (i)
			head = insertFront(head, students[i]);
		else
			head = students[i];
	}

	//  add visual attributes
	CircDLelement<StudentInfo> *current = head;
	StudentInfo si;
	do {
		si = current->getValue();
		current->setLabel(si.getStudentLabel());
		current->getVisualizer()->setColor(si.getFavoriteColor());

		current->getLinkVisualizer(current->getNext())->setColor(si.getDislikeColor());
		current->getLinkVisualizer(current->getNext())->setThickness(si.getStudentCreditHours()*.5);

		current->getLinkVisualizer(current->getPrev())->setColor(si.getDislikeColor());
		current->getLinkVisualizer(current->getPrev())->setThickness(si.getStudentCreditHours()*.5);

		current = current->getNext();
	}  while (current != head);

	// set data structure to point to head
	bridges->setDataStructure(head);
	// visualize the circular list
	bridges->visualize();

	return 0;
}

CircDLelement<StudentInfo> *insertFront(
	CircDLelement<StudentInfo> *tailElement,
	CircDLelement<StudentInfo> *newElement) {

	CircDLelement<StudentInfo> *tailNextElement = tailElement->getNext();

	newElement->setNext(tailNextElement);
	newElement->setPrev(tailElement);

	tailNextElement->setPrev(newElement);
	tailElement->setNext(newElement);

	return tailElement;
}

