#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;

/** 
 * Return a new AudioClip of the two AudioClips mixed together
*/
AudioClip mixClips(const AudioClip& ac1, const AudioClip& ac2, float duration) {
  if (ac1.getSampleRate() != ac2.getSampleRate()) {
    throw "can't mix audio clips of varying rates";
  }

  //create an audio clip configured appropriately
  int SAMPLE_RATE = ac1.getSampleRate();
  int sampleCount = SAMPLE_RATE * duration;
  
  AudioClip acMix = AudioClip(sampleCount, 1, ac1.getSampleBits(), SAMPLE_RATE);

  // Loop through the samples of both clips and use the average amplitude value
  // TODO
  
  return acMix;
}	

AudioClip mixClips(const AudioClip& ac1, const AudioClip& ac2) {
  // If no duration is given then just use the minimum song duration
  return mixClips(ac1, ac2, min((float)ac1.getSampleCount() / ac1.getSampleRate(), (float)ac2.getSampleCount()  / ac2.getSampleRate()));
}

int main() {
    Bridges bridges = Bridges(133, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
    bridges.setTitle("Audio Mixing");
    bridges.setDescription("Mixing two AudioClips together");

    // Load the clips
    AudioClip acPiano = AudioClip("../audio/piano.wav");
    bridges.setDataStructure(acPiano);
    bridges.visualize();
    
    AudioClip acBass = AudioClip("../audio/bass.wav");
    bridges.setDataStructure(acBass);
    bridges.visualize();
    
    // Apply simple mixing of the two AudioClips and visualize
    AudioClip acMix = mixClips(acPiano, acBass);
    bridges.setDataStructure(acMix);
    bridges.visualize();

    // One could do a more complex mixing that fades out one clip while the other fades in
    // TODO
    
    return 0;
}
