import bridges.base.DLelement;
import bridges.connect.Bridges;
import java.util.Iterator;

public class dllist {

	public static void main(String[] args) throws Exception {


		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("A doubly Linked List Example");

		// set description
		bridges.setDescription("This list has five nodes all linked to the nodes before and after them and illustrates visual attributes. ");


		// create some elements
		DLelement<String>  el0 = new DLelement<String> ("Gretel Chaney", "Gretel Chaney");
		DLelement<String>  el1 = new DLelement<String> ("Lamont Kyler", "Lamont Kyler");
		DLelement<String>  el2 = new DLelement<String> ("Gladys Serino", "Gladys Serino");
		DLelement<String>  el3 = new DLelement<String> ("Karol Soderman", "Karol Soderman");
		DLelement<String>  el4 = new DLelement<String> ("Starr McGinn", "Starr McGinn");

		// create the list
		el0.setNext(el1);
		el1.setPrev(el0);
		el1.setNext(el2);
		el2.setPrev(el1);
		el2.setNext(el3);
		el3.setPrev(el2);
		el3.setNext(el4);
		el4.setPrev(el3);

		// test SLelement iterators

		// using a for-each loop
		System.out.println("Using range for loop:");
		for (String s : el0)
			System.out.println("\t " + s);

		// use the forward iterator
		System.out.println("Using forward iterators..");
		Iterator<String> iter = el0.iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// use the reverse iterator
		System.out.println("Using reverse iterator..");
		iter = el4.reverse_iterator();
		while (iter.hasNext()) {
			System.out.println("\t" + iter.next());
		}

		// add  element colors
		// set colors for list elements - see the Color class for supported colors
		el0.setColor("red");
		el2.setColor("aliceblue");

		// color the links - must specify a valid terminating element
		el0.getLinkVisualizer(el1).setColor("green");
		// color the reverse link
		el1.getLinkVisualizer(el0).setColor("magenta");

		// adjust link thickness
		el3.getLinkVisualizer(el4).setThickness(3.0f);
		el4.getLinkVisualizer(el3).setThickness(6.0f);

		// set link label
		el2.getLinkVisualizer(el3).setLabel("Link Label");

		// set node transparency
		el4.setOpacity (0.5f);

		// set node size
		el0.setSize (20);

		bridges.setDataStructure(el0);
		bridges.visualize();
	}
}
