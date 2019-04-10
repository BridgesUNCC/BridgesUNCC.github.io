import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
		//  for 2D array 5x5
		int num_rows = 4, num_cols = 4;
		Array<Integer> my_array = new Array<Integer> (num_rows, num_cols);

		// populate the array
		for (int row = 0; row < num_rows; row++) {
			for (int col = 0; col < num_cols; col++) {
				my_array.getElement(row, col).setLabel("El " +
					String.valueOf(row * num_cols + col));
			}
		}

		// color some of the elements

		my_array.getElement(0, 0).getVisualizer().setColor("red");
		my_array.getElement(0, 3).getVisualizer().setColor("green");
		my_array.getElement(3, 0).getVisualizer().setColor("blue");
		my_array.getElement(3, 3).getVisualizer().setColor("magenta");
		my_array.getElement(1, 1).getVisualizer().setColor("cyan");
		my_array.getElement(2, 2).getVisualizer().setColor("yellow");

		//set visualizer type
		bridges.setDataStructure(my_array);

		// visualize the array
		bridges.visualize();
	}
}
