---
layout: post
title:  "Hello World Visualization - Part 1"
categories: jekyll update
---

## Installation and Setup:

-----

Download and install Eclipse found here [here](https://www.eclipse.org/downloads/index-java8.php). Under Package Solutions choose `Eclipse IDE for Java Developers` from the list.

Go to the Bridges website found [here](http://bridges.cs.uncc.edu/login) and create an account. After you create your account, click on your profile name in the upper right corner to view your profile. Once in your profile, click `Generate new API key` you will need this number in Part 2.

**Step 1:**

> Open Eclipse and create a new Java Project. `File`->`Java Project`

![drawing](/images/screenshot_0.png)

**Step 2:**

> In the new window change the `Project name` field to your name. Then click `Finish` in the lower right hand corner.

![drawing](/images/screenshot_1.png)

**Step 3:**

> Right-click your package (which should be your name) in the `Package Explorer` then click `Configure`->`Convert to Maven Project`.

![drawing](/images/screenshot_2.png)

**Step 4:**

> In the new window change the `Artifact Id` field to HelloWorld then click `Finish` in the lower right hand corner.

![drawing](/images/screenshot_3.png)

**Step 5:**

> Double-click `pom.xml` in the `Package Explorer` in your newly created package to open it. Click the `pom.xml` tab at the bottom of the screen to activate it. You should now see something like this.

![drawing](/images/screenshot_4.png)

**Step 6:**

> Paste the following bits into your maven `pom.xml`. It adds a dependency to your
> project for Bridges, and also installs a repository for fetching that dependency
> and for later updates. Later on, you can update easily by opening your project folder
> in the left panel and pressing Alt-F5

> Note to developers: For the latest, possibly broken version, replace the version with:
> [0.99.0,1.0.0)

{% highlight xml %}
  <repositories>
    <repository>
      <id>UNCC Bridges Updates</id>
      <url>https://googledrive.com/host/0B8wOEC5-v5lXSlIyancyMXJpY28/releases/</url>
    </repository>
  </repositories>
  <dependencies>
  	<dependency>
  		<groupId>edu.uncc.cs.bridges</groupId>
  		<artifactId>bridges</artifactId>
  		<version>[0.4.0,0.5.0)</version>
  	</dependency>
  </dependencies>
{% endhighlight %}

![drawing](/images/screenshot_5.png)

Congratulations, you are now ready to start writing code!

[Continue to Part 2](http://dismembered.github.io/jekyll/update/2014/06/23/HelloWorld-Tutorial_part2/)
