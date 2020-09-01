import bridges.base.DLelement;
import bridges.base.Color;
import bridges.connect.Bridges;

public class vis_example {

	public static void main(String[] args) throws Exception {


		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// set title
		bridges.setTitle("A Visualization Attributes Related Example Using Doubly Linked List");

		// create some elements
		DLelement<String>  el0 = new DLelement<String> ("element0", "Element 1");
		DLelement<String>  el1 = new DLelement<String> ("element1", "Element 1");

		// create the list
		el0.setNext(el1);
		el1.setPrev(el0);

		// node properties

		// set color, size , shape for list elements - see the Color class
		//for supported colors
		el0.setColor("red");
		el0.setSize(20.);
		el1.setShape("diamond");

		// set node transparency
		el0.setOpacity (0.3f);

		// color the links - must specify a valid terminating element
		// color the link from el0 to el1
		el0.getLinkVisualizer(el1).setColor("green");

		// color the link from el1 to el0, using rgb color
		el1.getLinkVisualizer(el0).setColor(new Color(255, 0, 255));

		// adjust link thickness
		el0.getLinkVisualizer(el1).setThickness(2.0f);
		el1.getLinkVisualizer(el0).setThickness(4.0f);

		// set link label
		el0.getLinkVisualizer(el1).setLabel("Link Label");

		bridges.setDataStructure(el0);
		bridges.visualize();
	}
}
