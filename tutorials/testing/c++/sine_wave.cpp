#include "AudioClip.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
    
    // Title, description
    bridges.setTitle("Sine Wave");
    bridges.setDescription("This program creates a sine wave audio clip to demonstrate the process of creating an audio clip from scratch.");

    // Create an audio clip to add the samples to
        const int SAMPLE_RATE = 44100; // Hz
        const int NUM_SAMPLES = SAMPLE_RATE * 10; //10 seconds
        AudioClip ac = AudioClip(NUM_SAMPLES, 1, 32, SAMPLE_RATE);

        // Iterate through every sample in the clip
        for (int i = 0; i < ac.getSampleCount(); i++){

            // Number of oscillations per second, 261.63 is middle C
            double frequency = 261.63;
            // Where the cycle is at i = 0
            double phase = 0;
            // The maximum amplitude of the wave (value of the highest point)
            double amplitude = INT_MAX / 4.0;
            // The current second (with decimals) of the clip
            double time = (double)i / SAMPLE_RATE;
            // This gives the sine curve
            double val = sin((2 * M_PI)  * frequency * time + phase);
            // Scale the curve up to the amplitude and cast to int
            int sampleValue = (int)(val * amplitude);

            // Set the sample at i to the new value
            ac.setSample(0, i, sampleValue);
        }

        // Visualize the audio clip
        bridges.setDataStructure(ac);
        bridges.visualize();
    return 0;
}
