import bridges.base.DLelement;
import bridges.connect.Bridges;
import java.util.Iterator;

// This tutorial creates a number of BRIDGES doubly linked list elements,
// links them into a list and displays them

public class tut_dllist_p1 {

	public static void main(String[] args) throws Exception {


		// create Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("A doubly Linked List Example");

		// set description
		bridges.setDescription("Creat a 5 node doubly linked list and display them");


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

		// provide BRIDGES the head of the list
		bridges.setDataStructure(el0);

		// visualize
		bridges.visualize();
	}
}
