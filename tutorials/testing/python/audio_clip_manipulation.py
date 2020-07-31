from bridges import AudioClip
from bridges import Bridges
import sys
import math

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    
    # Title, description
    bridges.set_title("An AudioClip Example")
    bridges.set_description("This program takes any input audio clip and lowers its volume by half. To do this, we'll" +
                " iterate through all the samples in the clip and halve them.")

    # Create the audio clip object from a .wav file
    # We do this by passing the path to the file into the constructor
    # Change the path to be any .wav file on your system.
    oldAudioClip = AudioClip("../../data/piano.wav")

    # Create a new audio clip object to store our changes on.
    # Copy the sample count, sample bit depth, and sample rate from the old clip.
    newAudioClip = AudioClip(sample_count=oldAudioClip.get_sample_count(), num_channels=1,
            sample_bits=oldAudioClip.get_sample_bits(), sample_rate=oldAudioClip.get_sample_rate())

    # Iterate through every sample in the clip
    for i in range(newAudioClip.get_sample_count()):
        # Get the sample at i in the first (and only) channel.
        sampleValue = oldAudioClip.get_sample(0, i)
        # Halve the value of the sample
        newSampleValue = int(sampleValue / 2)
        # Set the sample at i to the new value
        newAudioClip.set_sample(0, i, newSampleValue)

    # Visualize the original audio clip
    bridges.set_data_structure(oldAudioClip)
    bridges.visualize()

    #Visualize the new audio clip
    bridges.set_data_structure(newAudioClip)
    bridges.visualize()

if __name__ == "__main__":
    main()
