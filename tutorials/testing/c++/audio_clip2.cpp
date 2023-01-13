#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;

int main(int argc, char*argv[]) {

	// command line args provide credentials and server to test on
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");


	if (argc > 4)
		bridges.setServer(argv[4]);

    bridges.setTitle("Audio Test Example");
    bridges.setDescription("Piano test");

    // Load the clips
	string audio_file = "./piano.wav";
    AudioClip clip = AudioClip(string(audio_file));

    bridges.setDataStructure(clip);
    bridges.visualize();

    return 0;
}
