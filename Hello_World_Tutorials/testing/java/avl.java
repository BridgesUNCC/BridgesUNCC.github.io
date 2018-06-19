import bridges.connect.Bridges;
import bridges.data_src_dependent.Tweet;
import bridges.base.AVLTreeElement;

public class avl {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(11, "YOUR_USER_ID", "YOUR_API_KEY");

		//create  an  AVL tree elements
		AVLTreeElement<Integer, String> avl_root = new AVLTreeElement<Integer, String>(50,
			"Hello");
		AVLTreeElement<Integer, String> avl_2 = new AVLTreeElement<Integer, String>(30, "This");
		AVLTreeElement<Integer, String> avl_3 = new AVLTreeElement<Integer, String>(70, "is");
		AVLTreeElement<Integer, String> avl_4 = new AVLTreeElement<Integer, String>(20, "an");
		AVLTreeElement<Integer, String> avl_5 = new AVLTreeElement<Integer, String>(40, "AVL");
		AVLTreeElement<Integer, String> avl_6 = new AVLTreeElement<Integer, String>(90, "Tree");
		// put in the balance factors - done manually  here
		// for illustration, but in a real project, the user will
		// implement this as part of the insert/delete
		// operations on the tree to maintain a balanced tree
		avl_root.setLabel("0");
		avl_2.setLabel("0");
		avl_3.setLabel("-1");
		avl_4.setLabel("0");
		avl_5.setLabel("0");
		avl_6.setLabel("0");

		// add the links between nodes
		avl_root.setLeft(avl_2);
		avl_root.setRight(avl_3);
		avl_2.setLeft(avl_4);
		avl_2.setRight(avl_5);
		avl_3.setRight(avl_6);
		// set some attributes
		avl_root.getVisualizer().setColor("magenta");
		avl_root.getVisualizer().setOpacity(0.8f);

		//set visualizer type
		bridges.setDataStructure(avl_root);

		// visualize the list
		bridges.visualize();
	}
}
