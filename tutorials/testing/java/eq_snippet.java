import java.util.List;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.EarthquakeUSGS;

// This program fragment illustrates how to access the USGS earthquake data
public class eq_snippet {
	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
		// read the earth quake  data and build the BST
		bridges.setTitle("Accessing USGIS Earthquake Data (USGS Data)");

		DataSource ds = bridges.getDataSource();

		// get 100 most recent earthquake records
		List<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(100);

		// print the first record
		System.out.println("Earthquake 0:");
		System.out.println ("\tMagnitude:"  + eq_list.get(0).getMagnitude() + "\n"
			+ "\tDate:" + eq_list.get(0).getTime() + "\n"
			+ "\tLocation: " +  eq_list.get(0).getLocation() + "\n"
			+ "\tLat/Long:"  + eq_list.get(0).getLatit() + "," +
			eq_list.get(0).getLongit());
	}
}
