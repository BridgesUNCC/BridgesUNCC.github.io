#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"


using namespace bridges;

int main() {


						// initialize BRIDGES
	Bridges::initialize(14, "kalpathi60", "486749122386");
	Bridges::setTitle("A Color Grid Example");

	int width = 200, height = 200;

	ColorGrid *cg  = new ColorGrid(width, height, Color("red"));

						// create a checkerboard pattern
	const int num_squares_x = 10;
	const int num_squares_y = 10;
	const int sq_width = width/num_squares_x, sq_height = width/num_squares_y;
	for (int j = 0; j < num_squares_y;  j++) {
		for (int k = 0; k < num_squares_x;  k++)  {
						// find the address of the square
			bool x_even = (k%2) == 0;
			bool y_even = (j%2) == 0;

			string col; 
			if (y_even) 
				col = (x_even) ? "red" : "blue";
			else 
				col = (x_even) ? "blue" : "red"; 
								// color the square
			int origin_x = k*sq_width; 
			int origin_y = j*sq_height;

			for (int y = origin_y; y < origin_y+sq_height; y++)
			for (int x = origin_x; x < origin_x+sq_width; x++)
				cg->set(x, y, Color(col));
		}
	}

	Bridges::setDataStructure(cg);

	Bridges::visualize();

	return 0;
}
