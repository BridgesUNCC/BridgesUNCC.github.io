/**
 * Created by Kalpathi Subramanian
 * Date : 7/17/2018.
 *
 * krs@uncc.edu
 */
import java.lang.String;
import bridges.connect.Bridges;
import bridges.base.SLelement;
import bridges.base.Color;
import bridges.base.ColorGrid;

// This tutorial illustrates using the Bridges Color Grid
// and how to set elements within the grid

public class tut_col_grid_p1 {

	public static void main(String[] args) throws Exception {

		// initialize BRIDGES, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("BRIDGES Color Grid Tutorial - Part 1");

		// set description
		bridges.setDescription("This is an example of the color grid with height and width of 10 units each");

		int width = 10, height = 10;

		Color red   = new Color("red");
		Color green = new Color("green");
		Color blue  = new Color("blue");

		ColorGrid cg  = new ColorGrid(width, height, new Color("lightgoldenrodyellow"));

		// color a few squares and make a + sign at the center

		cg.set(5, 5, red);
		cg.set(5, 4, blue);
		cg.set(5, 6, blue);
		cg.set(4, 5, green);
		cg.set(6, 5, green);

		// tell Bridges the the color grid object to visualize
		bridges.setDataStructure(cg);

		// visualize
		bridges.visualize();
	}
}
