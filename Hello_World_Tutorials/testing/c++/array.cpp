#include "Bridges.h"
#include "Array.h"

using namespace bridges;

int main() {

	Bridges::initialize(0, "kalpathi60", "486749122386");
//  Bridges::initialize(0, "bridges_public", "997924677918");

	int dims[3] = {10, 1, 1};
	Array<int> *arr = new Array<int>(1, dims);

	for (int j = 0; j < dims[0]; j++) {
		arr->getValue(j).setValue(j*j);
		arr->getValue(j).setLabel(to_string(arr->getValue(j).getValue()));
	}

	arr->getValue(0).getVisualizer()->setColor(Color("red"));
	arr->getValue(1).getVisualizer()->setColor(Color("green"));
	arr->getValue(2).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(4).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(5).getVisualizer()->setColor(Color("yellow"));
	arr->getValue(6).getVisualizer()->setColor(Color("red"));
	arr->getValue(7).getVisualizer()->setColor(Color("green"));
	arr->getValue(8).getVisualizer()->setColor(Color("blue"));
	arr->getValue(9).getVisualizer()->setColor(Color("black"));
	

	Bridges::setTitle("Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
