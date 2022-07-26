import bridges.connect.Bridges;
import bridges.validation.RateLimitException;
import java.io.IOException;
import bridges.base.AudioClip;
import bridges_external.WavFileException;

public class AudioMixing {
    /** 
     * Return a new AudioClip of the two AudioClips mixed together
    */
	private static AudioClip mixClips(AudioClip ac1, AudioClip ac2, float duration) {
	    if (ac1.getSampleRate() != ac2.getSampleRate()) {
		throw new IllegalArgumentException ("sampling rate must be the same");
	    }
	    
	    int SAMPLE_RATE = ac1.getSampleRate();
	    int sampleCount = (int)(SAMPLE_RATE * duration);
		
		AudioClip acMix = new AudioClip(sampleCount, 1, ac1.getSampleBits(), SAMPLE_RATE);

	    // Loop through the samples of both clips and use the average amplitude value
		for (int i = 0; i < acMix.getSampleCount(); i++) {
			int sample1 = ac1.getSample(0, i);
			int sample2 = ac2.getSample(0, i);
			
	        acMix.setSample(0, i, (sample1 + sample2) / 2);
		}
		
		return acMix;
	}	
	
	private static AudioClip mixClips(AudioClip ac1, AudioClip ac2) {
	    // If no duration is given then just use the minimum song duration
	    return mixClips(ac1, ac2, Math.min((float)ac1.getSampleCount() / ac1.getSampleRate(), (float)ac2.getSampleCount()  / ac2.getSampleRate()));
	}
	
    /** 
     * Return a new AudioClip of the two AudioClips mixed together
    */
	private static AudioClip mixFadeClips(AudioClip ac1, AudioClip ac2, float fadeDuration, float duration) {
	    if (ac1.getSampleRate() != ac2.getSampleRate()) {
		throw new IllegalArgumentException ("sampling rate must be the same");
	    }

	     int SAMPLE_RATE = ac1.getSampleRate();
	     int sampleCount = (int)(SAMPLE_RATE * duration);
		
		AudioClip acMix = new AudioClip(sampleCount, 1, ac1.getSampleBits(), SAMPLE_RATE);
		
		// Get half of the song for the fade center point
	    int center = acMix.getSampleCount() / 2;

	    //  Get the number of samples that the songs should fade in/out
	    int fadeSamples = (int)(SAMPLE_RATE * fadeDuration);
	    
	    // Ensure the fade duration does not exceed the clip duration
	    fadeSamples = Math.min(fadeSamples, acMix.getSampleCount());
	    
	    // Get half of the fade samples for easier centering on the clip
	    // ensure the samples are correctly split when of an odd number
	    int fadeHalf1 = fadeSamples / 2;
	    int fadeHalf2 = fadeHalf1 - (fadeSamples / 2);
	    
	    // Calculate the start, end, and length of the fade section
	    int start = center - fadeHalf1;
	    int end = center + fadeHalf2;
	    
	    // Loop through the samples of both clips and use the average amplitude value
		for (int i = 0; i < acMix.getSampleCount(); i++) {
	        // Get the two samples to be mixed
			// sample1 starts at full amplitude and fades out after start until end
	        // sample2 starts at 0 amplitude and fades in after start until end
	        int sample1 = (int)(ac1.getSample(0, i) * (Math.max(0, fadeSamples - (i - start)) / (float)fadeSamples));
	        int sample2 = 0;

	        if (i >= start)
	            sample2 = (int)(ac2.getSample(0, i) * (Math.min(fadeSamples, (i - start)) / (float)fadeSamples));
	            
	        acMix.setSample(0, i, (sample1 + sample2) / 2);
		}
		
		return acMix;
	}

	private static AudioClip mixFadeClips(AudioClip ac1, AudioClip ac2) {
	    // If no duration is given then just use the minimum song duration
	    float duration = Math.min((float)ac1.getSampleCount() / ac1.getSampleRate(), (float)ac2.getSampleCount()  / ac2.getSampleRate());

	    // If no fade duration is given then use half the total duration
		float fadeDuration = duration / 2;
		
		return mixFadeClips(ac1, ac2, fadeDuration, duration);
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
		
		// Apply fade mixing to the two AudioClips and visualize
		AudioClip acFadeMix = mixFadeClips(acPiano, acBass);
		bridges.setDataStructure(acFadeMix);
		bridges.visualize();
	}
}
