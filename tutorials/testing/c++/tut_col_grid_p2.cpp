#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// The second  part of the tutorial illustrates using the different ways
// to specify color for cells in the color grid.

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("BRIDGES Color Grid Tutorial - Part 2");

	// set description
	bridges.setDescription("This is an example to illustrate different ways of setting colors in the ColorGrid");


	// create a 10 by 10 color grid  and initialize the grid to be all 
	// light yellow

	int width = 10, height = 10;
	ColorGrid cg(height, width, Color("lightgoldenrodyellow"));

	// color a few squares and make a + sign at the center using named colors
    cg.set(5, 5, Color("red"));
    cg.set(5, 4, Color("blue"));
    cg.set(5, 6, Color("blue"));
    cg.set(4, 5, Color("green"));
    cg.set(6, 5, Color("green"));

	// tell BRIDGES the handle to the color grid object
	bridges.setDataStructure(&cg);

	// visualize
	bridges.visualize();

	// you can also use r,g, b, triplets to specify color (in the range 0-255)
    cg.set(5, 5, Color(255,0, 0));
    cg.set(5, 4, Color(0, 0, 255));
    cg.set(5, 6, Color(0, 0, 255));
    cg.set(4, 5, Color(0, 255, 0));
    cg.set(6, 5, Color(0, 255, 0));

	// visualize again
	bridges.visualize();

	// you can also specify a fourth component, opacity (alpha) to make
	// colors transparent. We will choose 128, halfway
    cg.set(5, 5, Color(255,0, 0, 128));
    cg.set(5, 4, Color(0, 0, 255, 128));
    cg.set(5, 6, Color(0, 0, 255, 128));
    cg.set(4, 5, Color(0, 255, 0, 128));
    cg.set(6, 5, Color(0, 255, 0, 128));

	// visualize again -- note that you will see tabs to switch between 
	// the 3 visualizations
	bridges.visualize();

	return 0;
}
