import bridges.connect.Bridges;
import bridges.base.TreeElement;

public class tree {
	public static void main(String[] args) throws Exception {


		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// title, description
		bridges.setTitle("A General Tree Example");
		bridges.setDescription("A basic tree with seven nodes. Three on one side and three on the other. The root node is set to red with 0.3 opacity. "
			+	"The other six nodes are neutral color.");

		//create  tree nodes
		TreeElement<String> t0 = new TreeElement<String>("Hello", "Hello");
		TreeElement<String> t2 = new TreeElement<String>("This", "This");
		TreeElement<String> t3 = new TreeElement<String>("is", "is");
		TreeElement<String> t4 = new TreeElement<String>("a", "a");
		TreeElement<String> t5 = new TreeElement<String>("generic", "generic");
		TreeElement<String> t6 = new TreeElement<String>("Tree", "Tree");
		TreeElement<String> t7 = new TreeElement<String>("Representation", "Representation");

		// add links to children
		t0.addChild(t2);
		t0.addChild(t3);
		t0.addChild(t4);
		t2.addChild(t5);
		t2.addChild(t6);
		t3.addChild(t7);

		// set some visual attributes
		t0.setColor("red");
		t0.setOpacity(0.3f);

		// link colors
		t0.getLinkVisualizer(t2).setColor("green");
		t0.getLinkVisualizer(t2).setThickness(2.0f);
		t0.getLinkVisualizer(t3).setColor("blue");
		t0.getLinkVisualizer(t3).setThickness(2.0f);
		t0.getLinkVisualizer(t4).setColor("orange");
		t0.getLinkVisualizer(t4).setThickness(2.0f);

		bridges.setTitle("A General Tree Example");

		// visualize the tree
		bridges.setDataStructure(t0);
		bridges.visualize();
	}
}
