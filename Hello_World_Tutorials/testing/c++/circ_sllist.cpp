/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircSLelement.h"
#include "StudentInfo.h"

using namespace bridges;

int main () {

						// note: you must fill in with your Bridges credentials
	Bridges::initialize(6, "kalpathi60", "486749122386");
//	Bridges::initialize(6, "bridges_public", "997924677918");

         					// create the linked list elements with 
							// student data 
	CircSLelement<StudentInfo> *students[] = {
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				 9.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				 11.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				 12.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"green",
				"magenta",
				 9.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"cyan",
				 15.0
			), "") 
		};

	CircSLelement<StudentInfo> *head =  students[0];
	CircSLelement<StudentInfo> *current =  head;

	int num_students = 5;
	for(int i = 1; i < num_students-1; i++) {
		current->setNext(students[i]);
		current = current->getNext();
	}
						//  point the last element to the first element,
	current->setNext(head);

       					//  add visual attributes
	current = head;
	do {
		current->setLabel(current->getValue().getStudentLabel());
		current->getVisualizer()->setColor(current->getValue().getFavoriteColor());
		
		current->getLinkVisualizer(current->getNext())->setColor(current->getValue().getDislikeColor());
		current->getLinkVisualizer(current->getNext())->setThickness(current->getValue().getStudentCreditHours()*0.75);
		
		current = current->getNext();
	}   while(current!= head);


						// set data structure to point to head
	Bridges::setDataStructure(head);
						// visualize the circular list
	Bridges::visualize();
}
