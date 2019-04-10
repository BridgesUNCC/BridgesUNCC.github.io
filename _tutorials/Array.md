---
layout: post
title: "Tutorial: Arrays (1D, 2D, 3D)"
redirect-from: /Hello_World_Tutorials/Array.html
---

`Array<E>` implements arrays in BRIDGES, and it can be used to create arrays of any generic type.

Bridges Arrays support up to 3 dimensions. The `setDimensions()` method is used to set the array dimensions and allocate storage. Bridges creates arrays of `Element<E>`, which can be used to set visual properties.

## Example Details

-   The 3 examples illustrate creation of arrays of Bridges elements in 1D, 2D, 3D.
-   Indexing into the array is demonstrated, as well as setting visual attributes
-   Applications include sorting algorithms, stacks, queues (to show status of data structure operations, for instance).

{% capture java %}

### `arr1d.java`

```java
{% include_relative testing/java/arr1d.java %}
```

### `arr2d.java`

```java
{% include_relative testing/java/arr2d.java %}
```

### `arr3d.java`

```java
{% include_relative testing/java/arr3d.java %}
```

{% endcapture %}
{% capture cxx %}

### `array.cpp`

```c++
{% include_relative testing/cxx/array.cpp %}
```

### `array2d.cpp`

```c++
{% include_relative testing/cxx/array2d.cpp %}
```

### `array3d.cpp`

```c++
{% include_relative testing/cxx/array3d.cpp %}
```

{% endcapture %}
{% capture python %}

### `array1d.py`

```c++
{% include_relative testing/python/array1d.py %}
```

### `array2d.py`

```c++
{% include_relative testing/python/array2d.py %}
```

### `array3d.py`

```c++
{% include_relative testing/python/array3d.py %}
```
{% endcapture %}

{% include tutorial.html %}


## Bridges Visualization

- Once all your code is in order, run your file.
- Assuming all your code is correct and it compiles correctly, a link to the Bridges website will be generated on the console.
- Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.
- It should look something like this:

<iframe src="https://bridges-cs.herokuapp.com/assignments/100/bridges_public">

<iframe src="https://bridges-cs.herokuapp.com/assignments/1/bridges_public">

<iframe src="https://bridges-cs.herokuapp.com/assignments/102/bridges_public">

Well done! You’ve just created your Bridges Singly Linked List project!