/**
 * Created by Lucas Estrella on 1/31/2017.
 * lestrell@uncc.edu
 */
import java.util.ArrayList;

import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieWikidata;

// This program fragment illustrates how to access and read the Wikidata actor/movie data

public class wikidata_actor_snippet {

	public static void main(String[] args) throws Exception {

		// note: you must fill in with your Bridges credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("Accessing Wikidata Movie/Actor Data");

		// create data source object
		DataSource ds = bridges.getDataSource();

		// Get a List of Wikidata actor/movie  records from Bridges
		// get the actor movie Wikidata data through the BRIDGES API for 1955.
		// data are available from the early 20th century to now.
		ArrayList<ActorMovieWikidata> list = ds.getWikidataActorMovie(1955, 1955);

		System.out.println("Data Records in 1955: " + list.size() + "\n");

		// print out the first 3 records of the dataset
		for (int k = 0; k < 3; k++)
			System.out.println("Actor-Movie Data:\n" +
				"\tMovie: " + list.get(k).getMovieURI()  + " \""  + list.get(k).getMovieName() + "\"\n" +
				"\tActor: " +  list.get(k).getActorURI() + " \"" + list.get(k).getActorName() + "\"\n");
	}
}
