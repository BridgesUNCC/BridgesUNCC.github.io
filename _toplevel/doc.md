---
layout: post
title: Documentation
redirect-from:
    - /bridges_setup.html
    - /bridges_doclinks.html
---

<div class="row">
<div class="col-md-6" markdown="1">

## [Frequently asked questions](/doc/faq)

## Getting started

### Java

- [with IntelliJ IDEA](/doc/getting-started/java/intellij/)
    - [video tutorial](https://www.youtube.com/watch?v=oohLmVapqko)
- [with Eclipse](/doc/getting-started/java/eclipse/)
    - [video tutorial](https://www.youtube.com/watch?v=knFD9xF_g9Q)
- [with NetBeans](/doc/getting-started/java/netbeans/)
    - [video tutorial](https://www.youtube.com/watch?v=xYBdr-ZJXys)
- [with BlueJ](/doc/getting-started/java/bluej/)
    - [video tutorial](https://www.youtube.com/watch?v=H354LpJjLW8)
- [with jGRASP](/doc/getting-started/java/jgrasp/)

### Python

- [with PyCharm](/doc/getting-started/python/pycharm/)
    - [video tutorial](https://www.youtube.com/watch?v=_AA0PVqUfYk)
- [with Pip](/doc/getting-started/python/pip/)

### C++

- [with Eclipse](/doc/getting-started/cxx/eclipse/)
- [with XCode](/doc/getting-started/cxx/xcode/)
- [with MS Visual Studio C++ 2017 (video)](https://www.youtube.com/watch?v=SDIeHJhY4u4)
- [with Code::Blocks (video)](https://www.youtube.com/watch?v=l65aNgxyTNA)

The C++ version is provided as a header-only library & does not need to be separately compiled.

The C++ version requires [curl](https://curl.haxx.se). Most Linux systems already have it installed by default.

#### Manual curl installation

On Unix flavored platforms (OSX, Linux, Cloud 9), you can install curl as follows:

*   Download curl sources from[](https://curl.haxx.se/download.html)
*   Explode the archive (using tar, unzip, bunzip2, etc.)
*   Change to the folder containing the curl sources and run the following commands from a terminal.
    *   `./configure --prefix=path-to-install-curl`
    *   `make`
    *   `sudo make install`
*   'path-to-install-curl' is replaced by the path where you want curl to be installed. For a full set of options, try `./configure --help` on your terminal.
*   By default (if install path is not provided with the configure command), curl will be installed in `/usr/local`
*   The last command should be done using super user permission. If you do not have that, then specify a path to a directory you have write access to.
*   The library will be installed under a `lib` folder in the specified path and the include files will be under the `include` folder

</div>
<div class="col-md-6" markdown="1">

## Tutorials

- [Arrays](/tutorials/Array/)
  - [1D arrays](/tutorials/ARRAY1D/)
  - [2D arrays](/tutorials/ARRAY2D/)
  - [3D arrays](/tutorials/ARRAY3D/)

## Api documentation

### Java

 - [Latest](/doc/java-api/current/html/index.html)
 - [v2.4.0](/doc/java-api/2.4.0/html/index.html)
 - [v2.3.3](/doc/java-api/2.3.3/html/index.html)
 - [v2.3.2](/doc/java-api/2.3.2/html/index.html)
 - [v2.3.1](/doc/java-api/2.3.1/html/index.html)
 - [v2.3.0](/doc/java-api/2.3.0/html/index.html)
 - [v2.2.0](/doc/java-api/2.2.0/html/index.html)
 - [v2.1.0](/doc/java-api/2.2.0/html/index.html)

### Python

 - [Latest](/doc/python-api/current/html/index.html)
 - [v2.4.0](/doc/python-api/2.4.0/html/index.html)
 - [v1.0](/doc/python-api/1.0/html/index.html)

### C++

 - [Latest](/doc/cxx-api/current/html/index.html)
 - [v2.4.0](/doc/cxx-api/2.4.0/html/index.html)
 - [v2.3.4](/doc/cxx-api/2.3.4/html/index.html)
 - [v2.3.3](/doc/cxx-api/2.3.3/html/index.html)
 - [v2.3.2](/doc/cxx-api/2.3.2/html/index.html)
 - [v2.3.0](/doc/cxx-api/2.3.0/html/index.html)
 - [v2.2.0](/doc/cxx-api/2.2.0/html/index.html)

## Developer docs

- [Design overview](/doc/design-overview/)
- [Dataset list](/doc/datasets/)

</div>
</div>