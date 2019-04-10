---
layout: post
title: Downloads
index: 1
---

## Java

Releases are cross-platform

- [BRIDGES v2.4.1](/sw/bridges-java-2.4.1.zip)

## C++

Choose the correct version for your platform.

- [BRIDGES v2.4.1 (UNIX)](/sw/bridges-cxx-unix-2.4.1.zip)
- [BRIDGES v2.4.1 (Windows, requires VS2017)](/sw/bridges-cxx-windows-2.3.4.zip)

## Python

Releases are cross-platform

- [BRIDGES v2.4.1](sw/bridges-python-2.4.1.zip)

## Source code

- [Java client](http://github.com/krs-world/bridges)
- [C++ client](http://github.com/krs-world/bridges-cxx)
- [Python client](https://github.com/krs-world/bridges-python)
- [Server](http://github.com/stevemacn/bridgesAPI)

## Changes

### 2.3.3

*   `GraphAdjList` and `GraphAdjMatrix` now have _3 generic parameters,_ `K` for key type to access vertices and edges, `E1,` that stores vertex specific information and `E2,` to support edge specific information. Accessort methods to set/get vertex and edge data are provided.
    
    In the C++ version, E1 defaults K and E2 defaults to E1, thus, simple graphs (that dont care about vertex or edge attributes) can be declared with a single parameter for the key.
    
    Since Java does not support defaults for generic parameters, two classes `GraphAdjListSimple`, `GraphAdjMatrixSimple` are provided that provide the same functionality. These extend the graph classes with default values for the edge and vertex information types(currently set to String).
    
*   The graph classes provide convenience methods to easily set visual attributes for vertices and edges. `getVisualizer(K v)` and `getLinkVisualizer(K v1, K v2)` provide access to the visualizer objects that are then used to set any of the supported visual attributes.
*   Labels are now supported for graph edges. The label is defined as part of the `LinkVisualizer` object (`setLabel()`/`getLabel()`).
*   Faster rendering of large graphs (using Canvas)

### 2.3.2

*   Multilist element, `MLelement<E>` is now supported.