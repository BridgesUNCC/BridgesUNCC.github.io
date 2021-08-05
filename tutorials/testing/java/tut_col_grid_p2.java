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

// The second  part of the tutorial illustrates using the different ways
// to specify color for cells in the color grid.

public class tut_col_grid_p2 {

	public static void main(String[] args) throws Exception {

		// initialize BRIDGES, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("BRIDGES Color Grid Tutorial - Part 1");

		// set description
		bridges.setDescription("This is an example to illustrate different ways of setting colors in the ColorGrid");

		int width = 10, height = 10;

		Color red   = new Color("red");
		Color green = new Color("green");
		Color blue  = new Color("blue");

		ColorGrid cg  = new ColorGrid(width, height, new Color("lightgoldenrodyellow"));

		// color a few squares and make a + sign at the center
		// using named colors - full set of colors detailed in
		// in the Color class

		cg.set(5, 5, red);
		cg.set(5, 4, blue);
		cg.set(5, 6, blue);
		cg.set(4, 5, green);
		cg.set(6, 5, green);

		// tell Bridges the the color grid object to visualize
		bridges.setDataStructure(cg);

		// visualize
		bridges.visualize();

		// you can also use r,g, b, triplets to specify color
		// (in the range 0-255, for r, g, b and 0.0-1.0f for opacity)
		red =  new Color(255, 0, 0);
		green =  new Color(0, 255, 0);
		blue =  new Color(0, 0, 255);

		cg.set(5, 5, red);
		cg.set(5, 4, blue);
		cg.set(5, 6, blue);
		cg.set(4, 5, green);
		cg.set(6, 5, green);

		// visualize again
		bridges.visualize();

		red =  new Color(255, 0, 0, 0.5f);
		green =  new Color(0, 255, 0, 0.5f);
		blue =  new Color(0, 0, 255, 0.5f);

		// you can also specify a fourth component, opacity (alpha) to make
		// colors transparent. We will choose 128, halfway
		cg.set(5, 5, red);
		cg.set(5, 4, blue);
		cg.set(5, 6, blue);
		cg.set(4, 5, green);
		cg.set(6, 5, green);

		// visualize again -- note that you will see tabs to switch between
		// the 3 visualizations
		bridges.visualize();
	}
}
