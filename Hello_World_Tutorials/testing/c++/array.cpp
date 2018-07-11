#include "Bridges.h"
#include "Array.h"

using namespace bridges;

int main() {

	Bridges::initialize(0, "kalpathi60", "486749122386");

	Array<int> *arr = new Array<int>(10);

	for (int j = 0; j < 10; j++) {
		arr->getElement(j).setValue(j * j);
		arr->getElement(j).setLabel(to_string(arr->getElement(j).getValue()));
	}

	arr->getElement(0).getVisualizer()->setColor(Color("red"));
	arr->getElement(1).getVisualizer()->setColor(Color("green"));
	arr->getElement(2).getVisualizer()->setColor(Color("blue"));
	arr->getElement(3).getVisualizer()->setColor(Color("cyan"));
	arr->getElement(4).getVisualizer()->setColor(Color("magenta"));
	arr->getElement(5).getVisualizer()->setColor(Color("yellow"));
	arr->getElement(6).getVisualizer()->setColor(Color("red"));
	arr->getElement(7).getVisualizer()->setColor(Color("green"));
	arr->getElement(8).getVisualizer()->setColor(Color("blue"));
	arr->getElement(9).getVisualizer()->setColor(Color("black"));


	Bridges::setTitle("Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
