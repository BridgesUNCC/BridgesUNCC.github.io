import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Shakespeare;

// a program fragment to access the Shakespeare data (plays, poems)
public class shakespeare_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		// Get a List of Shakespeare objects from Bridges
		DataSource ds = bridges.getDataSource();
		List<Shakespeare> mylist = ds.getShakespeareData();

		// Inspect a random Shakespeare object
		Shakespeare work1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(work1.getTitle());
		System.out.println(work1.getType());
		System.out.println(work1.getText().substring(0, Math.min(100, work1.getText().length())) + "...");
	}
}
