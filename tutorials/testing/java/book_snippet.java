import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.GutenbergBook;

/*! A test class that fetches a random book from Gutenberg Book then sends the
	title, authors name, and genre to the console as output.
	There is no visual output to the users BRIDGES gallery after running this code.*/
	
public class book_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		/* Get a List of GutenbergBook objects from Bridges */
    DataSource ds = bridges.getDataSource();
    List<GutenbergBook> mylist = ds.getGutenbergBookMetaData();

		/* Inspect a random GutenbergBook object */
		GutenbergBook book1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(book1.getTitle());
		System.out.println(book1.getAuthorName());
		System.out.println(book1.getGenres());

	}
}
