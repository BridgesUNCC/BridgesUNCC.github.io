Assignment 7 - Grid Lyrics
==========================

Goals
-----

The purpose of this assignment is to learn to
1. Access lyrics data through BRIDGES.
2. Manipulate a `ColorGrid` object.
3. Show repetition patterns in songs.

You will generate a visualization that looks like [that](http://bridges-cs.herokuapp.com/assignments/7/bridges_workshop)!


Programming part
----------------

### Task

In this assignment, the objective is to pull a song from Bridges, split the lyrics into 
 individual words, and compare each word against every other word to check for repetition.

 From these lyrics, you will be building a matrix, or a `ColorGrid` in this case, where every row and 
 every column represents a sequential word in the song's lyrics.

 Upon finding repetition, you will be setting the pixel at that location to a color 
 of your choice at that point in the grid.

### Basic

1. Open your scaffolded code.
2. Plug in your credentials.
3. Complete the TODO's.
4. Run and visualize the code.

### Build a ColorGrid 

1. Plug in your credentials.
2. Think of any song which contains words.
3. Query `Bridges` for said `Song`. For example
  - in Java
   ```Java
	Song mySong = Bridges.getSong("My Favorite Song", "Optional Artist String");	
	String lyrics = mySong.getLyrics();
   ```
   - in C++
   ```C++
	Song mySong = DataSource::getSong("My Favorite Song", "Optional Artist String");	
	auto lyrics = mySong.getLyrics();
   ```
   - in Python
   ```python
   so = get_song("My Favorite Song", "Optional Artist String")
   song = so.get_lyrics()
   ```
4. Pass these lyrics through the provided helper function, which will clean up and split the
 lyrics into an array of squeaky clean `String`s.

5. Initialize a `ColorGrid` with the dimensions the size of the array returned from the helper function.

6. Iterate over the split lyrics array, checking to see if there is any repetition. For example, if 
 word 1 is the same as the word 6, you would color the pixel at (1, 6), and later on at (6, 1).

7. After filling out your grid, set it as the data structure on your Bridges object, and run the code.


### Help

#### for Java

[ColorGrid documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_color.html)


[DataSource documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1connect_1_1_data_source.html)

[Song documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1data__src__dependent_1_1_song.html)

[Bridges class documentation](http://bridgesuncc.github.io/doc/java-api/current/html/namespacebridges_1_1base.html)

#### for C++

[ColorGrid documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color_grid.html)

[Color documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_color.html)

[Song documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_song.html)

[DataSource documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_data_source.html)

#### For Python
[Bridges documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1bridges_1_1_bridges.html)

[Color documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color_1_1_color.html)

[ColorGrid documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1color__grid_1_1_color_grid.html)
