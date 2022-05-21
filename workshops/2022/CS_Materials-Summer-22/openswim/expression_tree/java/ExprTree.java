import bridges.connect.Bridges;
import bridges.base.TreeElement;

public class ExprTree {
	public static void main(String[] args) throws Exception {


		//create the Bridges object
		Bridges bridges = new Bridges(1, "YOUR_USER_ID", "YOUR_API_KEY");
		// title, description
		bridges.setTitle("An Expression Tree Example Using TreeElements");
		bridges.setDescription("A manually constructed expression tree for sqrt(Ax^2 + By + c");

		//TODO:  Create tree elements for each element of the above expression.
		// Refer to the document for TreeElement using its constructor to create
		// each element (refer to the TreeElement BRIDGES tutorial for more 
		// information

		// TODO: Tree elements can have visual attributes: color, opacity, shape
		// for the nodes and thickness, color for the links
		// Useful Links: 
		// 		http://bridgesuncc.github.io/tutorials/Tree.html
		//		http://bridgesuncc.github.io/doc/java-api/current/html/classbridges_1_1base_1_1_tree_element.html

		// 		Increase the size of the root node, colors of operator nodes, 
		//      thickness of links.


		// provide BRIDGES the  handle to the tree structure
		// you will provide the root of the tree to the following function

		// bridges.setDataStructure(root);
		// bridges.visualize();
	}
}
