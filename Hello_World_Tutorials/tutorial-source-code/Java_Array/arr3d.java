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
					my_array.setValue(i, j, k, new Element&lt;Integer&gt;(String.valueOf(n), n));
					n++;
				}
			}
		}
					 	// color some of the elements
		my_array.getValue(0, 3, 0).getVisualizer().setColor(0, 255, 255, 1.0f);
		my_array.getValue(0, 3, 1).getVisualizer().setColor("green");
		my_array.getValue(0, 3, 2).getVisualizer().setColor("blue");
		my_array.getValue(0, 3, 3).getVisualizer().setColor("magenta");

						//set visualizer type
		bridges.setDataStructure(my_array);

						// visualize the list
		bridges.visualize();
	}
}
