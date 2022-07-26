import bridges.connect.Bridges;
import bridges.base.LineChart;
import java.util.ArrayList;
import java.lang.Math;


class Complexity {

	public static void main(String args[]) throws Exception {
		Bridges bridges = new Bridges(28, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
		bridges.setServer("clone");

		bridges.setTitle("Complexity Matters");
		bridges.setDescription("Plotting the complexity of different function on different machines");



		// TODO:
		// You will be using the LineChart class to plot the performance of 
		// machines of varying capabilities (crudely approximated by clock speed!)
		// as function of input size
		//
		// Review the Line Chart tutorial at 
		// http://bridgesuncc.github.io/tutorials/LineChart.html


		LineChart lc = new LineChart();
		lc.setTitle("Something");
		lc.setXLabel("n");
		lc.setYLabel("Time in Seconds");

		// hold hte chart data in lists
		ArrayList<Double> xdata = new ArrayList<Double>();
		ArrayList<Double> ydata = new ArrayList<Double>();

		// create the function y = 10^4n, assuming 1 Mhz clock. Use the line chart
		// to plot performance (dont use all values of n, use some convenient step
		// size  to go from 1 to 10^4


		// use the setDataSeries() method of LineChart to add the plot to BRIDGES



		// Similarly, create the function y = 5*10^4n, assuming 1 Mhz clock. 

		// use the setDataSeries() method of LineChart to add the plot to BRIDGES


		// Similarly, create the function y = 100*n^2, assuming 1 Mhz clock

		// use the setDataSeries() method of LineChart to add the plot to BRIDGES


		// send the line chart data to the BRIDGES server and visualize

		// bridges.setDataStructure(lc);
		// bridges.visualize();
	}
}
