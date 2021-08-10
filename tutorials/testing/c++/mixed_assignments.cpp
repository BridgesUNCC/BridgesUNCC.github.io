#include "TreeElement.h"
#include "CircSLelement.h"
#include "Array2D.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Color.h"
#include "ColorGrid.h"
#include "SymbolCollection.h"

using namespace bridges;
using namespace std;

int main(int argc, char **argv) {
	//create the Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// Tree
	TreeElement<string> *t0 = new TreeElement<string>("Root");
	TreeElement<string> *t1 = new TreeElement<string>("Child1");
	TreeElement<string> *t2 = new TreeElement<string>("Child2");
	TreeElement<string> *t3 = new TreeElement<string>("Child3");

	// add links to children
	t0->addChild(t1);
	t0->addChild(t2);
	t0->addChild(t3);

	// set some visual attributes
	t0->setColor("red");
	t0->setShape(DIAMOND);
	t0->setOpacity(0.5f);

	// set data structure and visualize
	bridges.setTitle("A multiple subassignment example");
	bridges.setDataStructure(t0);
	bridges.visualize();

	delete t0;
	delete t1;
	delete t2;
	delete t3;
	
	
	// circular list
	CircSLelement<string> *head = new CircSLelement<string>("", "head");
	CircSLelement<string> *csl1 = new CircSLelement<string>("", "el1");
	CircSLelement<string> *csl2 = new CircSLelement<string>("", "el2");
	CircSLelement<string> *tail = new CircSLelement<string>("", "tail");

	// add links to list
	head->setNext(csl1);
	csl1->setNext(csl2);
	csl2->setNext(tail);
	tail->setNext(head);

	// set data structure and visualize
	bridges.setTitle("A small circular singly linked list");
	bridges.setDataStructure(head);
	bridges.visualize();


	delete head;
	delete csl1;
	delete csl2;
	delete tail;

	
	// 2D Array 
	int num_rows = 4, num_cols = 4;
	Array2D<int> my_array (num_rows, num_cols);

	// populate the array
	for (int row = 0; row < num_rows; row++) {
		for (int col = 0; col < num_cols; col++) {
			my_array.getElement(row, col).setLabel("El " +
				std::to_string (row * num_cols + col));
		}
	}

	// set a color
	my_array.getElement(0, 0).setColor("purple");

	// set data structure and visualize
	bridges.setTitle("A 2D Array");
	bridges.setDataStructure(my_array);
	bridges.visualize();

	
	// Shape collection
	SymbolCollection sc;

	Rectangle r1 (0.0f, 0.0f, 25, 25);
	r1.setFillColor("black");
	sc.addSymbol(r1);

	Circle s1 (25.0f, 0.0f, 10);
	s1.setFillColor("yellow");
	sc.addSymbol(s1);

	Circle s2 (-25.0f, 0.0f, 10);
	s2.setFillColor("yellow");
	sc.addSymbol(s2);

	Circle s3 (0.0f, 25.0f, 10);
	s3.setFillColor("yellow");
	sc.addSymbol(s3);

	Circle s4 (0.0f, -25.0f, 10);
	s4.setFillColor("yellow");
	sc.addSymbol(s4);

	// set data structure and visualize
	bridges.setTitle("A Symbol Collection");
	bridges.setDataStructure(sc);
	bridges.visualize();


	// color grid
	int rows = 30, cols = 30;

	ColorGrid cg  (rows, cols, Color("purple"));

	cg.set(12, 12, Color("black"));
	cg.set(12, 18, Color("black"));

	for (int i = 0; i < 10; i++) {
		cg.set(18, 10 + i, Color("black"));
	}

	// set data structure and visualize
	bridges.setTitle("Color Grid Example");
	bridges.setDataStructure(cg);
	bridges.visualize();
}
