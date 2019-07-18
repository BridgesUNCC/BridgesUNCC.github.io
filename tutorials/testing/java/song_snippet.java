import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Song;

public class song_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		/* Get a List of ActorMovieIMDB objects from Bridges */
		DataSource ds = bridges.getDataSource();
		List<Song> mylist = ds.getSongData();

		/* Inspect a random ActorMovieIMDB object */
		Song song1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(song1.getSongTitle());
		System.out.println(song1.getArtist());
		System.out.println(song1.getAlbumTitle());
		System.out.println(song1.getReleaseDate());
		System.out.println(song1.getLyrics().substring(0, Math.min(100, song1.getLyrics().length())) + "...");
	}
}
