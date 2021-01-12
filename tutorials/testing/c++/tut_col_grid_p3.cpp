#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// In the final part of this  tutorial we will build a checkerboard
// pattern using the ColorGrid

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("BRIDGES Color Grid Tutorial - Part 3");

	// set description
	bridges.setDescription("This example generates a checkerboard pattern");

	int width = 10, height = 10;

	// create a 10 by 10 color grid  and initialize the grid to be all red
	// all supported colors are stated in the Color class
	ColorGrid cg(height, width, Color("lightgoldenrodyellow"));

    // create a checkerboard pattern of  10 x 10 squares
    const int num_squares_x = 10;
    const int num_squares_y = 10;

	// compute square dimensions
	const int sq_width = width / num_squares_x, 
		sq_height = width / num_squares_y;

	for (int j = 0; j < num_squares_y;  j++)
	for (int k = 0; k < num_squares_x;  k++) {
		// use even/odd of pixel to figure out the color of the square
		bool x_even = (k % 2) == 0;
		bool y_even = (j % 2) == 0;

		string col;
		if (y_even)
			col = (x_even) ? "red" : "blue";
		else
			col = (x_even) ? "blue" : "red";

		// find the address of the square
		int origin_x = k * sq_width;
		int origin_y = j * sq_height;

		// color the square
		for (int row = origin_y; row < origin_y + sq_height; row++)
		for (int column = origin_x; column < origin_x + sq_width; column++)
			cg.set(row, column, Color(col));
	}

	// tell Bridges the the color grid object to visualize
	bridges.setDataStructure(&cg);

	// visualize
	bridges.visualize();

	return 0;
}
