---
layout: post
title:  "Twitter Tutorial"
categories: main
---

**Step 1:** Set up class

> Make sure the class is set up like the previous class in HelloWorld.

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
