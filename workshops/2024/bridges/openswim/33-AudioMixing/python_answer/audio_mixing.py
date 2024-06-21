from bridges import *
import json

# Return a new AudioClip of the two AudioClips mixed together
def mix_clips(ac1: AudioClip, ac2: AudioClip, duration: float = -1) -> AudioClip:
    if ac1.get_sample_rate() != ac2.get_sample_rate():
        raise "two clips must have the same sampling rate"
    
    SAMPLE_RATE = ac1.get_sample_rate()
    sample_count = (SAMPLE_RATE * duration) if duration != -1 else min(ac1.get_sample_count(), ac2.get_sample_count())

    # Create a new audio clip that holds n (duration) seconds of data
    ac_mix = AudioClip(sample_count=sample_count, num_channels=1, sample_bits=ac1.get_sample_bits(), sample_rate=SAMPLE_RATE)

    # Loop through the samples of both clips and use the average amplitude value
    for i in range(ac_mix.get_sample_count()):
        sample1 = ac1.get_sample(0, i)
        sample2 = ac2.get_sample(0, i)
        
        ac_mix.set_sample(0, i, (sample1 + sample2) / 2)
        
    return ac_mix
    
def mix_fade_clips(ac1: AudioClip, ac2: AudioClip, fade_duration: float = -1, duration: float = -1) -> AudioClip:
    """ Return a new AudioClip of the two AudioClips faded together
        ac1 will fade out in the center of the clip
        ac2 will fade in over fade_duration in the center of the clip
    """

    if ac1.get_sample_rate() != ac2.get_sample_rate():
        raise "two clips must have the same sampling rate"

    # If no duration is given (-1) then just use the minimum song sample_count
    SAMPLE_RATE = ac1.get_sample_rate()
    sample_count = (SAMPLE_RATE * duration) if duration != -1 else min(ac1.get_sample_count(), ac2.get_sample_count())

    # Create a new audio clip that holds n (duration) seconds of data
    ac_mix = AudioClip(sample_count=sample_count, num_channels=1, sample_bits=ac1.get_sample_bits(), sample_rate=SAMPLE_RATE)

    # Get half of the song for the fade center point
    center = ac_mix.get_sample_count() // 2

    # Get the number of samples that the songs should fade in/out
    fade_samples = (SAMPLE_RATE * fade_duration) if fade_duration != -1 else center

    # Ensure the fade duration does not exceed the clip duration
    fade_samples = min(fade_samples, ac_mix.get_sample_count())

    # Get half of the fade samples for easier centering on the clip
    # ensure the samples are correctly split when of an odd number
    fade_half1 = fade_samples // 2
    fade_half2 = fade_half1 - (fade_samples // 2)

    # Calculate the start, end, and lenght of the fade section
    start = center - fade_half1
    end = center + fade_half2

    for i in range(ac_mix.get_sample_count()):
        # Get the two samples to be mixed
        # sample1 starts at full amplitude and fades out after start until end
        # sample2 starts at 0 amplitude and fades in after start until end
        sample1 = int(ac1.get_sample(0, i) * (max(0, fade_samples - (i - start)) / fade_samples))
        sample2 = 0
        
        if i >= start:
            sample2 = int(ac2.get_sample(0, i) * (min(fade_samples, (i - start)) / fade_samples))
        
        ac_mix.set_sample(0, i, (sample1 + sample2) / 2)

    return ac_mix

def main():
    bridges = Bridges(233, "BRIDGES_USER_ID", "BRIDGES_API_KEY")
    
    bridges.set_title("Audio Mixing")
    bridges.set_description("Mixing two AudioClips together")
    
    # Path to the audio folder
    AUDIO_PATH = "../audio/"
    
    # Load the clips
    ac_piano = AudioClip(AUDIO_PATH + "piano.wav")
    bridges.set_data_structure(ac_piano)
    bridges.visualize()
    
    ac_bass = AudioClip(AUDIO_PATH + "bass.wav")
    bridges.set_data_structure(ac_bass)
    bridges.visualize()
    
    # Apply simple mixing of the two AudioClips and visualize
    ac_mix = mix_clips(ac_piano, ac_bass)
    bridges.set_data_structure(ac_mix)
    bridges.visualize()

    # Apply fade mixing to the two AudioClips and visualize
    ac_fade = mix_fade_clips(ac_piano, ac_bass, 2, 5)
    bridges.set_data_structure(ac_fade)
    bridges.visualize()

if __name__ == '__main__':
    main()
