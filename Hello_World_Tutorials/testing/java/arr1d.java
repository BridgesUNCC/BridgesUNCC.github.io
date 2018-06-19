import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr1d {
	public static void main(String[] args) throws Exception {

		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");

		//  set array dimensions, allocate array of elements
		int arraySize = 10;

		Array<Integer> arr = new Array<Integer> (arraySize);

		// populate the array, with squares of indices
		for (int k = 0; k < arr.getSize(); k++) {
			arr.getElement(k).setValue(k * k);
		}

		// color the array elements
		arr.getElement(0).getVisualizer().setColor("red");
		arr.getElement(1).getVisualizer().setColor("green");
		arr.getElement(2).getVisualizer().setColor("blue");
		arr.getElement(3).getVisualizer().setColor("cyan");
		arr.getElement(4).getVisualizer().setColor("magenta");
		arr.getElement(5).getVisualizer().setColor("yellow");
		arr.getElement(6).getVisualizer().setColor("red");
		arr.getElement(7).getVisualizer().setColor("green");
		arr.getElement(8).getVisualizer().setColor("blue");
		arr.getElement(9).getVisualizer().setColor("black");

		// tell Bridges what datastructure to visualize
		bridges.setDataStructure(arr);

		// visualize the list
		bridges.visualize();
	}
}
