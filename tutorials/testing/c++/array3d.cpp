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
	bridges.setDescription("A 3 dimensional array with visual attributes. The third dimension is illustrated as a sequence of 2D slices");


	// specify array dimensions and create 3D array
	int num_slices = 4, num_rows = 4, num_cols = 4;

	// create, populate 3D array
	Array3D<int> my_array (4, 4, 4);

	// populate the elements with their array position
	int n  = 0;
	for (int k = 0; k < num_slices; k++)
		for (int j = 0; j < num_rows; j++)
			for (int i = 0; i < num_cols; i++) {
				my_array.getElement(k, j, i).setLabel("El " + std::to_string(n));
				n++;
			}


	// color some of the elements
	my_array.getElement(0, 0, 0).setColor("red");
	my_array.getElement(0, 3, 0).setColor("green");
	my_array.getElement(1, 1, 0).setColor("cyan");
	my_array.getElement(2, 2, 0).setColor("yellow");
	my_array.getElement(3, 0, 0).setColor("blue");
	my_array.getElement(3, 3, 3).setColor("magenta");

	// visualize
	bridges.setDataStructure(my_array);
	bridges.visualize();

	return 0;
}
