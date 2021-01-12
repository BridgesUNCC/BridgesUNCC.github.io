#include "Bridges.h"
#include "Array1D.h"

using namespace bridges;

// This tutorial describes how to create a 1 dimensional array, populate
// it with integer values and display them

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// set title
	bridges.setTitle("A One-Dimensional Array Example");

	// set description
	bridges.setDescription("Create a 1 dimensional array with integer values and display them");

	// create, populate the array
	Array1D<int> arr (10);

	// populate the array, with squares of indices
	// Note that you can use the [] operator to access the array values
	for (int j = 0; j < 10; j++) {
		arr[j] = j * j;

		// use the array values to label the elements 
		// must use getElement() method to access the element and set properties
		arr.getElement(j).setLabel(to_string(arr[j]));
	}

	// provide BRIDGES a handle to the data structure
	bridges.setDataStructure(&arr);

	// visualize
	bridges.visualize();

	return 0;
}
