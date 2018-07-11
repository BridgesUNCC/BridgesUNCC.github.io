#include <iostream>
#include <string>
#include "Array.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(2, "kalpathi60", "486749122386");

	Array<string> *arr = new Array<string>(4, 4, 4);

	arr->getElement(0, 0, 0).getVisualizer()->setColor(Color("red"));
	arr->getElement(0, 3, 0).getVisualizer()->setColor(Color("green"));
	arr->getElement(3, 0, 0).getVisualizer()->setColor(Color("blue"));
	arr->getElement(3, 3, 0).getVisualizer()->setColor(Color("magenta"));
	arr->getElement(1, 1, 0).getVisualizer()->setColor(Color("cyan"));
	arr->getElement(2, 2, 0).getVisualizer()->setColor(Color("yellow"));

	Bridges::setTitle("3D Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
