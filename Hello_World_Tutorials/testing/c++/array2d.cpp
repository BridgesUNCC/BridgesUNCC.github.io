#include <string>
#include "Bridges.h"
#include "Array.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	Bridges *bridges =  new Bridges(101, "YOUR_USER_ID", "YOUR_API_KEY");

	if (argc == 4)	// Server type provided
		bridges->setServer(argv[3]);

	int dims[3] = {4, 4, 1};
	Array<string> *arr = new Array<string>(4, 4);

	for (int i = 0; i < dims[1]; i++)
		for (int j = 0; j < dims[0]; j++)
			arr->getElement(i, j).setLabel("El " + to_string(i * dims[0] + j));

	arr->getElement(0, 0).getVisualizer()->setColor(Color("red"));
	arr->getElement(0, 3).getVisualizer()->setColor(Color("green"));
	arr->getElement(3, 0).getVisualizer()->setColor(Color("blue"));
	arr->getElement(3, 3).getVisualizer()->setColor(Color("magenta"));
	arr->getElement(1, 1).getVisualizer()->setColor(Color("cyan"));
	arr->getElement(2, 2).getVisualizer()->setColor(Color("yellow"));


	bridges->setTitle("2D Array Example");
	bridges->setDataStructure(arr);
	bridges->visualize();

	return 0;
}
