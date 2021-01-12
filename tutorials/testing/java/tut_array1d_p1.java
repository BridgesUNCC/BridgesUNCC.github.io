import bridges.connect.Bridges;
import bridges.base.Array1D;

// This tutorial describes how to create a 1 dimensional array, populate
// it with integer values and display them

public class tut_array1d_p1 {
	public static void main(String[] args) throws Exception {

		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("One-Dimensional Array Example");

		// set description
		bridges.setDescription("Create a 1 dimensional array with integer values and display them");

		//  set array dimensions, allocate array of elements
		int arraySize = 10;

		Array1D<Integer> arr = new Array1D<Integer> (arraySize);

		// populate the array, with squares of indices
		for (int k = 0; k < arr.getSize(); k++) {
			arr.getElement(k).setValue(k * k);

			// use the array values to label the elements
			arr.getElement(k).setLabel(String.valueOf(arr.getElement(k).getValue()));
		}

		// tell Bridges the  datastructure to visualize
		bridges.setDataStructure(arr);

		// visualize the list
		bridges.visualize();
	}
}
