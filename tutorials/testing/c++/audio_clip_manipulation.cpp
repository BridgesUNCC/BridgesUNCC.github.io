#include "AudioClip.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");


  
    // Title, description
        bridges.setTitle("An AudioClip Example");
        bridges.setDescription("This program takes any input audio clip and lowers its volume by half. To do this, we'll iterate through all the samples in the clip and halve them.");

        // Create the audio clip object from a .wav file
        // We do this by passing the path to the file into the constructor
        // Change the path to be any .wav file on your system.
        AudioClip oldAudioClip = AudioClip("../../data/piano.wav");

        // Create a new audio clip object to store our changes on.
        // Copy the sample count, sample bit depth, and sample rate from the old clip.
        AudioClip newAudioClip = AudioClip(oldAudioClip.getSampleCount(), 1,
                oldAudioClip.getSampleBits(), oldAudioClip.getSampleRate());

        // Iterate through every sample in the clip
        for (int i = 0; i < newAudioClip.getSampleCount(); i++){
            // Get the sample at i in the first (and only) channel.
            int sampleValue = oldAudioClip.getSample(0, i);
            // Halve the value of the sample
            int newSampleValue = sampleValue / 2;
            // Set the sample at i to the new value
            newAudioClip.setSample(0, i, newSampleValue);
        }

        // Visualize the original audio clip
        bridges.setDataStructure(oldAudioClip);
        bridges.visualize();

        //Visualize the new audio clip
        bridges.setDataStructure(newAudioClip);
        bridges.visualize();
    return 0;
}
