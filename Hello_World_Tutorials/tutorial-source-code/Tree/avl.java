import bridges.connect.Bridges;
import bridges.data_src_dependent.Tweet;
import bridges.base.AVLTreeElement;

public class avl {
    public static void main(String[] args) throws Exception{
        
                    //create the Bridges object
		Bridges bridges = new Bridges(11, "YOUR_API_KEY", "YOUR_USER_ID");

                    //create  an  AVL tree elements
		AVLTreeElement&lt;Integer,String&gt; avl_root = new AVLTreeElement&lt;Integer,String&gt;(50, 
													"Hello");
		AVLTreeElement&lt;Integer,String&gt; avl_2 = new AVLTreeElement&lt;Integer,String&gt;(30, "This");
		AVLTreeElement&lt;Integer,String&gt; avl_3 = new AVLTreeElement&lt;Integer,String&gt;(70, "is");
		AVLTreeElement&lt;Integer,String&gt; avl_4 = new AVLTreeElement&lt;Integer,String&gt;(20, "an");
		AVLTreeElement&lt;Integer,String&gt; avl_5 = new AVLTreeElement&lt;Integer,String&gt;(40, "AVL");
		AVLTreeElement&lt;Integer,String&gt; avl_6 = new AVLTreeElement&lt;Integer,String&gt;(90, "Tree");
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
