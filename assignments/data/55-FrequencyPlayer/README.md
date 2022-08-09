Assignment 55 - Frequency Player
============

Goals
-----
The purpose of this assignment is to learn to
 - Use methods/functions to compartmentalize code
 - Use loops to iterate over large quantities of items
 - Apply simple mathematical concepts in code
 - Understand and cast between data types

Programming
-----------
### Tasks
 - Complete the `generateSineSample()` method. It should return a sample value according to the mathematical formula for a sine wave,
 which is `A * sin(2 * pi * f * t)`, where A is amplitude, f is frequency, and t is time.
 - Reassign `firstSample` and `lastSample` so that they use the `start` and `end` parameters in the method.
 `start` and `end` are measured in seconds, so you'll need to convert those to sample indices somehow.
 - If a sine wave ends on a sample value other than zero, it makes a noticeable cracking noise.
 Try listening for it in the middle of the clip after completing step 2.
 To fix this, you'll need to reassign `lastSample` so that it's close to the `end` second, but still ends on a sample with a value of zero.
 The `period` variable may be useful for this, although it isn't strictly necessary.


### Important Functions
- Math.sin() outputs the sine of the value passed into it.
- ac.getSampleRate(), where ac is an AudioClip, gets the sample rate of that AudioClip.
- ac.setSample(channel, index, value), where ac is an AudioClip, sets the sample at the index to the value passed in.
See the documentation for language-specific details.

### Help
#### For Java
[AudioClip documentation](http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_audio_clip.html)
#### For C++
[AudioClip documentation](http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_audio_clip.html)
#### For Python
[AudioClip documentation](http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1audio__clip_1_1_audio_clip.html)
