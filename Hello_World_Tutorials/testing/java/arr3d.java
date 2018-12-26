import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr3d {
	public static void main(String[] args) throws Exception {

		//create the Bridges object

		Bridges bridges = new Bridges(202, "YOUR_USER_ID", "YOUR_API_KEY");

		// specify array dimensions and create 3D array
		int num_slices = 4, num_rows = 4, num_cols = 4;
		Array<Integer> my_array = new Array<Integer> (num_slices, num_rows, num_cols);

		// populate the elements with their array position
		int n  = 0;
		for (int k = 0; k < num_slices; k++) {
			for (int j = 0; j < num_rows; j++) {
				for (int i = 0; i < num_cols; i++) {
					my_array.getElement(i, j, k).setLabel("El " + String.valueOf(n));
					n++;
				}
			}
		}
		// color some of the elements
		my_array.getElement(0, 0, 0).getVisualizer().setColor("red");
		my_array.getElement(0, 3, 0).getVisualizer().setColor("green");
		my_array.getElement(3, 0, 0).getVisualizer().setColor("blue");
		my_array.getElement(3, 3, 0).getVisualizer().setColor("magenta");
		my_array.getElement(1, 1, 0).getVisualizer().setColor("cyan");
		my_array.getElement(2, 2, 0).getVisualizer().setColor("yellow");

		//set visualizer type
		bridges.setDataStructure(my_array);

		// visualize the list
		bridges.visualize();
	}
}

