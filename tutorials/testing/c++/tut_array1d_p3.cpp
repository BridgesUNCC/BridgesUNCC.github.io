#include "Bridges.h"
#include "Array1D.h"

using namespace bridges;

// Part 3 of this tutorial describes how to use iterators with arrays
// We will use the same example array 

int main(int argc, char **argv) {

	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// set title
	bridges.setTitle("A One-Dimensional Array Example");

	// set description
	bridges.setDescription("Illustrating looping and iterators in 1D Arrays");

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

	// Using a regular for loop on BRIDGES elements
	cout << "Using a regular for loop..\n"; 
	for (int j = 0; j < 10; j++)
		cout << "\t" << arr[j] << endl;

	cout << "Using a forward iterator..\n"; 
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
		cout << "\t" << *iter << endl;

	cout << "Using a range loop..\n"; 
    for (auto iter: arr) {
        cout << "\t" << iter << endl;
    }


	// provide BRIDGES a handle to the data structure
	bridges.setDataStructure(&arr);

	// visualize
	bridges.visualize();

	return 0;
}
