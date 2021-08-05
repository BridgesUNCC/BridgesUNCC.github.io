import bridges.base.DLelement;
import bridges.connect.Bridges;
import java.util.Iterator;

// Part 2 of the tutorial illustrates styling features in a doubly linked list
// Uses the same list as part 1

public class tut_dllist_p2 {

	public static void main(String[] args) throws Exception {


		// create Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("A doubly Linked List Example");

		// set description
		bridges.setDescription("Illustrates styling features in a doubly linked list");


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

		// style the nodes and links in the list

		// color the elements
		el0.setColor("red");
		el1.setColor("green");
		el2.setColor("blue");
		el3.setColor("cyan");
		el4.setColor("yellow");

		// element size
		el0.setSize(40);
		el1.setSize(40);

		// element opacity
		el1.setOpacity(0.2f);
		el3.setOpacity(0.2f);

		// shape
		el2.setShape("triangle");
		el3.setShape("square");

		// thickness
		el3.getLinkVisualizer(el4).setThickness(6.0f);
		el4.getLinkVisualizer(el3).setThickness(6.0f);

		// link color
		el3.getLinkVisualizer(el4).setColor("orange");
		el4.getLinkVisualizer(el3).setColor("orange");

		// link label
		el0.getLinkVisualizer(el1).setLabel("Chaney-->Kyler");
		el1.getLinkVisualizer(el0).setLabel("Kyler-->Chaney");

		// provide BRIDGES the head of the list
		bridges.setDataStructure(el0);

		// visualize
		bridges.visualize();
	}
}
