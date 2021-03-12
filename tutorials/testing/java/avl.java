import bridges.connect.Bridges;
import bridges.base.AVLTreeElement;

public class avl {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// title, description
		bridges.setTitle("AVL Tree Example");
		bridges.setDescription("This AVL tree has six elements.  The root is magenta color and has three nodes on its left and two nodes on its right. The values from lower left to the root, 20, 40, 30, 50. And from lower right to root, 90, 70, 50. Hit the 'l' key to see the balance factors displayed at the nodes.");

		//create  an  AVL tree elements
		AVLTreeElement<Integer, String> avl_root = new AVLTreeElement<Integer, String>(50, "Hello");
		AVLTreeElement<Integer, String> avl2 = new AVLTreeElement<Integer, String>(30, "This");
		AVLTreeElement<Integer, String> avl3 = new AVLTreeElement<Integer, String>(70, "is");
		AVLTreeElement<Integer, String> avl4 = new AVLTreeElement<Integer, String>(20, "an");
		AVLTreeElement<Integer, String> avl5 = new AVLTreeElement<Integer, String>(40, "AVL");
		AVLTreeElement<Integer, String> avl6 = new AVLTreeElement<Integer, String>(90, "Tree");

		// put in the balance factors - done manually  here
		// for illustration, but in a real project, the user will
		// implement this as part of the insert/delete
		// operations on the tree to maintain a balanced tree

		avl_root.setBalanceFactor (0);
		avl2.setBalanceFactor (0);
		avl3.setBalanceFactor (1);
		avl4.setBalanceFactor (0);
		avl5.setBalanceFactor (0);
		avl6.setBalanceFactor (0);

		avl_root.setLabel(String.valueOf(avl_root.getBalanceFactor()));
		avl2.setLabel(String.valueOf(avl2.getBalanceFactor()));
		avl3.setLabel(String.valueOf(avl3.getBalanceFactor()));
		avl4.setLabel(String.valueOf(avl4.getBalanceFactor()));
		avl5.setLabel(String.valueOf(avl5.getBalanceFactor()));
		avl6.setLabel(String.valueOf(avl6.getBalanceFactor()));

		// add the links between nodes
		avl_root.setLeft(avl2);
		avl_root.setRight(avl3);
		avl2.setLeft(avl4);
		avl2.setRight(avl5);
		avl3.setRight(avl6);

		// set some attributes
		avl_root.setColor("magenta");
		avl_root.getLinkVisualizer(avl2).setColor("cyan");
		avl_root.getLinkVisualizer(avl3).setColor("blue");

		//set visualizer type
		bridges.setDataStructure(avl_root);

		// visualize the list
		bridges.visualize();
	}
}
