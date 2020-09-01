/**
 * Created by Lucas Estrella on 1/31/2017.
 * lestrell@uncc.edu
 */
import bridges.connect.Bridges;
import bridges.base.SLelement;
import java.util.Iterator;

public class sllist {

	public static void main(String[] args) throws Exception {

		// note: you must fill in with your Bridges credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("A Single Linked List Example");

		// set  description
		bridges.setDescription("A singly linked list of node with student names, where each node is linked only to the next node in the list. Illustrates Node and link coloring, node size, link thickness and opacity");

		// create the linked list elements with student names
		SLelement<String>  el0 = new SLelement<String> ("Gretel Chaney", "Gretel Chaney");
		SLelement<String>  el1 = new SLelement<String> ("Lamont Kyler", "Lamont Kyler");
		SLelement<String>  el2 = new SLelement<String> ("Gladys Serino", "Gladys Serino");
		SLelement<String>  el3 = new SLelement<String> ("Karol Soderman", "Karol Soderman");
		SLelement<String>  el4 = new SLelement<String> ("Starr McGinn", "Starr McGinn");

		//  link the elements
		el0.setNext(el1);
		el1.setNext(el2);
		el2.setNext(el3);
		el3.setNext(el4);

		// test SLelement iterators

		// using a for-each loop
		System.out.println("Using range for loop:");
		for (String s : el0)
			System.out.println("\t " + s);

		// use the iterator
		System.out.println("Using iterators..");
		Iterator<String> iter = el0.iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// set colors for list elements - see the Color class for supported colors
		el0.setColor("red");
		el2.setColor("aliceblue");

		// color the links - must specify a valid terminating element
		el0.getLinkVisualizer(el1).setColor("green");
		el3.getLinkVisualizer(el4).setColor("magenta");

		// adjust link thickness
		el0.getLinkVisualizer(el1).setThickness(2.0f);

		// set node transparency
		el4.setOpacity (0.5f);

		// set node size
		el0.setSize (20);

		// set link label
		el2.getLinkVisualizer(el3).setLabel("Gladys_to_Karol");

		bridges.setDataStructure(el0);
		bridges.visualize();
	}
}
