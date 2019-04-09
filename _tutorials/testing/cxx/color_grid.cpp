#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// This example illustrates using the Bridges color grid
// We will build a checker grid using two different colors

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");

	// set title for visualization
	bridges->setTitle("A Color Grid Example");

	int width = 200, height = 200;

	ColorGrid *cg  = new ColorGrid(width, height, Color("red"));

	// create a checkerboard pattern
	// 10 x 10 grid
	const int num_squares_x = 10;
	const int num_squares_y = 10;

	// compute square dimensions
	const int sq_width = width / num_squares_x, sq_height = width / num_squares_y;

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
			for (int y = origin_y; y < origin_y + sq_height; y++)
				for (int x = origin_x; x < origin_x + sq_width; x++)
					cg->set(x, y, Color(col));
		}

	bridges->setDataStructure(cg);

	bridges->visualize();

	return 0;
}
