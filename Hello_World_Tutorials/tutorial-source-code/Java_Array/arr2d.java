import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception{

						//create the Bridges object
		Bridges bridges = new Bridges(1, "YOUR_API_KEY", "YOUR_USER_ID");

						//  for 2D array 5x5
		int columns = 5;
		int rows = 5;
						// set dimensions, create array
		int[] dims = {columns, rows, 1};
		Array&lt;Integer&gt; my_array = new Array&lt;Integer&gt; (2, dims);

						// populate the array
		int k = 0;
		for (int row = 0; row < rows; row++){
			for (int col = 0; col < columns; col++){
				my_array.setValue(row, col,  new Element&lt;Integer&gt;String.valueOf(k), k*k));
				k++;
			}
		}

						// color some of the elements
		my_array.getValue(0,0).getVisualizer().setColor("green");
		my_array.getValue(0,4).getVisualizer().setColor("blue");
		my_array.getValue(2,2).getVisualizer().setColor("cyan");
		my_array.getValue(4,0).getVisualizer().setColor("magenta");
		my_array.getValue(4,4).getVisualizer().setColor("yellow");

							//set visualizer type
		bridges.setDataStructure(my_array);

							// visualize the array
		bridges.visualize();
	}
}
