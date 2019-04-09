---
title: 'Getting started: C++ & XCode'
layout: post
redirect-from: /bridges_setup_cxx_xcode.html
---

## Step 1: Install XCode

*   If you do not have Xcode installed on your Mac installed, download it from the [Apple developer site](https://developer.apple.com/xcode/downloads/). and install it on your computer.
*   You must also install the Xcode command line tools; this can be done from the command line from Terminal window as follows:

```console
$ xcode-select --install
```
    
*   If this completes successfully, you are now ready to use Xcode with BRIDGES.
*   Open Xcode and you should see it on your dock(set Options to keep it on the dock permanently).

## Step 2: Create Bridges Account

Visit the Bridges [main page](http://bridgesuncc.github.io) and create yourself an account by clicking the login button on the top navigation bar. Please ensure that your user id is devoid of spaces, as it will be used as part of the web link for your projects. After creating your account, click on your profile name in the upper right corner to view your profile. Once in your profile, you will see your API Key; you will need this API key later in the tutorial(as well as in every BRIDGES program you write).

**NOTE:** Make sure to remember your password. There is no password recovery option(for now), and you can only have one account per email address.

## Step 3: Download the Bridges C++ template files, Install CURL library

*   Download the Bridges C++ class files from this [link](./sw/bridges-cxx-2.3.4.zip). Save this in a convenient folder. You will need this later.
*   BRIDGES uses the [CURL](https://curl.haxx.se) library for communicating with the web server, and posting assignments. Download CURL from this [link](https://curl.haxx.se/download.html) and install the library in a convenient location

## Step 4: Create a C++ Project

*   Open Xcode
*   _File-->New-->Project_
*   Click on _OSX-->Application-->_, and selecting **Command Line Tool**
*   Specify a name for the project and a location on your drive.
*   You should now see a project on the left panel with a predefined main.cpp skeleton. Click on main.cpp to bring up the source file.

![](/doc/getting-started/cxx/xcode/new_proj.png)

![](/doc/getting-started/cxx/xcode/new_proj2.png)

## Step 5: Type or paste in a Bridges example program

*   There are multiple ways to import a source file. Here we will simply copy/paste a BRIDGES program to illustrate a singly linked list example.
*   Notice the number of errors that show up; we will resolve them next.

![](/doc/getting-started/cxx/xcode/bridges_src.png)

## Step 6: Project Settings

*   Click on the Project. This will bring up the Project Settings (middle panel). Select _Build Settings_ (top panel)
*   You will next need to specify the library and include search paths
*   _Include Paths:_ You will need to specify the path to the CURL library include as well as the BRIDGES class include files (not all BRIDGES sources are in include files)
    *   Scroll down to the section titled _Search Paths_
    *   Double click on the middle of line that says _Header Search Paths_ and this will bring up an edit box(see figure on the right).
    *   Click on the _+_ character on the bottom to add a path. You will do this twice to add the two include paths, as shown. These paths refer to the locations of the include files of CURL library and the BRIDGES include files, respectively.
    *   Click anywhere else to get rid of the editor box.
*   _Library Paths_: You will need to specify the path to the CURL library(this is usually under the lib folder of your CURL installation).
    *   Look for the _Library Search Paths_ right under _Header Search Paths_
    *   Similar to the previous step, double click to bring up the Editor box and enter Library Search path.
    *   Click anywhere else to get rid of the editor box.
*   _Link the CURL Library_
    
    *   Scroll to top of Settings and click on _Build Phases_ Select _Link Binary with Libraries_.
    *   Click the _+_ button and select _Add Other_. Navigate to your Curl library installation and add the library (liburl.dylib) to the project.
    
    ![](/doc/getting-started/cxx/xcode/includes.png)
    
    ![](/doc/getting-started/cxx/xcode/lib_path.png)

    ![](/doc/getting-started/cxx/xcode/lib.png)
    
## Step 7: Build Run Project**
    
    *   To build and run your project, hit the 'Run' button(rightward pointing filled triangle on the upper left window).
    *   If everything compiles correctly, you will see a console window at the bottom with a web link pointing to the visualization. Else if the build failed, then click on the little triangle with the exclamation point(below the Build/Run button) to see the build errors.

![](/doc/getting-started/cxx/xcode/run.png)

## Step 8: Visualize

*   Paste the link into your browser to see the doubly linked list.
*   If you see the visualization, you are done with your first BRIDGES program. Congratulations!
*   You should be able to move the visualization with your left button, click and pull the nodes, see the labels on mouse over, etc.

![](/doc/getting-started/cxx/xcode/sllist.png)