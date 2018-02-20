import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr1d {
	public static void main(String[] args) throws Exception {

    					//create the Bridges object, set credentials
		Bridges bridges = new Bridges(0, "486749122386", "kalpathi60");
	//	Bridges bridges = new Bridges(0, "997924677918", "bridges_public");

						//  set array dimensions, allocate array of elements
    	int arraySize = 10;
		int[] dims = { arraySize, 1, 1 };
		Array<Integer> my_array = new Array<Integer> (1, dims);

						// populate the array, with squares of indices
		for (int k = 0; k < my_array.getSize(); k++) {
			my_array.setValue(k, new Element<Integer>(String.valueOf(k), k*k));
			my_array.getValue(k).getVisualizer().setColor("red");
		}

				// color the array elements
		my_array.getValue(1).getVisualizer().setColor("green");
		my_array.getValue(3).getVisualizer().setColor("blue");
		my_array.getValue(5).getVisualizer().setColor("magenta");
		my_array.getValue(7).getVisualizer().setColor("cyan");
		my_array.getValue(9).getVisualizer().setColor("yellow");

    			// tell Bridges what datastructure to visualize
		bridges.setDataStructure(my_array);

				// visualize the list
    	bridges.visualize();
    }
}
