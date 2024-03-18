# Assignment 33 - Audio Mixing

## Example Output

<img src="./audio.png" alt="image" width="550"></img>


## Learning Outcomes

1. File input/output
2. Data visualization
3. Audio processing


## Goals

 The purpose of this assignment is to learn to
 1. Mix two audio sources together to create one
 2. Fade two audio source into one another


## Description

### How Audio is Structured
The AudioClip object contains a list of channels and each channel contains a list of samples. For this assignment the audio we are creating will only be using one channel.

### How Audio is Mixed
To mix two samples together you take the average of the two values. So if you have two samples 2 and 10 then their mixed value is...

> (2 + 10) / 2 = 6

### Tasks

#### Part 1 - Simple Audio Mixing
The first goal is to simply mix two audio sources together. Look at your scaffold code and read through the comments. Implement all of the TODOs for the mix clips method. Run the code and listen to the values and ensure that the two sounds have been properly mixed together.

#### Part 2 - Audio Mixing with Fade

The goal of this part is to fade one audio source out while another audio source fades in. Think about how song compilations will fade a song out near the end while fading in the next song so that the trasition is smooth. Look through the TODOs for the mix fade clips method. Uncomment the 2nd visualize code in main and run the code. Ensure that the two sound sources fade into each other in the center of the new clip.


## Extensions


## Help

#### For Java
[AudioClip Documentation](https://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_audio_clip.html)

#### For C++
[AudioClip Documentation](https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_audio_clip.html)

#### For Python
[AudioClip Documentation](https://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1audio__clip_1_1_audio_clip.html)

