import bridges.base.AudioClip;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;
import bridges_external.WavFileException;

import java.io.IOException;


public class AudioMixing {

	/**
	 * Return a new AudioClip of the two AudioClips mixed together
	 * @param ac1 - will fade out in the center of the clip
	 * @param ac2 - will fade in over fade_duration in the center of the clip
	 * @param duration - is the total duration of the new AudioClip in seconds
	 *
	 * @return A new AudioClip of two AudioClips mixed together
	 */
	private static AudioClip mixClips(AudioClip ac1, AudioClip ac2, float duration) {
	    if (ac1.getSampleRate() != ac2.getSampleRate()) {
		throw new IllegalArgumentException ("sampling rate must be the same");
	    }


	    // Goal: Implement simple mixing of the two AudioClips

	    // Create a new AudioClip object that uses the duration
	    AudioClip acMix = null;
	    //acMix = new AudioClip(...);

	    // Mix the audio clips together and store the values in the new AudioClip
	    // To mix two samples together simply take their average
		
	    return acMix;
	}	
	
	private static AudioClip mixClips(AudioClip ac1, AudioClip ac2) {
	    // If no duration is given then just use the minimum song duration
	    return mixClips(ac1, ac2, Math.min((float)ac1.getSampleCount() / ac1.getSampleRate(), (float)ac2.getSampleCount()  / ac2.getSampleRate()));
	}
	

	public static void main(String[] args) throws IOException, WavFileException, RateLimitException {
		Bridges bridges = new Bridges(33, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
		
	    bridges.setTitle("Audio Mixing");
	    bridges.setDescription("Mixing two AudioClips together");

		// Path to the audio folder
		// If you have issues with unrecognized paths, try making this path absolute instead of relative
		final String AUDIO_PATH = "../audio/";

	    // Load the clips
		AudioClip acPiano = new AudioClip(AUDIO_PATH + "piano.wav");
		bridges.setDataStructure(acPiano);
		bridges.visualize();

		AudioClip acBass = new AudioClip(AUDIO_PATH + "bass.wav");
		bridges.setDataStructure(acBass);
		bridges.visualize();
		
		// Apply simple mixing of the two AudioClips and visualize
		AudioClip acMix = mixClips(acPiano, acBass);
		bridges.setDataStructure(acMix);
		bridges.visualize();
		
	}
}
