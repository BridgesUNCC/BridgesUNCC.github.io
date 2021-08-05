import bridges.connect.Bridges;
import bridges.base.BSTElement;

// Part 2 of this tutorial will illustrate the use of the BRIDGES in styling
// nodes and links of binary search trees.  For instance you might want to
// illustrate the nodes and links that were visited during an insertion
// operation. Or color the tree based on a particular type of traversal.

// We will use the same tree as in Part 1 and illustrate styling.

public class tut_bst_p2 {
	public static void main(String[] args) throws Exception {


		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("A Simple  Binary Search Tree Example");

		// set description
		bridges.setDescription ("This tutorial illustrates styling options for binary search elements and links");

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

		// style the nodes and links. Nodes have properties of label shape, size,
		// color and opacity. Links have properties of a label, color and thickness

		// we will demonstrate the path leading to the largest and smallest keys
		// with styling options in BRIDGES

		root.setColor("red");
		root.setSize (40);

		// path to largest key
		node2.setShape("square");
		node3.setShape("square");
		node2.setColor("magenta");
		node3.setColor("magenta");

		//style link from root to node2
		root.getLinkVisualizer(node2).setThickness(3.0f);
		root.getLinkVisualizer(node2).setColor("orange");

		//style link from node2 to node3
		node2.getLinkVisualizer(node3).setThickness(3.0f);
		node2.getLinkVisualizer(node3).setColor("orange");

		// path to smallest key
		node1.setShape("triangle");
		node5.setShape("triangle");
		node5.setColor("cyan");
		node5.setColor("cyan");

		//style link from root to node2
		root.getLinkVisualizer(node1).setThickness(2.0f);
		root.getLinkVisualizer(node1).setColor("purple");

		//style link from node2 to node3
		node1.getLinkVisualizer(node5).setThickness(2.0f);
		node1.getLinkVisualizer(node5).setColor("purple");

		//deemphasize node 4, make it a bit transparent
		node4.setOpacity(0.2f);


		// privide BRIDGES a handle to the root of the tree
		bridges.setDataStructure(root);

		// visualize the binary search tree
		// Hit the 'l' key to see the node labels
		bridges.visualize();
	}
}
