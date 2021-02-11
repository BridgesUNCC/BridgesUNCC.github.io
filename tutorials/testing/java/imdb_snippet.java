import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;

// A test class that fetches a random movie from IMDB then sends the
//	actors name and movie title + release date to the console as output.
//	There is no visual output to the users BRIDGES gallery after running this code.

public class imdb_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		DataSource ds = bridges.getDataSource();

		// Get a List of ActorMovieIMDB objects from Bridges
		List<ActorMovieIMDB> mylist = ds.getActorMovieIMDBData(1813);

		// Inspect a random ActorMovieIMDB object
		ActorMovieIMDB pair1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(pair1.getActor());
		System.out.println(pair1.getMovie());
	}
}
