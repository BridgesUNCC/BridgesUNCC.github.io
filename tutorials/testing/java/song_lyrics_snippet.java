import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Song;
import java.util.ArrayList;

// a program fragment illustrating how to access the song lyrics data set

public class song_lyrics_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		// set title
		bridges.setTitle("Accessing Song Data");

		// create data source object
		DataSource ds  = bridges.getDataSource();

		// Get Song data
		Song s = ds.getSong("Harder Faster Better Stronger", "Daft Punk");


		// print song attributes
		System.out.println(s.getSongTitle());
		System.out.println(s.getArtist());
		System.out.println(s.getAlbumTitle());
		System.out.println(s.getReleaseDate());
		System.out.println(s.getLyrics());
	}
}
