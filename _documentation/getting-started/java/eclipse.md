---
title: 'Getting started: Java & Eclipse'
layout: post
---

## Step 1: Install Eclipse

If you do not have Eclipse installed, download it from the [Eclipse site](http://www.eclipse.org/) and install it on your computer.

## Step 2: Create Bridges Account

Visit the Bridges [main page](/) and create yourself an account by clicking the login button on the top navigation bar. **Please ensure that your user id is devoid of spaces, as it will be used as part of the web link for your projects.** After creating your account, click on your profile name in the upper right corner to view your profile. Once in your profile, you will see your API Key; you will need this API key in part 2 of the tutorial(as well as in every BRIDGES program you write).

**NOTE:** Make sure to remember your password. There is no password recovery option, and you can only have one account per email address.

## Step 3: Create a Java Project

* _File_ -> _New_ -> _Java Project_

![](/doc/getting-started/java/eclipse/newJavaProject.png)

## Step 4: Check Java version

* In the new window change the _Project name_ field to your user name, then make sure the _Execution Environment JRE_ is JavaSE-1.5 or above. Click _Finish_ in the lower right-hand corner.

![](/doc/getting-started/java/eclipse/JavaProject.png)

## Step 6: Import Jar File into project

* Download the latest Bridges.jar file from [the downloads page](/download/) and save it somewhere convenient on your drive.
* On Eclipse, right-click your project in the Package Explorer window then click: _Build Path_ -> _Add External Archives_

![](/doc/getting-started/java/eclipse/addArchive.png)

## Step 7: Import BRIDGES Jar file

* Locate and select the `Bridges.jar` file you saved earlier to import it into your new project

![](/doc/getting-started/java/eclipse/jar.png)

## Step 8: Verification

* To verify that you have successfully imported the Jar file, look under the Referenced Libraries section of your project in the Package Explorer window in Eclipse.
* If you have got a Project in the Eclipse Package Explorer with your username as the project name, and the referenced libraries section shows the bridges Jar file, you have completed the setup and are ready to build the Hello World class!

![](/doc/getting-started/java/eclipse/ReferencedLib.png)

### BRIDGES:Getting Started(Your First Bridges Program)

## Step 1: Create a new class

* Create a new class within your project
* _File_ -> _New_ -> _Class_

![](/doc/getting-started/java/eclipse/newClass.png)

## Step 2: Create a new class

* In the New Java Class window set the Package field to your name
* Set the Name field to HelloWorld (this is the name of the class)
* Tick the box to create public static void main(String\[\] args)
* to make Eclipse create a main method in our new class
* Click Finish in the bottom right-hand corner

![](/doc/getting-started/java/eclipse/class.png)

## Step 3: Now build the Bridges Program to illustrate a singly linked list

* First import the relevant Bridges classes

```java
import bridges.connect.Bridges;
import bridges.base.SLelement;
```

* Create the bridges object with your API Key and User ID. Since we want our project to print out `Hello World` use String as the type.

```java
Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");
```

* Create two singly-linked elements. Singly-linked elements can be linked together to create a linked-list structure.

```java
SLelement sle0 = new SLelement("Hello", "");
SLelement sle1 = new SLelement("World", "");
```

* Link the elements

```java
sle0.setNext(sle1);
```

* Set visual attributes of the elements

```java
sle0.getVisualizer().setColor("black");
sle0.getVisualizer().setOpacity(0.5);
sle1.getVisualizer().setColor("green");
```

* Pass the handle of your data structure (reference to the first element) of your data structure

```java
bridges.setDataStructure(sle0);
```

* Visualize the data structure

```java
bridges.visualize();
```

* To summarize, your HelloWorld.java should look like this:

```java
import bridges.connect.Bridges;
import bridges.base.SLelement;

public class HelloWorld {

     public static void main(String[] args) throws Exception{

             //create the Bridges object

         Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");

             //create two singly-linked elements
         SLelement sle0 = new SLelement("Hello", "");
         SLelement sle1 = new SLelement("World", "");

             // create a singly-linked list
             // by adding sle1 as sle0's next element
         sle0.setNext(sle1);

             //edit some visual properties of the two elements
         sle0.getVisualizer().setColor("black");
         sle0.getVisualizer().setOpacity(0.5);
         sle1.getVisualizer().setColor("green");

             //pass the first element of the list
        bridges.setDataStructure(sle0);

             // visualize the list
         bridges.visualize();
        }
    }
```

## Step 3: Running your Bridges program

* Once your code is in, run your project
* _Run_ -> _Run_
* _Run_ -> _Run As_ -> _Java Application_

![](/doc/getting-started/java/eclipse/runAs.png)

## Step 4: Visualize your data structure

If your code compiles correctly, the Eclipse console will give you a link to the Bridges website. to view the visualization. Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.

![](/doc/getting-started/HelloWorld.png)