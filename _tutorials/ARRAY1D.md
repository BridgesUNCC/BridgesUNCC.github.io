---
layout: post
title: "Tutorial: 1D Array"
redirect-from: /Hello_World_Tutorials/ARRAY1D.html
---

`Array<E>` implements an array in BRIDGES, and it can be used to create arrays of any generic type.

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
Bridges bridges = new Bridges(1, "YOUR_API_KEY", "YOUR_USER_ID");
```

**Note that you will need to replace the two fields in this call with your BRIDGES credentials.**

Then we can create our Array

```java
//declare array size, dimensions
int arraySize = 10;
int[] dims = {arraySize, 1, 1 }

Array<Integer> my_array = new Array<Integer> (1, dims);
```

Now populate the array with dummy data.

```java
for (int k = 0; k < my_array.getSize(); k++) {
    my_array.setValue(k, new Element<Integer>(String.valueOf(k), k*k));
    my_array.getValue(k).getVisualizer().setColor("red");
}
```

Now change the color of the elements.

```java
my_array.getValue(1).getVisualizer().setColor("green");
my_array.getValue(3).getVisualizer().setColor("blue");
my_array.getValue(5).getVisualizer().setColor("magenta");
my_array.getValue(7).getVisualizer().setColor("cyan");
my_array.getValue(9).getVisualizer().setColor("yellow");
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
{% include_relative testing/java/arr1d.java %}
```

{% endcapture %}

{% capture cxx %}

## Includes

We need to include these Bridges headers to give access to all the classes/methods needed to interact with Bridges.
In your .cpp file, enter the following code snippets:

```cpp
#include "Bridges.h"
#include "Element.h"
#include "Array.h"
```

## Namespace

By using this namespace we can forgo messy scope specifiers in our code for our Bridges calls.
In your .cpp file, enter the following code snippet:

```cpp
using namespace bridges;
```

## Inside our Main

First we need to initialize our Bridges Credentials

```cpp
Bridges::initialize(1, "YOUR_USER_ID", "YOUR_API_KEY",);
```

Note that you must replace the two strings above with your BRIDGES credentials.

Then we can create our Array, by specifying the dimensions.

```cpp
int dims[3] = {10, 1, 1};
Array<int> *el_array = new Array<int>(1, dims);
```          

Now populate the array with dummy data.

```cpp
for (int j = 0; j < 10; j++)
    el_array[j].setLabel("Element " + to_string(j));
```
          

Now change the color of the elements.

```cpp
arr->getValue(0).getVisualizer()->setColor(Color("red"));
arr->getValue(1).getVisualizer()->setColor(Color("green"));
arr->getValue(2).getVisualizer()->setColor(Color("blue"));
arr->getValue(3).getVisualizer()->setColor(Color("cyan"));
arr->getValue(4).getVisualizer()->setColor(Color("magenta"));
arr->getValue(5).getVisualizer()->setColor(Color("yellow"));
arr->getValue(6).getVisualizer()->setColor(Color("red"));
arr->getValue(7).getVisualizer()->setColor(Color("green"));
arr->getValue(8).getVisualizer()->setColor(Color("blue"));
arr->getValue(9).getVisualizer()->setColor(Color("black"));
```

Now we pass the first element of our singly linked list to Bridges

```cpp
Bridges::setDataStructure(el_array, 10);
```

Finally we call the visualize function

```cpp
Bridges::visualize();
```

### Code summary

```cpp
{% include_relative testing/cxx/array.cpp %}
```
{% endcapture %}

{% include tutorial.html %}

## Bridges Visualization

-   Once all your code is in order, run your file.
-   Assuming all your code is correct and it compiles correctly, a
    link to the Bridges website will be generated on the console.
-   Copy/paste this link into your favorite browser to view a visualization
    of the data structure you just created.
-   It should look something like this:

<iframe src="https://bridges-cs.herokuapp.com/assignments/0/bridges_public">

Well done! You’ve just created your 1D Array!
