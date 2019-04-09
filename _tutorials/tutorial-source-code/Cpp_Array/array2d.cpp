#include &lt;string&gt;
#include "Bridges.h"
#include "Array.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(1, "YOUR_USER_ID", "YOUR_API_KEY");

	int dims[3] = {4, 4, 1};
	Array&lt;string&gt; *arr = new Array&lt;string&gt;(2, dims);

	for (int i = 0; i < dims[1]; i++)
	for (int j = 0; j < dims[0]; j++)
		arr->getValue(i,j).setLabel("El " + to_string(i*dims[0]+j));

	arr->getValue(0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2).getVisualizer()->setColor(Color("yellow"));
	

	Bridges::setTitle("Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
