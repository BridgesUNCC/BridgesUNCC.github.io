#include "Bridges.h"
#include "CircSLelement.h"
#include "StudentInfo.h"

using namespace bridges;
					// helper function
int main() {

	Bridges::initialize(600, "kalpathi60", "486749122386");

						// load student info
	int num_students = 5;

	CircSLelement<StudentInfo> *el[5];
         					// create the list elements with student data 
	el[0] = new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				 9.0
			), "");
	el[1] = new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				 11.0
			), "");
	el[2] = new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				 12.0
			), "");
	el[3] = new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"green",
				"magenta",
				 9.0
			), "");
	el[4] = new CircSLelement<StudentInfo>(
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
	CircSLelement<StudentInfo> *head = el[0], *current;
	StudentInfo si = el[3]->getValue();
	cout << "Label[0]:" << si.getFullName() << endl;

	for(int i = 0; i < numStudents-1; i++) 
		el[i]->setNext(el[i+1]);
							// connect the last element to the first
	el[4]->setNext(head);
	
                            // add visual attributes
	current = head;
	cout << head->getValue().getStudentLabel() << endl;
	do {
		cout << current->getValue().getStudentLabel() << endl;

		current->getVisualizer()->setColor(current->getValue().getFavoriteColor());
		
		current->getLinkVisualizer(current->getNext())->setColor(current->getValue().getDislikeColor());
		current->getLinkVisualizer(current->getNext())->setThickness(current->getValue().getStudentCreditHours()*0.75);
		
		current = current->getNext();
	} while(current != head);

	Bridges::setDataStructure(head);
	Bridges::visualize();

	return 0;
}
