---
layout: post
title:  "Hello World Visualization - Part 2"
tags: [tutorial]
---

## Writing our first code:
-----
To give you a preview, this is what we will be creating in this part of the tutorial.

![drawing](/img/Tutorial/screenshot_9.png)


**Step 1:** Creating our class

* Lets create a new class within our project. `File`->`New`->`Class`.

![drawing](/img/Tutorial/screenshot_6.png)

**Step 2:** Creating our class continued

* In the new window set the `Package` field to your name.
* Set the `Name` field to HelloWorld (this is the name of the class).
* Tick the box to create `public static void main(String[] args)` (this will have Eclipse create a main method for us within our newly created class).
* Then click `Finish`.

![drawing](/img/Tutorial/screenshot_7.png)

**Step 3:** Importing Bridges

* Import the Bridges package. This gives us access to all the classes/methods needed to create a graph or any other data structure visualization.

```java
import edu.uncc.cs.bridges.*;
```

**Step 4:** Creating our Graph object

* Create a new GraphVisualizer object. This is an object that will contain all the graph data.

```java
GraphVisualizer gv = new GraphVisualizer();
```

**Step 5:** Initializing Bridges

* Initialize Bridges. Your API key should have been generated in Part 1, this is where it goes along with your User Name.

```java
Bridge.init(0, "Your API key here", gv, "Your user name here");
```

**Step 6:** Creating our first vertex

* Create our first Vertex. HelloWorld is what we are going to name our first vertex. The Vertex object is looking for a name (what we want to call it) and a Graph (where we want to store it). We tell the Vertex that it will contain a String in this case, but later we will want Followers for Twitter, or any other type you find convenient.

```java
Vertex<String> HelloWorld = new Vertex<String>("HelloWorld", gv);
```

**Step 7:** Submitting our visualization

* Submit the visualization data. This tells Bridges that we are ready to submit our data to be visualized.

```java
Bridge.complete();
```

Our final code should look just like below, minus the API key and User Name which has been removed for security purposes.

```java
package studentNameHere;
import edu.uncc.cs.bridges.*;

public class HelloWorld {
  public static void main(String[] args) {
    GraphVisualizer gv = new GraphVisualizer();
    Bridge.init(0, "Your API key", gv, "Your username");
    Vertex<String> HelloWorld = new Vertex<String>("HelloWorld", gv);
    Bridge.complete();
  }
}
```

**Step 8:** Running our program

Finally we need to run our program.
In the console there will be a string, similar to the one below, giving you a link to view the visualization.

```
Check out your visuals at http://bridges-cs.herokuapp.com/assignments/0/YOUR_USERNAME?apikey=YOUR_API_KEY_WILL_BE_HERE
```

* USERNAME is case-sensitive and should be your actual user name (seen on the top right when logged in)
* The website above will be reflected in the eclipse console. Note that the website located in the console should be used rather than the sample shown above. 
* Copy and paste the URL into your favorite browser in order to view the visualization.

Below is a sample of what your visualization should look like at this point.

![drawing](/img/Tutorial/screenshot_9.png)

[Continue to Part 3](/tutorial/HelloWorld-Tutorial_part3/)

[Return to Part 1](/tutorial/HelloWorld-Tutorial_part1/)
