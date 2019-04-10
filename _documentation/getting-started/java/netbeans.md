---
title: 'Getting started: Java & NetBeans'
layout: post
redirect-from: /bridges_setup_java_netbeans.html
---

## Step 1: Install NetBeans

*   If you do not have NetBeans installed, download it from the [NetBeans site](https://netbeans.org/downloads/) and install it on your computer.

## Step 2: Create Bridges Account

*   Visit the Bridges [main page](/) and create yourself an account by clicking the login button on the top navigation bar. **Please ensure that your user id is devoid of spaces, as it will be used as part of the web link for your projects.** After creating your account, click on your profile name in the upper right corner to view your profile. Once in your profile, you will see your API Key; you will need this API key in part 2 of the tutorial(as well as in every BRIDGES program you write).

**NOTE:** Make sure to remember your password. There is no password recovery option, and you can only have one account per email address.

## Step 3: Create a Java Project

*   _File-->New Project-->Java Application-->Next_

![](/doc/getting-started/java/netbeans/fileNew.png)

## Step 4: Name Project

*   In the new window change the _Project name_ field to your user name, and choose prject path. Click Finish.

![](/doc/getting-started/java/netbeans/nameProject.png)

## Step 5a: Import Jar File into project

*   Download the Bridges.jar file from [the downloads page](/download/) and save it somewhere convenient on your drive.
*   On NetBeans, right-click your project in the Package Explorer window then click: _Set Configuration_ -> _Customize_

![](/doc/getting-started/java/netbeans/setconf.png)

## Step 5b: Import BRIDGES Jar file

*   Navigate to the Libraries tab and click _Add JAR/Folder_ **Make sure your JDK is 1.8 or above.**

![](/doc/getting-started/java/netbeans/addlibrary.png)

## Step 5c: Import BRIDGES Jar file

*   Locate and select the Bridges.jar file you saved earlier to import it into your new project.

![](/doc/getting-started/java/netbeans/findLibrary.png)

## Step 6: Verification

*   To verify that you have successfully imported the Jar file, look under the Libraries section of your project in the Package Explorer window in NetBeans.
*   If you have got a Project in the NetBeans Package Explorer with your username as the project name, and the referenced libraries section shows the bridges Jar file, you have completed the setup and are ready to build the Hello World class!

![](/doc/getting-started/java/netbeans/verify.png)

### BRIDGES:Getting Started(Your First Bridges Program)

## Step 1a: Create a new class

*   Create a new class within your project
*   _Right Click package-->New-->Java Class_
*   Select Java Main Class in File Types

![](/doc/getting-started/java/netbeans/newClass.png)

## Step 1b: Create a new class***   In the New Java Class window set the Package field to your na
*   Set the Name field to HelloWorld (this is the name of the class)
*   Click Finish in the bottom right-hand corner

![](/doc/getting-started/java/netbeans/classConf.png)

## Step 2: Now build the Bridges Program to illustrate a singly linked list

*   First import the relevant Bridges classes

```java
import bridges.connect.Bridges;
import bridges.base.SLelement;
```

*   Create the bridges object with your API Key and User ID. Since we want our project to print out `Hello World` use `String` as the type.

```java
Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");
```

*   Create two singly-linked elements. Singly-linked elements can be linked together to create a linked-list structure.

```java
SLelement sle0 = new SLelement("Hello", "");
SLelement sle1 = new SLelement("World", "");
```

*   Link the elements

```java
sle0.setNext(sle1);
```

*   Set visual attributes of the elements

```java
sle0.getVisualizer().setColor("black");
sle0.getVisualizer().setOpacity((float)0.5);
sle1.getVisualizer().setColor("green");
```

*   Pass the handle of your data structure (reference to the first element) of your data structure

```java
_bridges.setDataStructure(sle0);
```

*   Visualize the data structure

```java
_bridges.visualize();
```

*   To summarize, your HelloWorld.java should look like this:

```java
import bridges.connect.Bridges;
import bridges.base.SLelement;

public class HelloWorld {

     public static void main(String\[\] args) throws Exception{

             //create the Bridges object

         Bridges bridges = new Bridges(0, "YOUR\_USER\_ID", "YOUR\_API\_KEY");

             //create two singly-linked elements
         SLelement sle0 = new SLelement("Hello", "");
         SLelement sle1 = new SLelement("World", "");

             // create a singly-linked list
             // by adding sle1 as sle0's next element
         sle0.setNext(sle1);

             //edit some visual properties of the two elements
         sle0.getVisualizer().setColor("black");
         sle0.getVisualizer().setOpacity((float)0.5);
         sle1.getVisualizer().setColor("green");

             //pass the first element of the list
        bridges.setDataStructure(sle0);

             // visualize the list
         bridges.visualize();
        }
    }
```

## Step 3: Running your Bridges program

*   Once your code is in, run your project
*   _Run_ -> _Run_
*   _Run_ -> _Run As_ -> _Java Application_

![](/doc/getting-started/java/netbeans/run.png)

## Step 4: Visualize your data structure

*   If your code compiles correctly, the NetBeans console will give you a link to the Bridges website. to view the visualization. Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.

![](/doc/getting-started/HelloWorld.png)