---
layout: post
title:  "Twitter Tutorial"
categories: main
---

**Step 1:** Setting up our class

> * Lets create a `new class` like we did before in our package. This time will will call it TwitterDriver.
* `File` -> `New` -> `Class`

> Note: Lets make sure it is set up like I previous class with a main and all the appropriate function calls.

{% highlight js  %}

import bridges.*;

public class TwitterDriver {

	public static void main(String[] args) throws Exception {
		GraphVisualizer gv = new GraphVisualizer();
		Bridge.init(0, "Your_API_Key_Here", gv);
		
		Bridge.complete();
	}
}

{% endhighlight %}

**Step 2:** Finding a person on Twitter

> * First we need to get a url of someone's twitter. You can try someone random or you can choose someone that you know. In this case we chose `twitter.com/Joey`.
* Next we create a vertex out of the twitter handle that we chose. Doing this allows that twitter handle to be the focus of our graph.

{% highlight js  %}
String name = "twitter.com/Joey";
		 
Vertex joey = new Vertex(name, gv);
{% endhighlight %}

**Step 3:** Checking associations

> * Now we get to check if the person we chose actually has friends.
* This will print the associations, 50 in this case, of the twitter handle that we chose earlier.
{% highlight js  %}
System.out.println(Bridge.getAssociations(joey.getIdentifier(), 50));
{% endhighlight %}

