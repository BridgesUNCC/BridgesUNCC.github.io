import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr3d {
	public static void main(String[] args) throws Exception{

							//create the Bridges object
		Bridges bridges = new Bridges(2, "YOUR_API_KEY", "YOUR_USER_ID");

						// specify array dimensions and create 3D array
		int[] dims = {4, 4, 4};
		Array&lt;Integer&gt; my_array = new Array&lt;Integer&gt; (3, dims);

						// populate the elements with their array position
		int n  = 0;
		for (int k = 0; k < dims[0]; k++) {
			for (int j = 0; j < dims[1]; j++) {
				for (int i = 0; i < dims[2]; i++) {
					my_array.getValue(i, j, k).setLabel("El "+String.valueOf(n));
					n++;
				}
			}
		}
					 	// color some of the elements
		my_array.getValue(0, 0, 0).getVisualizer().setColor("red");
		my_array.getValue(0, 3, 0).getVisualizer().setColor("green");
		my_array.getValue(3, 0, 0).getVisualizer().setColor("blue");
		my_array.getValue(3, 3, 0).getVisualizer().setColor("magenta");
		my_array.getValue(1, 1, 0).getVisualizer().setColor("cyan");
		my_array.getValue(2, 2, 0).getVisualizer().setColor("yellow");

						//set visualizer type
		bridges.setDataStructure(my_array);

						// visualize the list
		bridges.visualize();
	}
}
