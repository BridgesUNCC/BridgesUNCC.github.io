#include <string>
#include "Bridges.h"
#include "TreeElement.h"

using namespace bridges;
using std::string;

int main(int argc, char **argv) {


	Bridges bridges (1, "BRIDGEs_USER_ID", "BRIDGES_API_KEY");

	bridges.setTitle("An Expression Tree Example Using TreeElements");
	bridges.setDescription("A manually constructred expression tree for sqrt(Ax^2 + By + c");

	TreeElement<string> *a = new TreeElement<string>("a", "a");
	TreeElement<string> *x = new TreeElement<string>("x", "x");
	TreeElement<string> *x2 = new TreeElement<string>("x", "x");
	TreeElement<string> *b =  new TreeElement<string>("b", "b");
	TreeElement<string> *y =  new TreeElement<string>("y", "y");
	TreeElement<string> *c =  new TreeElement<string>("c", "c");
	TreeElement<string> *z =  new TreeElement<string>("z", "z");
	TreeElement<string> *times1 =  new TreeElement<string>("*", "*");
	TreeElement<string> *times2 =  new TreeElement<string>("*", "*");
	TreeElement<string> *times3 =  new TreeElement<string>("*", "*");
	TreeElement<string> *times4 =  new TreeElement<string>("*", "*");
	TreeElement<string> *plus1 =  new TreeElement<string>("+", "+");
	TreeElement<string> *plus2 =  new TreeElement<string>("+", "+");
	TreeElement<string> *plus3 =  new TreeElement<string>("+", "+");
	TreeElement<string> *qrt =  new TreeElement<string>("sqrt", "sqrt");


	// increase their size
	qrt->setSize(49.0);
	plus3->setSize(30.0);

	// add links to children

	times1->addChild(a);
	times1->addChild(x);

	times2->addChild(times1);
	times2->addChild(x2);

	times3->addChild(b);
	times3->addChild(y);

	plus1->addChild(times2);
	plus1->addChild(times3);

	times4->addChild (c);
	times4->addChild (z);

	plus2->addChild (times3);
	plus2->addChild (times4);

	plus3->addChild (plus1);
	plus3->addChild (times4);

	qrt->addChild(plus3);


	// mark the operators in  red
	times1->setColor("red");
	times2->setColor("red");
	times3->setColor("red");
	times4->setColor("red");
	plus1->setColor("red");
	plus2->setColor("red");
	plus3->setColor("red");
	qrt->setColor("red");

	// set link attributes, color, thickness
	qrt->setShape(SQUARE);
	qrt->getLinkVisualizer(plus3)->setColor("green");
	qrt->getLinkVisualizer(plus3)->setThickness(5.);
	plus3->getLinkVisualizer(plus1)->setThickness(3.);
	plus3->getLinkVisualizer(times4)->setThickness(3.);


	// link colors

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(qrt);

	bridges.visualize();

	
	return 0;
}
