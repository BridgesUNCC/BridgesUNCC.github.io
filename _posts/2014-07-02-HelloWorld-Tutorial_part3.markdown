---
layout: post
title:  "Hello World Visualization - Part 3"
categories: jekyll update
---

## Continuing our graph visualization:
-----
At the end of this section of the tutorial you will know how to create edges and manipulate Vertex and Edge properties. This is what you will be creating.

![drawing](/images/screenshot_10.png)

When we left off last we had just created our first visualization and displayed our first vertex. It should have looked something like this.

![drawing](/images/screenshot_9.png)

Lets start off by managing the properties of that vertice. Each vertex and edge that we create has access to an array of properties to manage their appearance. The first property we will look at is the color property.

## Step 1: Changing the vertex color

> First we want to use the vertex that we want to manipulate and call the appropriate method, in this case the .setColor() method. Bridges is set up to accept strings or the CSS color value.

> Note: If you do not choose a value that is in our list you will recieve an InvalidValueException. Thats okay just choose a different color.

{% highlight java %}

HelloWorld.setColor("red"); OR HelloWorld.setColor("#FF0000");

{% endhighlight %}

![drawing](/images/screenshot_11.png)

## Step 2: Changing the size of a vertex

> This only requires further method calls on the same vertex to change its properties. We should also go ahead and create another vertex to prepare for the next part of the tutorial.

{% highlight java %}

HelloWorld.setSize(15);

Vertex GoodByeWorld = new Vertex("GoodByeWorld", gv);

{% endhighlight %}

![drawing](/images/screenshot_12.png)

## Step 3: Connecting vertices

> We only need the two vertices that we want to connect and one method call.

{% highlight java %}

HellowWorld.createEdge(GoodByeWorld);

{% endhighlight %}

![drawing](/images/screenshot_13.png)

## Step 4: Changing the properties of edges

> We can manipulate the edges of connected vertices the same way that we manipulate the vertices themselves. All we need are the two vertices that make up the edge and we will have access to the edge.

> Note: You have to call .getEdge() in the same order that you called .createEdge(). HelloWorld.getEdge(GoodByeWorld); will not return the same edge as GoodByeWorld.getEdge(HelloWorld);

{% highlight java %}

HelloWorld.getEdge(GoodByeWorld).setColor("yellow");

{% endhighlight %}

![drawing](/images/screenshot_10.png)

Congratulations, you have just finished your first graph representation!

[Return to Part 1](http://dismembered.github.io/jekyll/update/2014/06/23/HelloWorld-Tutorial_part1/)

[Return to Part 2](http://dismembered.github.io/jekyll/update/2014/06/23/HelloWorld-Tutorial_part2/)
