import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr1d {
	public static void main(String[] args) throws Exception {

    					//create the Bridges object, set credentials
		Bridges bridges = new Bridges(0, "486749122386", "kalpathi60");

						//  set array dimensions, allocate array of elements
    	int arraySize = 10;
		int[] dims = { arraySize, 1, 1 };
		Array<Integer> arr = new Array<Integer> (1, dims);

						// populate the array, with squares of indices
		for (int k = 0; k < arr.getSize(); k++) {
			arr.setValue(k, new Element<Integer>(String.valueOf(k),k*k));
		}

						// color the array elements
		arr.getValue(0).getVisualizer().setColor("red");
		arr.getValue(1).getVisualizer().setColor("green");
		arr.getValue(2).getVisualizer().setColor("blue");
		arr.getValue(3).getVisualizer().setColor("cyan");
		arr.getValue(4).getVisualizer().setColor("magenta");
		arr.getValue(5).getVisualizer().setColor("yellow");
		arr.getValue(6).getVisualizer().setColor("red");
		arr.getValue(7).getVisualizer().setColor("green");
		arr.getValue(8).getVisualizer().setColor("blue");
		arr.getValue(9).getVisualizer().setColor("black");

    			// tell Bridges what datastructure to visualize
		bridges.setDataStructure(arr);

				// visualize the list
    	bridges.visualize();
    }
}
