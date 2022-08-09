import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.*;
import java.util.*;



public class gutenberg_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");

		//create a bridges datasource object to use and
		//retrieve the gutenberg books
		DataSource ds = bridges.getDataSource();

		//Get Meta data for a single book
		

		//Get Meta data for a book

		System.out.println("Meta data for 1 book: Moby Dick, by Id");
		GutenbergMeta b = ds.getAGutenbergBookMetaData (2701);
			System.out.println("\tId: " + b.getId());
			System.out.println("\tTitle: " + b.getTitle());
			System.out.println("\tLanguage: " + b.getLanguage());
			System.out.println("\tDate Added:" + b.getDate());

		System.out.println("Retrieving books by title: Pride and Prejudice");
		List<GutenbergMeta> blist = ds.getGutenbergBookMetaData("Pride and Prejudice", "title");
		for (int k = 0; k < 2; k++) {
			System.out.println("\tId: " + blist.get(k).getId());
			System.out.println("\tTitle: " + blist.get(k).getTitle());
			System.out.println("\tLanguage: " + blist.get(k).getLanguage());
			System.out.println("\tDate Added: " + blist.get(k).getDate());
		}

		System.out.println("Retrieving books by Language: English");
		blist = ds.getGutenbergBookMetaData("en", "language");
		for (int k = 0; k < 2; k++) {
			System.out.println("\tId: " + blist.get(k).getId());
			System.out.println("\tTitle: " + blist.get(k).getTitle());
			System.out.println("\tLanguage: " + blist.get(k).getLanguage());
			System.out.println("\tDate Added: " + blist.get(k).getDate());
		}

		System.out.println("Retrieving books by Date: 2018");
		blist = ds.getGutenbergBookMetaData("2018-01-01", "date");
		for (int k = 0; k < 2; k++) {
			System.out.println("\tId: " + blist.get(k).getId());
			System.out.println("\tTitle: " + blist.get(k).getTitle());
			System.out.println("\tLanguage: " + blist.get(k).getLanguage());
			System.out.println("\tDate Added: " + blist.get(k).getDate());
		}
		System.out.println("Retrieving books by Author: Mark Twain");
		blist = ds.getGutenbergBookMetaData("Mark Twain", "author");
		for (int k = 0; k < blist.size(); k++) {
			System.out.println("\tId: " + blist.get(k).getId());
			System.out.println("\tTitle: " + blist.get(k).getTitle());
			String[] authors = blist.get(k).getAuthors();
			System.out.print("\tAuthors:");
			for (int j = 0; j < authors.length; j++) 
				System.out.println(authors[j] + ",");
			System.out.println("\tLanguage: " + blist.get(k).getLanguage());
			System.out.println("\tDate Added: " + blist.get(k).getDate());
		}

		System.out.println ("Retrieving book text: PRIDE AND PREJUDICE");
		String book = ds.getGutenbergBookText(1342);

		// print the first 300 chars of the book
		System.out.println("Printing the first 300 characters of the book");
		System.out.println(book.substring(0, 300));
	}
}
