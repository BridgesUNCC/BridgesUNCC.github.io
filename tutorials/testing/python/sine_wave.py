from bridges import AudioClip
from bridges import Bridges
import sys
import math

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # Title, description
    bridges.set_title("An AudioClip Example")
    bridges.set_description("This program creates a sine wave audio clip to demonstrate the " +
            "process of creating an audio clip from scratch.")

    # Create an audio clip to add the samples to
    SAMPLE_RATE = 44100 # Hz
    NUM_SAMPLES = SAMPLE_RATE * 10 #10 seconds
    ac = AudioClip(sample_count=NUM_SAMPLES, num_channels=1, sample_bits=32, sample_rate=SAMPLE_RATE)

    # Iterate through every sample in the clip
    for i in range(ac.get_sample_count()):
        # Number of oscillations per second, 261.63 is middle C
        frequency = 261.63
        # Where the cycle is at i = 0
        phase = 0
        # The maximum amplitude of the wave (value of the highest point)
        amplitude = 2**31 / 4.0
        # The current second (with decimals) of the clip
        time = i / SAMPLE_RATE
        # This gives the sine curve
        val = math.sin((2 * math.pi)  * frequency * time + phase)
        # Scale the curve up to the amplitude and cast to int
        sampleValue = val * amplitude
        
        # Set the sample at i to the new value
        ac.set_sample(0, i, sampleValue)

    # Visualize the audio clip
    bridges.set_data_structure(ac)
    bridges.visualize()

if __name__ == "__main__":
    main()
