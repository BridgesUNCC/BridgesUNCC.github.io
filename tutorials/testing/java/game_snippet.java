import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Game;

// this program fragment illustrates how to access the IGN Games data
public class game_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		/* Get a List of Game objects from Bridges */
		DataSource ds = bridges.getDataSource();
		List<Game> mylist = ds.getGameData();

		// Inspect a random Game object
		Game game1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(game1.getTitle());
		System.out.println(game1.getPlatformType());
		System.out.println(game1.getRating());
		System.out.println(game1.getGenre());
	}
}
