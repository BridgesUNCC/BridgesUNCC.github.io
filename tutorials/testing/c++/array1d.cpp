#include "Bridges.h"
#include "Array1D.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// title, description
	bridges.setTitle("One-Dimensional Array Example");
	bridges.setDescription("Illustrates a one dimensional array with visual attributes");

	// create, populate the array
	Array1D<int> arr (10);

	// populate the array, with squares of indices
	// use the values to label the elements
	for (int j = 0; j < 10; j++) {
		arr[j] = j * j;
		arr.getElement(j).setLabel(to_string(arr[j]));
	}

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

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
