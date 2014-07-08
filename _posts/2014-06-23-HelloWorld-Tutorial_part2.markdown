---
layout: post
title:  "Hello World Visualization - Part 2"
categories: main
---

## Writing your first code:
-----
To give you a preview, this is what we will be creating in this part of the tutorial.

![drawing](/img/Tutorial/screenshot_9.png)


**Step 1:**

> Lets create a new class within our project. `File`->`Class`.

![drawing](/img/Tutorial/screenshot_6.png)

**Step 2:**

> In the new window set the `Package` field to your name. Set the `Name` field to HelloWorld (this is the name of the class). Tick the box to create `public static void main(String[] args)` (this will have Eclipse create a main method for us within our newly created class). Then click `Finish` in the lower right corner.

![drawing](/img/Tutorial/screenshot_7.png)

**Step 3:**

> Import the Bridges package. This gives us access to all the classes/methods needed to create a graph or any other data structure visualization.

{% highlight java  %}

import bridges.*;

{% endhighlight %}

**Step 4:**

> Create a new GraphVisualizer object. This is an object that will contain all the graph data.

{% highlight java  %}

GraphVisualizer gv = new GraphVisualizer();

{% endhighlight %}

**Step 5:**

> Initialize Bridges. Your API key should have been generated in Part 1, this is where it goes.

{% highlight java  %}

Bridge.init(0, "Your API key here", gv);

{% endhighlight %}

**Step 6:**

> Create our first Vertex. HelloWorld is what we are going to name our first vertex. The Vertex object is looking for a name (what we want to call it) and a Graph (where we want to store it).

{% highlight java  %}

Vertex HelloWorld = new Vertex("HelloWorld", gv);

{% endhighlight %}

**Step 7:**

> Submit the visualization data. This tells Bridges that we are ready to submit our data to be visualized.

{% highlight java  %}

Bridge.complete();

{% endhighlight %}

**Step 8:**

> Finally we need to run our program.
In the console there will be a string, similar to the one below, giving you a link to view the visualization.

`Check out your visuals at http://bridges.cs.uncc.edu/assignments/0/YOUR_USERNAME?apikey=YOUR_API_KEY_WILL_BE_HERE`

> Copy and paste the URL into your favorite browser in order to view the visualization. Where the URL says `YOUR_USERNAME` be sure to replace it with the user name that you created on the Bridges website in Part 1.

Congratulations on creating your very first visualization with Bridges! Below is a sample of what your visualization should look like.

![drawing](/img/Tutorial/screenshot_9.png)

[Continue to Part 3](http://BridgesUNCC.github.io/main/HelloWorld-Tutorial_part3/)

[Return to Part 1](http://BridgesUNCC.github.io/main/HelloWorld-Tutorial_part1/)
