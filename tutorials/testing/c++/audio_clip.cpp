#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;

void generateSine(AudioClip * ac, int bit_depth) {
    for (int s = 0; s < ac->getSampleCount(); s++) {
        for (int c = 0; c < ac->getNumChannels(); c++) {
            double val = sin(s / 20.0);
            int minmax32 = (pow(2, bit_depth) / 2.0) - 1.0;

            int amp = (int)(val * minmax32);
            
            ac->setSample(c, s, amp);
        }
    }
}

int main(int argc, char*argv[]) {

	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

    bridges.setTitle("Audio Mixing");
    bridges.setDescription("sine");


    AudioClip clip (44100*.25, 1, 32, 44100);

    generateSine(&clip, 32);

    bridges.setDataStructure(clip);
    bridges.visualize();

    AudioClip clip2 (44100*.25, 1, 8, 44100);

    generateSine(&clip2, 8);

    bridges.setDataStructure(clip2);
    bridges.visualize();

    AudioClip clip3 (44100*.25, 1, 16, 44100);

    generateSine(&clip3, 16);

    bridges.setDataStructure(clip3);
    bridges.visualize();
        
	    
	    AudioClip ac2 ("../../data/clap-8bit.wav");

	    bridges.setDataStructure(ac2);

	    bridges.visualize();

	    AudioClip ac3 ("../../data/clap-16bit.wav");
		
	    bridges.setDataStructure(ac3);

	    bridges.visualize();

	    AudioClip ac4 ("../../data/clap-24bit.wav");

	    
	    bridges.setDataStructure(ac4);

	    bridges.visualize();

	    
	    AudioClip ac5 ("../../data/clap-32bit.wav");
	    
	    bridges.setDataStructure(ac5);


	    AudioClip ac6 ("../../data/piano.wav");

	    bridges.setDataStructure(ac6);

		bridges.visualize();

    
    return 0;
}
