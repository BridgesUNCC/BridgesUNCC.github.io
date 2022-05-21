from bridges import *
import json

# Goal: Implement simple mixing of the two AudioClips
def mix_clips(ac1: AudioClip, ac2: AudioClip, duration: float = -1) -> AudioClip:
    """ Return a new AudioClip of the two AudioClips mixed together
    """
    if ac1.get_sample_rate() != ac2.get_sample_rate():
        raise "two clips must have the same sampling rate"
    
    SAMPLE_RATE = ac1.get_sample_rate()
    sample_count = (SAMPLE_RATE * duration) if duration != -1 else min(ac1.get_sample_count(), ac2.get_sample_count())

    # Create a new audio clip of appropriate length
    # using the same sampling rate
    # if duration is negative, pick the shorter of the two clips

    # Mix the audio clips together and store the values in the new AudioClip
    # To mix two samples together simply take their average

    return None

def main() -> None:
    bridges = Bridges(233, "BRIDGES_USER_ID", "BRIDGES_API_KEY")

    bridges.set_title("Audio Mixing")
    bridges.set_description("Mixing two AudioClips together")

    # Load the clips
    ac_piano = AudioClip("../audio/piano.wav")
    ac_bass = AudioClip("../audio/bass.wav")

    # Apply simple mixing of the two AudioClips and visualize
    ac_mix = mix_clips(ac_piano, ac_bass)
    bridges.set_data_structure(ac_mix)
    bridges.visualize()

    #as a bonus problem. One could mix two clips with a fade in/fade out
    
if __name__ == "__main__":
    main()
