Complexity Matters
==================

Goal
----

The purpose of this assignment is to understand why algorithms are
judged by their Big-Oh notations rather than a more precise model, or
runtime measurement. We make a crude approximation of using the clock speed
as representing the machine's performance

Programming Part
----------------

### Task

Using Bridges LineChart object, plot the runtime of an algorithm for
problem size ranging from 1 to 10<sup>5</sup>. (Don't use all values
of n, take steps of reasonable size.)

1. 10<sup>4</sup> n instructions on a machine at 1 MHz
2. 5.10<sup>4</sup> n instructions on a machine at 1MHz
3. 10<sup>2</sup> n<sup>2</sup> instruction on a machine at 100MHz

#### Conclude

Does it really matter that you can get a slightly faster machine if you can get a lower BigOh complexity?

Does it really matter that you can gain a factor of 100 if you can get a lower BigOh complexity?

##### Sample Output

![Sample Output](./output.png)

### Help

#### For C++
[Bridges documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_bridges.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_line_chart.html)

#### For Java
[Bridges documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_bridges.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_line_chart.html)

#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/namespacebridges_1_1bst__element.html)

[LineChart documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1line__chart_1_1_line_chart.html)
