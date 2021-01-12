#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// This tutorial illustrates using the Bridges Color Grid
// and how to set elements within the grid

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title
	bridges.setTitle("BRIDGES Color Grid Tutorial - Part 1");

	// set description
	bridges.setDescription("This is an example of the color grid with height and width of 10 units each");

	int width = 10, height = 10;

	// create a 10 by 10 color grid  and initialize the grid to be all red
	// all supported colors are stated in the Color class
	ColorGrid cg(height, width, Color("lightgoldenrodyellow"));

	// color a few squares and make a + sign at the center

	cg.set(5, 5, Color("red"));
	cg.set(5, 4, Color("blue"));
	cg.set(5, 6, Color("blue"));
	cg.set(4, 5, Color("green"));
	cg.set(6, 5, Color("green"));

	// tell Bridges the the color grid object to visualize
	bridges.setDataStructure(&cg);

	// visualize
	bridges.visualize();

	return 0;
}
