#include <iostream>
#include <string>
#include "Array3D.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// title, description
	bridges.setTitle("Three-Dimensional Array Example");

		
	// create, populate 3D array
	Array3D<std::string> arr (4, 4, 4);

	arr[0][1][2] = "hi there";
	arr.getElement(0, 1, 2).setLabel(arr[0][1][2]);
	arr.getElement(0, 1, 2).setColor("white");
	
	arr.getElement(0, 0, 0).setColor("red");
	arr.getElement(0, 3, 0).setColor("green");

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
