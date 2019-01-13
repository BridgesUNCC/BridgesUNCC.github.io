/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "SLelement.h"
#include "StudentInfo.h"

using namespace bridges;

int main (int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");

	// create the linked list elements with
	// student data
	SLelement<StudentInfo> *el0 = new SLelement<StudentInfo>(
		StudentInfo(
			"00000000000",
			"Gretel Chaney",
			"CS",
			"g.chaney@generated.com",
			"magenta",
			"blue",
			9.0
		), "");
	SLelement<StudentInfo> *el1 = new SLelement<StudentInfo>(
		StudentInfo(
			"00000000001",
			"Karol Soderman",
			"SIS",
			"k.soderman@generated.com",
			"magenta",
			"red",
			11.0
		), "");
	SLelement<StudentInfo> *el2 = new SLelement<StudentInfo>(
		StudentInfo(
			"00000000002",
			"Lamont Kyler",
			"BIO",
			"l.kyler@generated.com",
			"yellow",
			"green",
			12.0
		), "");
	SLelement<StudentInfo> *el3 = new SLelement<StudentInfo>(
		StudentInfo(
			"00000000003",
			"Gladys Serino",
			"CS",
			"g.serino@generated.com",
			"green",
			"magenta",
			9.0
		), "");
	SLelement<StudentInfo> *el4 = new SLelement<StudentInfo>(
		StudentInfo(
			"00000000004",
			"Starr Mcginn",
			"CS",
			"s.mcginn@generated.com",
			"red",
			"cyan",
			15.0
		), "");

	//  link the elements
	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);

	// iterate through the list and add visual attributes
	// to the elements; set the element color to the favorite
	// color and the link to the disliked color
	SLelement<StudentInfo> *currentElement = el0;
	while (currentElement != nullptr) {
		// color the node
		StudentInfo si = currentElement->getValue();
		currentElement->getVisualizer()->setColor(si.getFavoriteColor());

		if (currentElement->getNext() != nullptr) {

			// color the link
			currentElement->getLinkVisualizer(currentElement->getNext())->setColor(si.getDislikeColor());
			// adjust link thickness
			currentElement->getLinkVisualizer(currentElement->getNext())->setThickness(5.0);//75 percent thinner
		}

		// set the label to the student info (label created in
		// StudentInfo class
		currentElement->setLabel(si.getStudentLabel());

		currentElement = currentElement->getNext();
	}

	bridges->setDataStructure(el0);
	bridges->visualize();
}
