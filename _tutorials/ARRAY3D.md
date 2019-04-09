---
layout: post
title: "Tutorial: 3D Array"
redirect-from: /Hello_World_Tutorials/ARRAY3D.html
---

`Array<E>` implements a array in BRIDGES, and it can be used to create arrays of type `Element<E>`

{% capture java %}

### Create a new .java file

### Imports

-   We need to include these Bridges files to give access to all the classes/methods needed to interact with Bridges

	import bridges.connect.Bridges;
	import bridges.base.Array;
	import bridges.base.Element;

### Main Exception

-   By adding a throw exception we can forgo messy try/catch blocks in our code for our Bridges calls
-   In your .java file, add a throw exception to the main function so it looks like this:

	public static void main(String\[\] args) throws Exception

### Inside our Main

-   First we need to create our BRIDGES object and initialize our BRIDGES Credentials

	Bridges bridge = new Bridges(3, "YOUR\_API\_KEY", "YOUR\_USER\_ID");

**Note that you will need to replace the two fields in this call with your BRIDGES credentials.**

-   Specify array dimensions, create the 3D Array

	int\[\] dims = { 4, 4, 4 };
	Array<Integer> my\_array = new Array<Integer> (3, dims);

-   Now populate the 3d array with dummy data.

	int n  = 0;
	for (int k = 0; k < dims\[2\]; k++) {
		for (int j = 0; j < dims\[1\]; j++) {
			for (int i = 0; i < dims\[0\]; i++) {
					my\_array.setValue(i, j, k, new Element(String.valueOf(n), n));
				n++;
			}
		}
	}

-   Now change the color of specific elements.

	my\_array.getValue(0, 3, 0).getVisualizer().setColor(0, 255, 255, 1.0f);
	my\_array.getValue(0, 3, 1).getVisualizer().setColor("green");
	my\_array.getValue(0, 3, 2).getVisualizer().setColor("blue");
	my\_array.getValue(0, 3, 3).getVisualizer().setColor("magenta");

-   Now we pass the array object to BRIDGES

	bridge.setDataStructure(my\_array);

-   Finally we call the visualize function

	bridge.visualize();

#### Code summary

import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr3d {
	public static void main(String\[\] args) throws Exception{

							//create the Bridges object
		Bridges bridges = new Bridges(3, "YOUR\_API\_KEY", "YOUR\_USER\_ID");

						// specify array dimensions and create 3D array
		int\[\] dims = {4, 4, 4};
		Array<Integer> my\_array = new Array<Integer> (3, dims);

						// populate the elements with their array position
		int n  = 0;
		for (int k = 0; k < dims\[0\]; k++) {
			for (int j = 0; j < dims\[1\]; j++) {
				for (int i = 0; i < dims\[2\]; i++) {
					my\_array.setValue(i, j, k, new Element<Integer>(String.valueOf(n), n));
					n++;
				}
			}
		}
							// color some of the elements
		my\_array.getValue(0, 3, 0).getVisualizer().setColor(0, 255, 255, 1.0f);
		my\_array.getValue(0, 3, 1).getVisualizer().setColor("green");
		my\_array.getValue(0, 3, 2).getVisualizer().setColor("blue");
		my\_array.getValue(0, 3, 3).getVisualizer().setColor("magenta");

						//set visualizer type
		bridges.setDataStructure(my\_array);

						// visualize the list
		bridges.visualize();
	}
}

{% endcapture %}

{% capture cxx %}

### Includes

-   We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges
-   In your .cpp file, enter the following code snippets:

#include "Bridges.h"
#include "Element.h"

### Namespace

-   By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls
-   In your .cpp file, enter the following code snippet:

using namespace bridges;

### Inside our Main

-   First we need to initialize our Bridges Credentials

Bridges::initialize(1, "YOUR\_USER\_ID", "YOUR\_API\_KEY");

Note that you must replace the two strings above with your BRIDGES credentials.

-   Then we can create our 3D Array

int dims\[3\] = {4, 4, 4};
Array \*arr = new Array(3, dims);

-   Now populate the 3d array with dummy data.

for (int k = 0; k < dims\[0\]; i++)
for (int j = 0; j < dims\[1\]; j++)
for (int i = 0; i < dims\[2\]; i++)
			arr->getValue(i, j, k).setLabel("El " + to\_string(i\*dims\[0\]+j));

-   Now change the color of specific elements.

arr->getValue(0,0,0).getVisualizer()->setColor(Color("red"));
arr->getValue(0,3,0).getVisualizer()->setColor(Color("green"));
arr->getValue(3,0,0).getVisualizer()->setColor(Color("blue"));
arr->getValue(3,3,0).getVisualizer()->setColor(Color("magenta"));
arr->getValue(1,1,0).getVisualizer()->setColor(Color("cyan"));
arr->getValue(2,2,0).getVisualizer()->setColor(Color("yellow"));

-   Now we pass the first element of our singly linked list to Bridges

Bridges::setDataStructure(&e0;);

-   Finally we call the visualize function

Bridges::visualize();

#### Code summary

#include <iostream>
#include <string>

using namespace std;


#include "Bridges.h"
#include "Element.h"
#include "Array.h"

using namespace bridges;
int main() {

	Bridges::initialize(0, "YOUR\_API\_KEY", "YOUR\_USER\_ID");

	int dims\[3\] = {4, 4, 4};
	Array<string> \*arr = new Array<string> (3, dims);

	for (int k = 0; k < dims\[0\]; k++)
	for (int j = 0; j < dims\[1\]; j++)
	for (int i = 0; i < dims\[2\]; i++)
		arr->getValue(i, j, k).setLabel("El " + to\_string(i\*dims\[0\]+j));

	arr->getValue(0,0,0).getVisualizer()->setColor(Color("red"));
	arr->getValue(0,3,0).getVisualizer()->setColor(Color("green"));
	arr->getValue(3,0,0).getVisualizer()->setColor(Color("blue"));
	arr->getValue(3,3,0).getVisualizer()->setColor(Color("magenta"));
	arr->getValue(1,1,0).getVisualizer()->setColor(Color("cyan"));
	arr->getValue(2,2,0).getVisualizer()->setColor(Color("yellow"));


	Bridges::setTitle("Array 3D Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
{% endcapture %}

{% include tutorial.html %}

### Bridges Visualization

-   Once all your code is in order, run your file.
-   Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
-   Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
-   It should look something like this:

<iframe src="https://bridges-cs.herokuapp.com/assignments/2/bridges_public">

Well done! You’ve just created your 3D Array!