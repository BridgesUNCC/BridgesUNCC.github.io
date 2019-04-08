---
title: 'Getting started: Python & Pip'
layout: post
---

## Step 1a: Install PyCharm

*   If you do not have Eclipse installed, download it from the [Pycharm site](https://www.jetbrains.com/pycharm/) and install it on your computer.

## Step 1b: (Optional) Install Pip

*   If you do not have Pip, install it from [here](https://pip.pypa.io/en/stable/installing/)

## Step 1b: (Optional) Install through Zip

*   Download the Bridges zip file from [here](/download/)
*   In your terminal navigate to the _Bridges directory_ (where you saved it).
*   Run the command `python setup.py install`

## Step 2: Create Bridges Account

*   Visit the Bridges [main page](/) and create yourself an account by clicking the login button on the top navigation bar. **Please ensure that your user id is devoid of spaces, as it will be used as part of the web link for your projects.** After creating your account, click on your profile name in the upper right corner to view your profile. Once in your profile, you will see your API Key; you will need this API key in part 2 of the tutorial(as well as in every BRIDGES program you write).

**NOTE:** Make sure to remember your password. There is no password recovery option, and you can only have one account per email address.

## Step 3: Creating Project

*   Click _Create New project_

![](/doc/getting-started/python/pip/newproject.png)

## Step 3b: Creating Project

*   Name your project `HelloWorld` create a new environment using _virtualenv_

![](/doc/getting-started/python/pip/projectconfig.png)

## Step 3c: Creating Project.

*   Choose a location for the virtual environment
*   Choose the base interpreter for project: _Python 3_ (Note: your location and base interpreter path will be different)
*   Uncheck _Inherit global variables_ and check _Make available for all projects_. (Note, If you installed Bridges through the zip file, check _Inherit global variables_)
*   Click _Create_ at the bottom right corner.

![](/doc/getting-started/python/pip/projectconfig.png)

## Step 4a: Installing Bridges _(Skip to step 4c if using Zip file)_

*   Go to _Project Settings -> Project Interpreter -> +/install_

![](/doc/getting-started/python/pip/settingsadd.png)

## Step 4b: Installing Bridges

*   Type in at the top _Bridges_
*   Select Bridges on the left side
*   Click _Install Package_

![](/doc/getting-started/python/pip/installpackage.png)

## Step 4c: Verification

*   To verify that you have successfully installed Bridges, look under the External Libraries section of your project and expand the python interpreter.
*   If you have a Project in PyCharm named 'HelloWorld', and the expanded python interpreter/site-packages has the Bridges folder, you have completed the setup and are ready to build the Hello World class!

![](/doc/getting-started/python/pip/verify.png)

### BRIDGES:Getting Started(Your First Bridges Program)

## Step 1a: Create a new File

*   Create a new class within your project
*   _File-->New-->Python File_

![](/doc/getting-started/python/newPythonFile.png)

## Step 1b: Create a new File

*   Name the file HelloWorld

![](/doc/getting-started/python/pip/createhelloworld.png)

## Step 2: Now build the Bridges Program to illustrate a singly linked list

*   First import the relevant Bridges classes

```python
from bridges.bridges import *
from bridges.sl_element import *
```

*   Create the bridges object with your API Key and User ID.

```python
bridges = Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY")
```

*   Create two singly-linked elements. Singly-linked elements can be linked together to create a linked-list structure.

```python
sle0 = SLelement("Hello", "")
sle1 = SLelement("World", "")
```

*   Link the elements

```python
sle0.set_next(sle1)
```

*   Set visual attributes of the elements

```python
sle0.get_visualizer().set_color("black")
sle0.get_visualizer().set_opacity(0.5)
sle1.get_visualizer().set_color("green")
```

*   Pass the handle of your data structure (reference to the first element) of your data structure

```python
bridges.set_data_structure(sle0)
```

*   Visualize the data structure

```python
bridges.visualize()
```

*   To summarize, your HelloWorld.py should look like this:

```python
from bridges.bridges import *
from bridges.sl_element import *

class HelloWorld:

  # create the Bridges object
  bridges = Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY")

  # create two singly-linked elements**
  sle0 = SLelement("Hello", "")
  sle1 = SLelement("World", "")

  # create a singly-linked list
  # by adding sle1 as sle0's next element
  sle0.set_next(sle1)

  # edit some visual properties of the two elements
  sle0.get_visualizer().set_color("black")
  sle0.get_visualizer().set_opacity(0.5)
  sle1.get_visualizer().set_color("green")

  # pass the first element of the list**
  bridges.set_data_structure(sle0)**

  # visualize the list
  bridges.visualize()
```

## Step 3: Running your Bridges program

*   Once your code is in, run your project
*   _Run_ -> _Run_
*   _Run_ -> _HelloWorld_

![](/doc/getting-started/python/runHelloWorld.png)

## Step 4: Visualize your data structure

*   If your code compiles correctly, the Eclipse console will give you a link to the Bridges website. to view the visualization. Copy/paste this link into your favorite browser to view a visualization of the data structure you just created.

![](/doc/getting-started/HelloWorld.png)