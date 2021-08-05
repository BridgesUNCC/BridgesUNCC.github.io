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

// In the final part of this  tutorial we will build a checkerboard
// pattern using the ColorGrid

public class tut_col_grid_p3 {

	public static void main(String[] args) throws Exception {

		// initialize BRIDGES, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("BRIDGES Color Grid Tutorial - Part 3");

		// set description
		bridges.setDescription("This example generates a checkerboard pattern");

		int width = 10, height = 10;

		// create a 10 by 10 color grid
		ColorGrid cg  = new ColorGrid(width, height, new Color("lightgoldenrodyellow"));

		// create a checkerboard pattern of  10 x 10 squares
		int num_squares_x = 10;
		int num_squares_y = 10;

		// compute square dimensions
		int sq_width = width / num_squares_x,
			sq_height = width / num_squares_y;

		Color col = new Color("white");
		Color red = new Color("red");
		Color blue = new Color("blue");

		for (int j = 0; j < num_squares_y;  j++)
			for (int k = 0; k < num_squares_x;  k++) {
				// use even/odd of pixel to figure out the color of the square
				Boolean x_even = (k % 2) == 0;
				Boolean y_even = (j % 2) == 0;

				if (y_even)
					col = (x_even) ? red : blue;
				else
					col = (x_even) ? blue : red;

				// find the address of the square
				int origin_x = k * sq_width;
				int origin_y = j * sq_height;

				// color the square
				for (int row = origin_y; row < origin_y + sq_height; row++)
					for (int column = origin_x; column < origin_x + sq_width; column++)
						cg.set(row, column, col);
			}

		// tell Bridges the the color grid object to visualize
		bridges.setDataStructure(cg);

		// visualize
		bridges.visualize();

	}
}
