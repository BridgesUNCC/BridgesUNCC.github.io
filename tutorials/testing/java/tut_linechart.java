import bridges.base.LineChart;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;

import java.io.IOException;
import java.util.*;
import java.util.function.Consumer;

public class tut_linechart {

	public static void main(String[] args) throws IOException, RateLimitException, InterruptedException {
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// create plot, set title
		LineChart plot = new LineChart();
		plot.setTitle("linechart plot");

		// plot 1 with 3 points
		double x1[] = new double[] {1, 3, 5, 20};
		double y1[] = new double[] {2, 3, 5, 20};
		plot.setDataSeries("1", x1, y1);

		// plot 2 with 2 points
		double x2[] = new double[] {2, 15.2,  40};
		double y2[] = new double[] {4, 30.5, 400.99};
		plot.setDataSeries("2", x2, y2);

		// visualize
		bridges.setDataStructure(plot);
		bridges.visualize();


		// plot using logarithmic scale
		plot.toggleLogarithmicX(true);
		plot.toggleLogarithmicY(true);

		// allow mouse tracking
		plot.toggleMouseTrack(true);


		// visualize
		bridges.visualize();
	}

}
