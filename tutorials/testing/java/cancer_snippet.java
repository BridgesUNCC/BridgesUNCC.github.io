import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.CancerIncidence;

// This program fragment illustrates how to access the Cancer Incidence data
public class cancer_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
		// set title
		bridges.setTitle("How to access the Cancer Incidence Data");

		// read the IGN game data
		DataSource ds  = bridges.getDataSource();
		List<CancerIncidence> ca = ds.getCancerIncidenceData();

		System.out.println (ca.size());

		// Print a single record of the data for illustration
		System.out.println("Incident 0:");
		CancerIncidence c = ca.get(0);

		System.out.println("\tType: " + c.getEventType() + "\n"
			+ "\tYear: " + c.getYear() + "\n"
			+ "\tPopulation: " + c.getPopulation() + "\n"
			+ "\tRace: " + c.getRace() + "\n"
			+ "\tGender: " + c.getGender() + "\n"
			+ "\tCrudeRate: " + c.getCrudeRate() + "(more rate information available) \n"
			+ "\tLocation: " + c.getLocationX() + ", " + c.getLocationY() + "\n"
			+ "\tCount: " + c.getCount());
	}
}
