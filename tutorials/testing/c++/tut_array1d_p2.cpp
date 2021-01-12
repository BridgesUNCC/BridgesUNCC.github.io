#include "Bridges.h"
#include "Array1D.h"

using namespace bridges;

// Part 2 of this tutorial describes how to style arrays created using BRIDGES 
// We will use the sam array as Part 1 

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// set title
	bridges.setTitle("A One-Dimensional Array Example");

	// set description
	bridges.setDescription("Demonstrate styling 1D array elements with visual attributes");

	// create, populate the array
	Array1D<int> arr (10);

	// populate the array, with squares of indices
	for (int j = 0; j < 10; j++) {
		arr[j] = j * j;

		// use the array values to label the elements
		// must use getElement() method to access the element to set properties
		arr.getElement(j).setLabel(to_string(arr[j]));
	}

	// style the array - only color, opacity and label are supported for arrays
	
	// color the elements
	// set visual attributes
    arr.getElement(0).setColor("red");
    arr.getElement(1).setColor("green");
    arr.getElement(2).setColor("blue");
    arr.getElement(3).setColor("cyan");
    arr.getElement(4).setColor("magenta");
    arr.getElement(5).setColor("yellow");
    arr.getElement(6).setColor("red");
    arr.getElement(7).setColor("green");
    arr.getElement(8).setColor("blue");
    arr.getElement(9).setColor("black");

	// opacity
	arr.getElement(3).setOpacity(0.2f);
	arr.getElement(9).setOpacity(0.2f);

	// provide BRIDGES a handle to the data structure
	bridges.setDataStructure(&arr);

	// visualize
	bridges.visualize();

	return 0;
}
