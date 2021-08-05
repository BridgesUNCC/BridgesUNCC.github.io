import java.util.Iterator;

import bridges.connect.Bridges;
import bridges.base.Array1D;

// Part 3 of this tutorial describes use of iterators with BRIDGES Arrays

public class tut_array1d_p3 {
	public static void main(String[] args) throws Exception {

		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("One-Dimensional Array Example");

		// set description
		bridges.setDescription("Illustrating looping and iterators in 1D Arrays");

		//  set array dimensions, allocate array of elements
		int arraySize = 10;

		Array1D<Integer> arr = new Array1D<Integer> (arraySize);

		// populate the array, with squares of indices

		for (int k = 0; k < arr.getSize(); k++) {
			arr.getElement(k).setValue(k * k);

			// use the array values to label the elements
			arr.getElement(k).setLabel(String.valueOf(arr.getElement(k).getValue()));
		}

		System.out.println ("Printing values of array..");

		// using regular for loops
		System.out.println ("Using regular for loop..");
		for (int k = 0; k < 10; k++)
			System.out.println("\t" + arr.getElement(k).getValue());


		//use an iterator to print the values of the array

		System.out.println("Using an iterator..\n");
		Iterator<Integer> iter = arr.iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// using a for-each loop
		System.out.println("Using range loop:");
		for (int  s : arr)
			System.out.println("\t " + s);

		// tell Bridges the  datastructure to visualize
		bridges.setDataStructure(arr);

		// visualize the list
		bridges.visualize();
	}
}
