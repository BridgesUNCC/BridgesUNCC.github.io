import bridges.connect.Bridges;
import bridges.base.BSTElement;

// Part 1 of this tutorial will illustrate the use of the BRIDGES in building
// binary search trees.  We will begin by constructing the tree manually and
// displaying it

public class tut_bst_p1 {
	public static void main(String[] args) throws Exception {


		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("A Simple  Binary Search Tree Example");

		// set description
		bridges.setDescription("This example illustrates a binary search tree built using BRIDGES");

		// we will create the tree manually in this example

		// create the nodes
		// the constructors sets the key and the node's label.
		// Labels may also be set by the setLabel() method of the object
		BSTElement<Integer, String> root = new BSTElement<Integer, String>(100, "Root");
		BSTElement<Integer, String> node1 = new BSTElement<Integer, String>(50, "Node1");
		BSTElement<Integer, String> node2 = new BSTElement<Integer, String>(200, "Node2");
		BSTElement<Integer, String> node3 = new BSTElement<Integer, String>(250, "Node3");
		BSTElement<Integer, String> node4 = new BSTElement<Integer, String>(75, "Node4");
		BSTElement<Integer, String> node5 = new BSTElement<Integer, String>(33, "Node4");

		// construct the tree
		root.setLeft(node1);
		root.setRight(node2);
		node2.setRight(node3);
		node1.setRight(node4);
		node1.setLeft(node5);


		// privide BRIDGES a handle to the root of the tree
		bridges.setDataStructure(root);

		// visualize the binary search tree
		// Hit the 'l' key to see the node labels
		bridges.visualize();
	}
}
