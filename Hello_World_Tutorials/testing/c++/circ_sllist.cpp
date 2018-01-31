#include "Bridges.h"
#include "CircSLelement.h"
#include "StudentInfo.h"

using namespace bridges;
					// helper function
int main() {

	Bridges::initialize(600, "kalpathi60", "486749122386");

						// load student info
	int num_students = 5;
	StudentInfo students[] = {
				StudentInfo(
                      "00000000000",
                      "Gretel Chaney",
                      "CS",
                      "g.chaney@generated.com",
                      "magenta",
                      "blue",
                      9.0 
				),
				StudentInfo(
                      "00000000001",
                      "Karol Soderman",
                      "SIS",
                      "k.soderman@generated.com",
                      "magenta",
                      "red",
                      11.0
				),
				StudentInfo(
                      "00000000002",
                      "Lamont Kyler",
                      "BIO",
                      "l.kyler@generated.com",
                      "purple",
                      "green",
                      12.0
				),
				StudentInfo(
                      "00000000003",
                      "Gladys Serino",
                      "CS","g.serino@generated.com",
                      "blue",
                      "black",
                      9.0
				),
				StudentInfo("00000000004",
                      "Starr Mcginn",
                      "CS",
                      "s.mcginn@generated.com",
                      "red",
                      "cyan",
                      15.0)
			};

							// insert the students in front of the list
	CircSLelement<StudentInfo> *head = new CircSLelement<StudentInfo>(students[0], "");
	CircSLelement<StudentInfo> *current = head;

	int numStudents = 5;
	for(int i = 1; i < numStudents; i++) {
		current->setNext(new CircSLelement<StudentInfo>(students[i], ""));
		current = current->getNext();
	}
						// connect the last element to the first
	current->setNext(head);
	
                            // add visual attributes
	current = head;
	do {
		current->setLabel(current->getValue().getStudentLabel());
		cout << current->getValue().getFavoriteColor() << endl;

//		current->getVisualizer()->setColor(current->getValue().getFavoriteColor());
		
cout <<  "processing.." << endl;
//		current->getLinkVisualizer(current->getNext())->setColor(current->getValue().getDislikeColor());
//		current->getLinkVisualizer(current->getNext())->setThickness(current->getValue().getStudentCreditHours()*0.75);
		
		current = current->getNext();
	} while(current != head);



	Bridges::setDataStructure(head);
	Bridges::visualize();

	return 0;
}
