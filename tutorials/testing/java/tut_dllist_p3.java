import bridges.base.DLelement;
import bridges.connect.Bridges;
import java.util.Iterator;

// Part 3 of this tutorial illustrates iterators that can be used to
// traverse doubly linked lists
//
// We will continue to use the same list
//

public class tut_dllist_p3 {

	public static void main(String[] args) throws Exception {


		// create Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("A doubly Linked List Example");

		// set description
		bridges.setDescription("Illustrate the user of iterators with doubly linked lists");


		// create the nodes
		DLelement<String>  el0 = new DLelement<String> ("Gretel Chaney", "GretelChaney");
		DLelement<String>  el1 = new DLelement<String> ("Lamont Kyler", "Lamont Kyler");
		DLelement<String>  el2 = new DLelement<String> ("Gladys Serino", "Gladys Serino");
		DLelement<String>  el3 = new DLelement<String> ("Karol Soderman", "Karol Soderman");
		DLelement<String>  el4 = new DLelement<String> ("Starr McGinn", "Starr McGinn");

		// link elements, create the list
		el0.setNext(el1);
		el1.setPrev(el0);
		el1.setNext(el2);
		el2.setPrev(el1);
		el2.setNext(el3);
		el3.setPrev(el2);
		el3.setNext(el4);
		el4.setPrev(el3);


		// print the elements of the list -- using a regular for loop
		System.out.println("Printing list elements --  regular for loop:");
		for (DLelement<String> el = el0; el != null; el = el.getNext())
			System.out.println("\t " + el0.getLabel());


		// print the elements of the list -- using a forward iterator
		System.out.println("Printing list elements --  using forward iterator:");
		Iterator<String> iter = el0.iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// print the elements of the list -- using range loop
		System.out.println("Printing list elements --  using range loop:");
		for (String s : el0)
			System.out.println("\t " + s);

		// use the reverse iterator
		System.out.println("Printing list elements --  using reverse iterator:");
		iter = el4.reverse_iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// provide BRIDGES the head of the list
		bridges.setDataStructure(el0);

		// visualize
		bridges.visualize();
	}
}
