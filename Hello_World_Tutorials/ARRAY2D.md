Array<E> implements a _array_ in BRIDGES, and it can be used to create arrays of type Element<E>

	## 2D Array - An Example BRIDGES program
	
	Java
	
	C++
	
	### Create a new .java file
	
	### Imports
	
	-   We need to include these Bridges files to give access to all the classes/methods needed to interact with Bridges
	-   In your .java file, enter the following code snippets:
	
		import bridges.connect.Bridges;
		import bridges.base.Array;
		import bridges.base.Element;
	
	### Main Exception
	
	-   By adding a throw exception we can forgo messy try/catch blocks in our code for our Bridges calls
	-   In your .java file, add a throw exception to the main function so it looks like this:
	
		public static void main(String\[\] args) throws Exception
	
	### Inside our Main
	
	-   First we need to create our BRIDGES object and initialize our BRIDGES Credentials
	
		Bridges bridge = new Bridges(2, "YOUR\_API\_KEY", "YOUR\_USER\_ID");
	
	**Note that you will need to replace the two fields in this call with your BRIDGES credentials.**
	
	-   Then we can create our 2D Array
	
		int columns = 5;
		int rows = 5;
		int\[\] dims = {columns, rows, 1}
		Array<Integer> my\_array = new Array<Integer> (2, dims);
	
	-   Now populate the 2d array with dummy data.
	
		for (int rowAt = 0; rowAt < rows; k++) {
			for (int columnAt = 0; columnAt < columns; k++) {
				my\_array.setValue(rowAt, columnAt,  new Element<Integer>(String.valueOf(k), k\*k));
				k++;
			}
		}
	
	-   Now change the color of the elements.
	
		my\_array.getValue(0,0).getVisualizer().setColor("green");
		my\_array.getValue(0,4).getVisualizer().setColor("blue");
		my\_array.getValue(2,2).getVisualizer().setColor("magenta");
		my\_array.getValue(4,0).getVisualizer().setColor("cyan");
		my\_array.getValue(4,4).getVisualizer().setColor("yellow");
	
	-   Now we pass the array object to BRIDGES
	
		bridge.setDataStructure(my\_array);
	
	-   Finally we call the visualize function
	
		bridge.visualize();
	
	#### **Code Summary:** Your .java file should look like this
	
	import bridges.connect.Bridges;
	import bridges.base.Array;
	import bridges.base.Element;
	
	public class arr2d {
		public static void main(String\[\] args) throws Exception{
	
							//create the Bridges object
			Bridges bridges = new Bridges(2, "YOUR\_API\_KEY", "YOUR\_USER\_ID");
	
							//  for 2D array 5x5
			int columns = 5;
			int rows = 5;
							// set dimensions, create array
			int\[\] dims = {columns, rows, 1};
			Array<Integer> my\_array = new Array<Integer> (2, dims);
	
							// populate the array
			int k = 0;
			for (int row = 0; row < rows; row++){
				for (int col = 0; col < columns; col++){
					my\_array.setValue(row, col,  new Element<Integer>(String.valueOf(k), k\*k));
					k++;
				}
			}
							// color some of the elements
			my\_array.getValue(0,0).getVisualizer().setColor("green");
			my\_array.getValue(0,4).getVisualizer().setColor("blue");
			my\_array.getValue(2,2).getVisualizer().setColor("cyan");
			my\_array.getValue(4,0).getVisualizer().setColor("magenta");
			my\_array.getValue(4,4).getVisualizer().setColor("yellow");
	
								//set visualizer type
			bridges.setDataStructure(my\_array);
	
								// visualize the array
			bridges.visualize();
		}
	}
	
	### Create a new .cpp file
	
	### Includes
	
	-   We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges
	-   In your .cpp file, enter the following code snippets:
	
	#include "Bridges.h"
	#include "Element.h"
	#include "Array.h"
					
	
	### Namespace
	
	-   By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls
	-   In your .cpp file, enter the following code snippet:
	
	using namespace bridges;
	
	### Inside our Main
	
	-   First we need to initialize our Bridges Credentials
	
	Bridges::initialize(1, "YOUR\_USER\_ID", "YOUR\_API\_KEY");
	
	Note that you must replace the two strings above with your BRIDGES credentials.
	
	-   Then we can create our 2D Array
	
	int dims\[3\] = {4, 4, 1};
	Array<string> \*arr = new Array<string>(2, dims);
	
	-   Now populate the 2d array with dummy data.
	
	for (int i = 0; i < dims\[1\]; i++)
	for (int j = 0; j < dims\[0\]; j++)
		arr->getValue(i,j).setLabel("El " + to\_string(i\*dims\[0\]+j));
	
	-   Now change the color of specific elements.
	
	arr->getValue(0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2).getVisualizer()->setColor(Color("yellow"));
	
	-   Now we pass the array object to BRIDGES.
	
	Bridges::setDataStructure(&e0;);
	
	-   Finally we call the visualize function.
	
	Bridges::visualize();
	
	#### **Code Summary:** Your .cpp file should look like this
	
	#include <iostream>
	#include <string>
	
	using namespace std;
	
	#include "Bridges.h"
	#include "Element.h"
	#include "Array.h"
	
	using namespace bridges;
	int main() {
			Bridges::initialize(1, "YOUR\_USER\_ID", "YOUR\_API\_KEY");
	
			int dims\[3\] = {4, 4, 1};
			Array<string> \*arr = new Array<string>(2, dims);
	
			for (int i = 0; i < dims\[1\]; i++)
			for (int j = 0; j < dims\[0\]; j++)
					arr->getValue(i,j).setLabel("El " + to\_string(i\*dims\[0\]+j));
	
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
	
	### Bridges Visualization
	
	-   Once all your code is in order, run your file.
	-   Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
	-   Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
	-   It should look something like this:
	
	<p>Sorry, your browser doesn't seem to support iframes - <a href="/assignments/1/bridges_public">Frame Link</a> </p>
	
	Well done! You’ve just created your 2D array!