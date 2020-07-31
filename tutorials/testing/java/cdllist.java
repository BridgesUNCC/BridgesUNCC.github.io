import bridges.base.CircDLelement;
import bridges.connect.Bridges;
import java.util.Iterator;

public class cdllist {

	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		bridges.setTitle("A Circular Doubly Linked List Example");


		// create the linked list elements with student names
		CircDLelement<String>  el0 = new CircDLelement<String> ("Gretel Chaney", "Gretel Chaney");
		CircDLelement<String>  el1 = new CircDLelement<String> ("Lamont Kyler", "Lamont Kyler");
		CircDLelement<String>  el2 = new CircDLelement<String> ("Gladys Serino", "Gladys Serino");
		CircDLelement<String>  el3 = new CircDLelement<String> ("Karol Soderman", "Karol Soderman");
		CircDLelement<String>  el4 = new CircDLelement<String> ("Starr McGinn", "Starr McGinn");

		//  link the elements
		el0.setNext(el1);
		el1.setPrev(el0);
		el1.setNext(el2);
		el2.setPrev(el1);
		el2.setNext(el3);
		el3.setPrev(el2);
		el3.setNext(el4);
		el4.setPrev(el3);

		// link the last element to the first
		el4.setNext (el0);
		el0.setPrev (el4);

		// test CurcDLelement iterators


        System.out.println("Using foreach range loop.");
        Iterator<String> iter = el0.iterator();
		for (String s : el0)
            System.out.println("\t" + iter.next());

        // use the iterator
        System.out.println("Using iterators..");
		iter = el0.iterator();
		while (iter.hasNext())
            System.out.println("\t" + iter.next());
		// test reverse iterator
		System.out.println("Using reverse iterator..");
        iter = el0.reverse_iterator();
		while (iter.hasNext())
            System.out.println("\t" + iter.next());


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
