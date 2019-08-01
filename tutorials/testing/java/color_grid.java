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

/**
 *  This example illustrates the use of the Grid type and its subclass, a ColorGrid.
 *  The example builds  a checkerboard with two different colors
 *
 */

public class color_grid {

	public static void main(String[] args) throws Exception {

		// This example illustrates using the Bridges color grid
		// We will build a checker grid using two different colors

		// initialize BRIDGES
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		int width = 100, height = 100;

		Color blue = new Color("blue");
		Color red = new Color("red");

		ColorGrid cg  = new ColorGrid(width, height, red);

		// create a checkerboard pattern
		// 10 x 10 grid
		int num_squares_x = 10;
		int num_squares_y = 10;

		// compute square dimensions
		int sq_width = width / num_squares_x, sq_height = width / num_squares_y;

		for (int j = 0; j < num_squares_y;  j++)
			for (int k = 0; k < num_squares_x;  k++) {

				// use even/odd value of pixel to
				// figure out the color of the square
				Boolean x_even = (k % 2) == 0;
				Boolean y_even = (j % 2) == 0;

				Color col;

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

		bridges.setDataStructure(cg);

		bridges.visualize();
	}
}
