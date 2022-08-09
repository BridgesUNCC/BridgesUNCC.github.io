import java.util.ArrayList;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Reddit;


// This program fragment illustrates how to access the reddit data
public class reddit {
	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
		// read the earth quake  data and build the BST
		bridges.setTitle("Accessing Reddit Data");

		DataSource ds = bridges.getDataSource();

		//ds.setSourceType("local");
		

		ArrayList<String> subreddits = ds.getAvailableSubreddits();
		System.out.println ("all subreddits available:");
		for (String subred : subreddits) {
		    System.out.println(subred);
		}

		// get some data from the  "News" subreddit
		ArrayList<Reddit> reddit_posts = ds.getRedditData("askscience", -9999);
		int limit_posts = 10, i = 0;   // print upto 10 posts
		for (Reddit r: reddit_posts) {
			if  (i++ < limit_posts) {
		    	System.out.println("ID: "+r.getID());
		    	System.out.println("Title: "+r.getTitle());
		    	System.out.println("Author: "+r.getAuthor());
		    	System.out.println("Score: "+r.getScore());
		    	System.out.println("VoteRatio: "+r.getVoteRatio());
		    	System.out.println("CommentCount: "+r.getCommentCount());
		    	System.out.println("Subreddit: "+r.getSubreddit());
		    	System.out.println("PostTime: "+r.getPostTime());
		    	System.out.println("URL: "+r.getURL());
		    	System.out.println("Text: "+r.getText());
		    	System.out.println("");
			}
		}
		
	}
}
