#include &lt;string&gt;
#include "Array.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main() {

	Bridges::initialize(2, "YOUR_USER_ID", "YOUR_API_KEY");

	int dims[3] = {4, 4, 4};
	Array&lt;string&gt; *arr = new Array&lt;string&gt;(3, dims);

	arr->getValue(0,0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3,0).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3,0).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1,0).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2,0).getVisualizer()->setColor(Color("yellow"));

	Bridges::setTitle("3D Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
