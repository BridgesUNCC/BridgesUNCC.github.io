---
layout: post
title:  "Twitter Tutorial"
categories: main
---

**Step 1:** Setting up our class

> Lets create a new class within our project. `File`->`New`->`Class`.

![drawing](/img/Tutorial/newClass.png)

> Note: Lets make sure it is set up like I previous class.

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

