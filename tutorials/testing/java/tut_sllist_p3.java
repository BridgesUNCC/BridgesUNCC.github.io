import bridges.connect.Bridges;
import bridges.base.SLelement;
import java.util.Iterator;

//
// In part 3 of this tutorial we demonstrate more advanced features such as
// using iterators to traverse lists, which are more convenient than working
// with the underlying element objects. To keep the tutorial simple, we will ignore
// styling (that was illustrated in part 2).
//
// Reference Classes: SLelement, Bridges
//


public class tut_sllist_p3 {

	public static void main(String[] args) throws Exception {

		// Create Bridges object,  fill in credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("A Single Linked List Example");

		// set  description
		bridges.setDescription("Demonstrate advanced features, looping, iterators");

		// create the linked list elements with student names
		SLelement<String>  st0 = new SLelement<String> ("Gretel Chaney");
		SLelement<String>  st1 = new SLelement<String> ("Lamont Kyler");
		SLelement<String>  st2 = new SLelement<String> ("Gladys Serino");
		SLelement<String>  st3 = new SLelement<String> ("Karol Soderman");
		SLelement<String>  st4 = new SLelement<String> ("Starr McGinn");

		//  link the elements
		st0.setNext(st1);
		st1.setNext(st2);
		st2.setNext(st3);
		st3.setNext(st4);

		// we want to see these names in the visualization so we will set them as
		// the nodes' labels. We will retrieve the nodes' generic data for the label
		st0.setLabel(st0.getValue());
		st1.setLabel(st1.getValue());
		st2.setLabel(st2.getValue());
		st3.setLabel(st3.getValue());
		st4.setLabel(st4.getValue());

		// print the names of the students in the list using iteration

		// Using a regular for loop on BRIDGES elements
		System.out.println("Using a regular for loop..");
		for (SLelement<String> el = st0; el != null; el = el.getNext())
			System.out.println("\t" +  el.getValue());

		// using a forward iterator
		System.out.println("Using a forward iterator..\n");
		Iterator<String> iter = st0.iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// using a for-each loop
		System.out.println("Using range loop:");
		for (String s : st0)
			System.out.println("\t " + s);

		// tell Bridges the head of the list
		bridges.setDataStructure(st0);

		// visualize the linked list (hit the key 'l' on the visualzation to see all labels
		bridges.visualize();
	}
}
