---
layout: post
title: "Tutorial: 2D Array"
redirect-from: /Hello_World_Tutorials/ARRAY2D.html
---

Array<E> implements a _array_ in BRIDGES, and it can be used to create arrays of type Element<E>

{% capture java %}

## Imports

We need to include these Bridges files to give access to all the classes/methods needed to interact with Bridges.
In your .java file, enter the following code snippets:

```java
import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;
```

## Main Exception

By adding a throw exception we can forgo messy try/catch blocks in our code for our Bridges calls.
In your .java file, add a throw exception to the main function so it looks like this:

```java
public static void main(String[] args) throws Exception
```

## Inside our Main

First we need to create our BRIDGES object and initialize our BRIDGES Credentials

```java
Bridges bridge = new Bridges(2, "YOUR_API_KEY", "YOUR_USER_ID");
```

**Note that you will need to replace the two fields in this call with your BRIDGES credentials.**

Then we can create our 2D Array

```java
int columns = 5;
int rows = 5;
int[] dims = {columns, rows, 1}
Array<Integer> my_array = new Array<Integer> (2, dims);
```

Now populate the 2d array with dummy data.

```java
for (int rowAt = 0; rowAt < rows; k++) {
	for (int columnAt = 0; columnAt < columns; k++) {
		my_array.setValue(rowAt, columnAt,  new Element<Integer>(String.valueOf(k), k*k));
		k++;
	}
}
```

Now change the color of the elements.

```java
my_array.getValue(0,0).getVisualizer().setColor("green");
my_array.getValue(0,4).getVisualizer().setColor("blue");
my_array.getValue(2,2).getVisualizer().setColor("magenta");
my_array.getValue(4,0).getVisualizer().setColor("cyan");
my_array.getValue(4,4).getVisualizer().setColor("yellow");
```

Now we pass the array object to BRIDGES

```java
bridge.setDataStructure(my_array);
```

Finally we call the visualize function

```java
bridge.visualize();
```

### Code summary

```java
{% include_relative testing/java/arr2d.java %}
```

{% endcapture %}

{% capture cxx %}

## Includes

We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges.
In your .cpp file, enter the following code snippets:

```c++
#include "Bridges.h"
#include "Element.h"
#include "Array.h"
```

## Namespace

By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls.
In your .cpp file, enter the following code snippet:

```c++
using namespace bridges;
```

## Inside our Main

First we need to initialize our Bridges Credentials

```c++
Bridges::initialize(1, "YOUR_USER_ID", "YOUR_API_KEY");
```

Note that you must replace the two strings above with your BRIDGES credentials.

Then we can create our 2D Array

```c++
int dims[3] = {4, 4, 1};
Array<string> *arr = new Array<string>(2, dims);
```

Now populate the 2d array with dummy data.

```c++
for (int i = 0; i < dims[1]; i++)
	for (int j = 0; j < dims[0]; j++)
		arr->getValue(i,j).setLabel("El " + to_string(i*dims[0]+j));
```

Now change the color of specific elements.

```c++
arr->getValue(0,0).getVisualizer()->setColor(Color("red"));
arr->getValue(0,3).getVisualizer()->setColor(Color("green"));
arr->getValue(3,0).getVisualizer()->setColor(Color("blue"));
arr->getValue(3,3).getVisualizer()->setColor(Color("magenta"));
arr->getValue(1,1).getVisualizer()->setColor(Color("cyan"));
arr->getValue(2,2).getVisualizer()->setColor(Color("yellow"));
```

Now we pass the array object to BRIDGES.

```c++
Bridges::setDataStructure(&e0;);
```

Finally we call the visualize function.

```c++
Bridges::visualize();
```

### Code summary

```c++
{% include_relative testing/cxx/array2d.cpp %}
```
{% endcapture %}

{% include tutorial.html %}

## Bridges Visualization

Once all your code is in order, run your file.
Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
It should look something like this:

<iframe src="https://bridges-cs.herokuapp.com/assignments/1/bridges_public">

Well done! You’ve just created your 2D array!