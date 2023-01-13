import bridges.connect.Bridges;
import bridges.base.Array1D;

public class purposefully_breaking2 {
	public static void main(String[] args) throws Exception {

		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("One-Dimensional Array Example");
		bridges.setDescription("One dimensional  array with visual attributes");

		//  set array dimensions, allocate array of elements
		int arraySize = 1;
		int SIZE = 17*1000*1000*2;
				
		Array1D<Integer> arr = new Array1D<Integer> (arraySize);

		// populate the array, with squares of indices
		// use the values to label the elements
		for (int k = 0; k < arr.getSize(); k++) {
			arr.getElement(k).setValue(k * k);
			arr.getElement(k).setLabel(String.valueOf(arr.getElement(k).getValue()));
		}

		
		
		StringBuilder payload = new StringBuilder();
		for (int i=0; i<SIZE; ++i) {
		    payload.append(" ");
		}
		arr.getElement(0).setLabel(payload.toString());



		// tell Bridges what datastructure to visualize
		bridges.setDataStructure(arr);

		// visualize the list
		bridges.visualize();
	}
}
