import bridges.connect.Bridges;
import bridges.base.BSTElement;

// Part 3 of this tutorial will illustrate traversing a binary search tree
// to find a specific key value and mark it as well as style the path to it
// illustrate the paths

public class tut_bst_p3 {
	public static void main(String[] args) throws Exception {


		//create the Bridges object, set credentials
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// set title
		bridges.setTitle("A Simple  Binary Search Tree Example");

		// set description
		bridges.setDescription("This example illustrates finding a key in a constructed binary search tree and styling the visited nodes and links");

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


		// traverse the tree to the largest node and style them to find
		// key value 75
		BSTElement<Integer, String> r  = root, left, right;
		Boolean found = false;
		int search_key = 75;
		while (!found && r != null) {
			// style the node
			r.setColor("red");
			r.setShape("square");
			r.setShape("square");
			r.setSize(20);

			int key = r.getKey();
			if (key == search_key) { 	// found it
				found = true;
				r.setColor("orange");
				r.setSize(49);
				System.out.println("Yay! Found the key!\n");
			}
			else if (search_key < key) { // go left
				left = r.getLeft();
				if (left != null) {  // style link
					r.getLinkVisualizer(left).setColor("cyan");
					r.getLinkVisualizer(left).setThickness(5.0f);
				}
				r = left;
			}
			else {
				right = r.getRight();
				if (right != null) { // style link
					r.getLinkVisualizer(right).setColor("cyan");
					r.getLinkVisualizer(right).setThickness(5.0f);
				}
				r = right;
			}
		}

		// privide BRIDGES a handle to the root of the tree
		bridges.setDataStructure(root);

		// visualize the binary search tree
		// Hit the 'l' key to see the node labels
		bridges.visualize();

	}
}

