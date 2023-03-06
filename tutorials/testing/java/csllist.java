import bridges.base.CircSLelement;
import bridges.connect.Bridges;

import java.util.Iterator;

public class csllist {

	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// title, description
		bridges.setTitle("A Circle Singly Linked List Example");

		// set  description
		bridges.setDescription("A circular singly linked list of node with student names, where each node is linked only to the next node in the list and the last node is linked to the first.  Illustrates Node and link coloring, node size, link thickness and opacity");

		// create the linked list elements with student names
		CircSLelement<String>  el0 = new CircSLelement<String> ("Gretel Chaney", "Gretel Chaney");
		CircSLelement<String>  el1 = new CircSLelement<String> ("Lamont Kyler", "Lamont Kyler");
		CircSLelement<String>  el2 = new CircSLelement<String> ("Gladys Serino", "Gladys Serino");
		CircSLelement<String>  el3 = new CircSLelement<String> ("Karol Soderman", "Karol Soderman");
		CircSLelement<String>  el4 = new CircSLelement<String> ("Starr McGinn", "Starr McGinn");

		//  link the elements
		el0.setNext(el1);
		el1.setNext(el2);
		el2.setNext(el3);
		el3.setNext(el4);

		// link the last to the first
		el4.setNext(el0);

        // use the iterator
        System.out.println("Using iterators..");
        Iterator<String> iter = el0.iterator();
		do {
            System.out.println("\t" + iter.next());
		} while (iter.hasNext());

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
