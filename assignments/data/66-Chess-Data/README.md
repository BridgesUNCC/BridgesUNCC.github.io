Chess Matchups
================

Goals
-----

The purpose of this assignment is to learn to
 - Use chess matchup dataset (from Lichess.org)
 - Determine how many games Alireza2003 (the number one player on Lichess.org) won/lost/drew out of his last 50.
 - Use BRIDGES to visualize solution

### Assignment Tasks
1. Use the Game class to access games json
2. Add a vertex for each unique username
3. Add an edge between Alireza2003 and every other vertex
4. Color edges depending on game outcome, if Alireza2003 won the edge is green, if he lost the edge is red, if the game was a draw the edge is grey
5. OPTIONAL: Color each vertex to reflect their piece color in the game (e.g. If RebeccaHarris1 played as the white pieces, color their vertex to be white)
6. Visualize


Expected Output:
----------------
![Solution](figures/Solution.png)


### Help
#### For C++
[GraphAdjList](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_graph_adj_list.html)

#### For Java
[GraphAdjListSimple](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_graph_adj_list_simple.html)

#### For Python
[GraphAdjList](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1graph__adj__list_1_1_graph_adj_list.html)
