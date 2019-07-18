#include <string>
#include "Bridges.h"
#include "Array2D.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// title, description
	bridges.setTitle("Two-Dimensional Array Example");
	bridges.setDescription("A TwoD array with four rows and four columns. "
						 "Row one left to right: red, neutral, neutral, blue. "
						 "Row two left to right: neutral, cyan, neutral, neutral. "
						 "Row three left to right: neutral, neutral, yellow, neutral. "
						 "Row four left to right: green, neutral, neutral, magenta.");

	// create, populate 2D array
	int rows = 5;
	int cols = 3;
	Array2D<int> arr(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		  arr[i][j] = i*100+j;
	
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		  arr.getElement(i, j).setLabel(std::to_string(arr[i][j]));

	// set visual attributes
	arr.getElement(0, 0).setColor("red");
	arr.getElement(0, 3).setColor("green");
	arr.getElement(5, 0).setColor("blue");
	arr.getElement(5, 3).setColor("magenta");
	arr.getElement(1, 1).setColor("cyan");
	arr.getElement(2, 2).setColor("yellow");

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
