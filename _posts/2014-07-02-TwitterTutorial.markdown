---
layout: post
title:  "Twitter Tutorial"
categories: main
---

**Step 1:** Setting up our class

> * Lets create a `new class` like we did before in our package. This time will will call it TwitterDriver.

> * `File` -> `New` -> `Class`

> Note: Lets make sure it is set up like I previous class with a main and all the appropriate function calls.

{% highlight java  %}

import bridges.*;

public class TwitterDriver {

	public static void main(String[] args) throws Exception {
		GraphVisualizer gv = new GraphVisualizer();
		Bridge.init(0, "Your_API_Key_Here", gv);
		
		Bridge.complete();
	}
}

{% endhighlight %}

