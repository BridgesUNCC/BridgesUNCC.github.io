#include "Bridges.h"
#include "CircDLelement.h"
#include "StudentInfo.h"

using namespace bridges;
					// helper function
CircDLelement<StudentInfo> *insertFront(
                CircDLelement<StudentInfo> *tailElement,
                CircDLelement<StudentInfo> *newElement);

int main() {

	Bridges::initialize(600, "kalpathi60", "486749122386");

						// load student info
	int num_students = 5;

	CircDLelement<StudentInfo> *el[5];
         					// create the list elements with student data 
	el[0] = new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				 9.0
			), "");
	el[1] = new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				 11.0
			), "");
	el[2] = new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				 12.0
			), "");
	el[3] = new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"green",
				"magenta",
				 9.0
			), "");
	el[4] = new CircDLelement<StudentInfo>(
			StudentInfo(
				"00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"cyan",
				 15.0
			), "");

	int numStudents = 5;

	CircDLelement<StudentInfo> *head = nullptr, *current;
	for(int i = 0; i < numStudents; i++)  {
		if (i > 0)
			head = insertFront(head, el[i]);
		else head = el[0];
	}
                            // add visual attributes
	current = head;
	do {
		StudentInfo si = current->getValue();

		current->getVisualizer()->setColor(si.getFavoriteColor());
		current->getLinkVisualizer(current->getNext())->setColor(si.getDislikeColor());
		double c = si.getStudentCreditHours()*0.75;
		current->getLinkVisualizer(current->getNext())->setThickness(8.0f);
		
		current = current->getNext();
	} while(current != head);

	Bridges::setDataStructure(head);
	Bridges::visualize();

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
