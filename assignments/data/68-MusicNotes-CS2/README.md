Assignment 68 - Music Notes for cs2
========================

This assignment is a good introduction to queues, as well as reading from a file.

This assignment is inspired by a  [Nifty](http://nifty.stanford.edu/2015/obourn-stepp-melody-maker/) assignment, but using BRIDGES for the visualization and Audio API. Students create a program to read notes to a song from a file, place them in a queue, and then play the song. Included with this assignment we have the files for happy birthday, and twinkle twinkle little star. The student is welcome to write other songs or download some of the other samples from Nifty; in
fact, this would increase engagement of the assignment as it provides choices
for students to choose their own songs and share the assignemnt output 
with others.  


Goals
------
The purpose of this assignment is to learn to
1. Read Song Notes From Files
2. Manipulate Queues
3. Use the Bridges Audio API

Programming part
---------------------
### Task
Build a queue of notes from a file
### Steps
1. Open your base code.
2. Plug in your credentials.
### Build Notes queue from file
- In loadSong(), follow the TODO comment to open, read, create a note class, and add it to a queue
- Make sure to return the queue at the end 
### Build Song from Notes Queue
- In the main method:
    * Iterate over the queue to find the total length of the song
    * Iterate over the queue again to add each note to the audio clip

### Reference
[Music Theory Converting Notes to HZ](https://pages.mtu.edu/~suits/notefreqs.html)

#### Java
[Bridges Audio Clip](https://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_audio_clip.html)

[Java Queue](https://docs.oracle.com/javase/8/docs/api/java/util/Queue.html)

#### C++ 

[Bridges Audio Clip](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_audio_clip.html)

#### Python 

[Bridges Audio Clip](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1audio__clip_1_1_audio_clip.html)

