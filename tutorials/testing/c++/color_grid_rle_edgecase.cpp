#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// This example illustrates using the Bridges color grid
// We will build a checker grid using two different colors

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title, description
	bridges.setTitle("A CheckerBoard Example Using Grid Type");
	bridges.setDescription("This is an example of the color grid with height and width 10. "
		"This example alternates between blue and red starting with red at the top left corner of the grid.");
	int width = 128;
	int height = 128;

	ColorGrid cg(width, height, Color("red"));

	// color the square
	for (int row = 0; row < width; row++)
	  for (int column = 0; column < height; column++)
	    cg.set(row, column, Color("blue"));

	bridges.setDataStructure(&cg);

	bridges.visualize();

	return 0;
}
