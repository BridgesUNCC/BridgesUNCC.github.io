---
title: 'Getting started: Python & PyCharm'
layout: post
redirect-from: /bridges_setup_python_pycharm.html
---

## Step 1: Install PyCharm

*   If you do not have Eclipse installed, download it from the [Pycharm site](https://www.jetbrains.com/pycharm/) and install it on your computer.

## Step 2: Create Bridges Account

*   Visit the Bridges [main page](/) and create yourself an account by clicking the login button on the top navigation bar. **Please ensure that your user id is devoid of spaces, as it will be used as part of the web link for your projects.** After creating your account, click on your profile name in the upper right corner to view your profile. Once in your profile, you will see your API Key; you will need this API key in part 2 of the tutorial(as well as in every BRIDGES program you write). **NOTE:** Make sure to remember your password. There is no password recovery option, and you can only have one account per email address.

## Step 3: Python requests package

*   Use Pip to install requests package
*   For Mac, open your terminal and type _pip install requests_
*   For windows, open your terminal and navigate to the directory python is downloaded. Then type _python -m pip install requests_

## Step 4a: Python Environment Setup

*   Click configure at the bottom right corner of the IDE and click _Settings_

![](/doc/getting-started/python/pycharm/pycharmWindow.PNG)

## Step 4b: Python Environment Setup

*   In _Project interpreter_ click the gear icon on the far right and click _Add_

![](/doc/getting-started/python/pycharm/addInterp.png)

## Step 4c: Python Environment Setup, New Global Enviornment

*   Locate a convenient place to save this new Environment in the _Location_ attribute.
*   Locate the path of your python download for your _Base interpreter_
*   Be sure _Make available to all projects_ is checked. (Note: your location and base interpreter path will be different)

![](/doc/getting-started/python/pycharm/globalEnv.png)

## Step 5a: Import Zip archive into project interpreter paths

*   Download the Bridges.zip file from [the download page](/download/) and save it somewhere convenient on your drive.
*   On Pycharm, go back to _Project interpreter_, click the down arrow, and select _Show All_.

![](/doc/getting-started/python/pycharm/showAll.png)

## Step 5b: Import Bridges zip archive

*   Select the Enviornment we just created.
*   Then Click _Show paths for selected interpreter_

![](/doc/getting-started/python/pycharm/ShowPaths.png)

## Step 5c: Import Bridges zip archive

*   Click the _+_ button and navigate to where you saved the zip file. Then press OK.

![](/doc/getting-started/python/pycharm/add.png)

## Step 5d: Import Python Site-Packages

*   Click the _+_ button and navigate to where your Python _site-packages_ directory.
*   For Mac the path is `/Library/Frameworks/Python.framework/Versions/3.7/lib/python3.7/site-packages/`
*   For Windows it is in the same directory your python is downloaded `/python/python36/lib/site-packages/`.
*   Select the directory then press OK.

![](/doc/getting-started/python/pycharm/sitePackagesA.png)

## Step 6: Create a new Project

*   Click _Create New Project_ and name it as HelloWorld.
*   Then select _Existing Interpreter_ and select the Environment we created.

![](/doc/getting-started/python/pycharm/newProject.PNG)

## Step 6: Verification

*   To verify that you have successfully imported the zip file, look under the External Libraries section of your project and expand the python interpreter.
*   If you have a Project in PyCharm named 'HelloWorld', and the expanded python interpreter in the External Library section shows the bridges zip file, you have completed the setup and are ready to build the Hello World class!

![](/doc/getting-started/python/pycharm/verification.PNG)

### BRIDGES:Getting Started(Your First Bridges Program)

## Step 1a: Create a new class

*   Create a new class within your project
*   _File_ -> _New_ -> _Python File_

![](/doc/getting-started/python/pycharm/newPythonFile.png)

## Step 1b: Create a new class

*   Name the class HelloWorld
*   `class HelloWorld:`

![](/doc/getting-started/python/pycharm/newClass.PNG)

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