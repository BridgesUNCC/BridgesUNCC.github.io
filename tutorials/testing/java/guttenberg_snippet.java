import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.GutenbergBook;

// 	A test class that fetches a random book from Gutenberg Book then sends the
//	title, authors name, and genre to the console as output.
public class guttenberg_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		// Get a List of GutenbergBook objects from Bridges
		DataSource ds = bridges.getDataSource();
		List<GutenbergBook> mylist = ds.getGutenbergBookMetaData();

		// Inspect a random GutenbergBook object
		GutenbergBook book1 = mylist.get(0);
		//		System.out.println(book1.getTitle());
		//		System.out.println(book1.getAuthorName());
		//		System.out.println(book1.getGenres());

		// print the first book record
		System.out.println("Guttenberg Book Data:"
			+ "\tAuthor: "  + book1.getAuthorName() + "\n"
			+ "\tAuthor Birth: "  + book1.getAuthorBirth() + "\n"
			+ "\tAuthor Death: "  + book1.getAuthorBirth() + "\n"
			+ "\tTitle: "  + book1.getTitle() +  "\n" +
			"\tLanguage: ") ;
		for (int i = 0; i < book1.getLanguages().size(); i++)
			System.out.println ("\t\t" + book1.getLanguages().get(i));
		System.out.println("\tSubject: ");
		for (int i = 0; i < book1.getSubjects().size(); i++)
			System.out.println ("\t\t" + book1.getSubjects().get(i));
		System.out.println("\tNum Downloads: " + book1.getNumDownloads() + "\n" +
			"\tNum Words: "  + book1.getNumWords() + "\n" +
			"\tNum Difficult Words: "  + book1.getNumDifficultWords() + "\n" +
			"\tNum Sentences: " + book1.getNumSentences() + "\n" +
			"\tNum Characters: " +  book1.getNumChars());
	}
}
