import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ElevationData;

// a program fragment to access the Elevation data
public class elevation_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		// Get a List of Shakespeare objects from Bridges
		DataSource ds = bridges.getDataSource();
		ElevationData elev_data = ds.getElevationData(6.020558108041891,46.10757941505641,
							      9.707863253414155,47.77059916141684, 0.02);


		System.out.println("Width: "+elev_data.getCols());
		System.out.println("Height: "+elev_data.getRows());
		System.out.println("Resolution: "+elev_data.getCellSize());
		System.out.println("Lower Left Corner: "+elev_data.getxll()+", "+elev_data.getyll());

		System.out.println("first 10 elevations:");
		for (int i=0; i<10; ++i) {
		    System.out.println(elev_data.getData()[0][i]);
		}

		
	}
}
