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
// In part 2 of this tutorial we demonstrate how we can style the nodes and links
// of the singly linked list  and displays them
//
// Reference: SLelement, Bridges classes, ElementVisualizer, LinkVisualizer, Color
//
int main (int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
	// set title
	bridges.setTitle("A Singly Linked List Example");

	// set  description
	bridges.setDescription("Demonstrate styling linked list nodes and links"); 

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

	// now we want to style the nodes and links to illustrate the visual
	// attributes that can be applied to elements and links between links
    // Elements have color, opacity, shape and opacity attributes. Links
	// have color, thickness and label attributes

	 // set colors for list elements - see the Color class for supported colors
    st0->setColor("red");
    st2->setColor("aliceblue");

    // color the links - must specify a valid terminating element
    st0->getLinkVisualizer(st1)->setColor("green");
    st3->getLinkVisualizer(st4)->setColor("magenta");

    // adjust link thickness
    st2->getLinkVisualizer(st3)->setThickness(5.0f);

    // set node transparency
    st4->setOpacity (0.5f);

	// set link labels
    st0->getLinkVisualizer(st1)->setLabel("Gretel Chaney --> Lamont Kyler");

	// set shape of node
    st2->setShape(SQUARE);
	st4->setShape (TRIANGLE);

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
