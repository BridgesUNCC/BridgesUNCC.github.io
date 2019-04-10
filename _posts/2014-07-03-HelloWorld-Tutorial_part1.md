---
layout: post
title:  "Hello World Visualization Tutorial"
tags: [tutorial]
---

## Installation and Setup:

-----

**Step 1:** Installing Eclipse

* Download and install [Eclipse](https://www.eclipse.org/downloads/index-java8.php). There are several choices here so make sure you choose the correct one.
* Under Package Solutions choose `Eclipse IDE for Java Developers` from the list. The important thing here is that it has 'Maven integration', which is required to use Bridges.
* To verify you have Maven installed correctly `Eclipse`->`About Eclipse` (on Mac) or `Help`-> `About Eclipse` (on Linux) and you should see the Maven icon as illustrated below.
* NOTE: If you already have Eclipse installed, you can just install the [Maven](https://www.eclipse.org/m2e/download/) plugin by dragging and dropping the "Install" image into a running Eclipse workspace. It installs automatically.

![drawing](/img/Tutorial/verifyMaven.png)

**Step 2:** Creating a Bridges account

* Go to the [Bridges website](http://bridges-cs.herokuapp.com/login) and create an account. After you create your account, click on your profile name in the upper right corner to view your profile. Once in your profile there will be a number under `API Key`, you will need this number in Part 2 of the tutorial.
* NOTE: Make sure to remember your password; there is no option for password recovery and you can only have one account per email address.

**Step 3:** Creating a Java Project

* Open Eclipse and create a new Java Project. `File`->`New`->`Java Project`

![drawing](/img/Tutorial/screenshot_0.png)

* In the new window change the `Project name` field to your name. Then click `Finish` in the lower right hand corner.

![drawing](/img/Tutorial/screenshot_1.png)

**Step 4:** Converting Maven

* Right-click your project (which should be your name) in the `Package Explorer` then click `Configure`->`Convert to Maven Project`.
* NOTE: If you can not see your project make sure the Welcome Screen is closed (this should only be an issue if you fresh installed Eclipse. If it is still not showing up you can click `Window` -> `Show View` -> `Package Explorer`.

* NOTE: If you do not see `Convert to Maven Project` go to Step 1.

![drawing](/img/Tutorial/screenshot_2.png)

**Step 5:** Setting up Maven

* In the new window change the `Artifact Id` field to HelloWorld then click `Finish`.

![drawing](/img/Tutorial/screenshot_3.png)

**Step 6:** Setting up Maven continued

* Double-click `pom.xml` in the `Package Explorer` in your newly created package to open it. Click the `pom.xml` tab at the bottom of the screen to activate it. You should now see something like this.

![drawing](/img/Tutorial/screenshot_4.png)

**Step 7:** Editting the pom.xml

* Paste the following text into your maven `pom.xml` below `<version>0.0.1-SNAPSHOT</version>`. It adds a dependency to your
> project for Bridges, and also installs a repository for fetching that dependency
> and for later updates. If you need to update you check out [Upgrading Maven](http://bridgesuncc.github.io/maven/upgrading/) for instructions on how to do so.
* After copying and pasting the following code into your pom.xml, be sure to save it. `File`->`Save`

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
  		<version>[0.99.0,1.0.0)</version>
  	</dependency>
  </dependencies>
{% endhighlight %}

![drawing](/img/Tutorial/screenshot_5.png)

* To verify that you did everything correctly in the pom.xml click the `Dependencies` tab and check that `bridges : [0.99.0,1.0.0)`. If it is not there make sure you copied all of the above code and that it is in the correct spot.

![drawing](/img/Tutorial/dependencies.png)

You are now ready to start writing code!

[Continue to Part 2](http://BridgesUNCC.github.io/tutorial/HelloWorld-Tutorial_part2/)
