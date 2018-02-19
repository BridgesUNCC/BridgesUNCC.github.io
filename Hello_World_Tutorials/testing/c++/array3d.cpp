#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

#define LOCAL_SERVER 0

#include "Bridges.h"
#include "Element.h"

using namespace bridges;
int main() {

	Bridges::initialize(2, "kalpathi60", "486749122386");
//	Bridges::initialize(2, "bridges_public", "997924677918");

	int dims[3] = {4, 4, 4};
	Array<string> *arr = new Array<string>(3, dims);

//	for (int i = 0; i < dims[1]; i++)
//	for (int j = 0; j < dims[0]; j++)
//		arr->getValue(0, i, j).setLabel("El " + to_string(i*dims[0]+j));

cout << "here.." << endl;
	arr->getValue(0,0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3,0).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3,0).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1,0).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2,0).getVisualizer()->setColor(Color("yellow"));

	

	Bridges::setTitle("Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
