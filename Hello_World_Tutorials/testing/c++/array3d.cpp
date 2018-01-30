#include <iostream>
#include <string>

using namespace std;


#include "Bridges.h"
#include "Element.h"
#include "Array.h"

using namespace bridges;
int main() {

	Bridges::initialize(0, "YOUR_API_KEY", "YOUR_USER_ID");

	int dims[3] = {4, 4, 4};
	Array<string> *arr = new Array<string> (3, dims);

	for (int k = 0; k < dims[0]; k++)
	for (int j = 0; j < dims[1]; j++)
	for (int i = 0; i < dims[2]; i++)
		arr->getValue(i, j, k).setLabel("El " + to_string(i*dims[0]+j));

	arr->getValue(0,0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3,0).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3,0).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1,0).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2,0).getVisualizer()->setColor(Color("yellow"));


	Bridges::setTitle("Array 3D Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
