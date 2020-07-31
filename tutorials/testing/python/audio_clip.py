import random
from bridges import AudioClip
from bridges import Bridges
import math
import sys


class AudioTest(AudioClip):
                
    def generate_sine(self, bit_depth: int) -> None:
        for s in range(self.sample_count):
            for c in range(self.num_channels):
                val = math.sin(s / 20)
                self.set_sample(c, s, val * ((2 ** bit_depth / 2.0) - 1.0))

def main():

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    print ("generating 32-bit sine wave")

    clip = AudioTest(sample_count=int(44100*.25), num_channels=2)

    clip.generate_sine(32)

    bridges.set_data_structure(clip)
    bridges.visualize()

    
    # Bit Depth Testing, was unsure where to put this since it requires a new clip
    

    print ("generating 8-bit sine wave")

    clip = AudioTest(sample_count=int(44100*.25), num_channels=1, sample_bits=8, sample_rate=44100)
    clip.generate_sine(8)

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("generating 16-bit sine wave")
    
    clip = AudioTest(sample_count=int(44100*.25), num_channels=1, sample_bits=16, sample_rate=44100)
    clip.generate_sine(16)

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("generating 24-bit sine wave")


    clip = AudioTest(sample_count=int(44100*.25), num_channels=1, sample_bits=24, sample_rate=44100)
    clip.generate_sine(24)

    bridges.set_data_structure(clip)
    bridges.visualize()


    print ("reading 8 bit clip")

    clip = AudioTest(filepath="../../data/clap-8bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("reading 16 bit clip")
    
    clip = AudioTest(filepath="../../data/clap-16bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("reading 24 bit clip")
    
    clip = AudioTest(filepath="../../data/clap-24bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("reading 32 bit clip")
    
    clip = AudioTest(filepath="../../data/clap-32bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    print ("reading piano clip")
    
    clip = AudioTest(filepath="../../data/piano.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()




if __name__ == "__main__":
    main()
