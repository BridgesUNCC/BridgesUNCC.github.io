
import bridges.connect.Bridges;
import bridges.base.BinTreeElement;


public class bintree{
	public static void main(String[] args) throws Exception{
    	
   					//create the Bridges object
//		Bridges<Integer, Integer> bridges = new Bridges<Integer, Integer>(8,
//								"YOUR_API_KEY", "YOUR_USER_ID");
		Bridges<Integer, Integer> bridges = new Bridges<Integer, Integer>(8,
								"997924677918", "bridges_public");

		bridges.setTitle("A Huffman Coding Tree Example");
		bridges.setDescription("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2");
   					//create  an   tree
		BinTreeElement<Integer> t0 = 
			new BinTreeElement<Integer>("306", 0);
		BinTreeElement<Integer> t1 = 
			new BinTreeElement<Integer>("120\\nE", 1);
		BinTreeElement<Integer> t2 = 
			new BinTreeElement<Integer>("186", 2);
		BinTreeElement<Integer> t3 = 
			new BinTreeElement<Integer>("79", 3);
		BinTreeElement<Integer> t4 = 
			new BinTreeElement<Integer>("37\\nU", 4);
		BinTreeElement<Integer> t5 = 
			new BinTreeElement<Integer>("42\\nD", 5);
		BinTreeElement<Integer> t6 = 
			new BinTreeElement<Integer>("42\\nL", 6);
		BinTreeElement<Integer> t7 = 
			new BinTreeElement<Integer>("107", 7);
		BinTreeElement<Integer> t8 = 
			new BinTreeElement<Integer>("65", 8);
		BinTreeElement<Integer> t9 = 
			new BinTreeElement<Integer>("32\\nC", 9);
		BinTreeElement<Integer> t10 = 
			new BinTreeElement<Integer>("33", 10);
		BinTreeElement<Integer> t11 = 
			new BinTreeElement<Integer>("9", 11);
		BinTreeElement<Integer> t12 = 
			new BinTreeElement<Integer>("2\\nZ", 12);
		BinTreeElement<Integer> t13 = 
			new BinTreeElement<Integer>("7\\nK", 13);
		BinTreeElement<Integer> t14 = 
			new BinTreeElement<Integer>("24\\nM", 14);

					// put in the balance factors - done manually  here 
					// for illustration, but in a real project, the user will
					// implement this as part of the insert/delete
					// operations on the tree to maintain a balanced tree
		t0.setLeft(t1);
		t0.setRight(t2);
		t2.setLeft(t3);
		t2.setRight(t7);
		t3.setLeft(t4);
		t3.setRight(t5);
		t7.setLeft(t6);
		t7.setRight(t8);
		t8.setLeft(t9);
		t8.setRight(t10);
		t10.setLeft(t11);
		t10.setRight(t14);
		t11.setLeft(t12);
		t11.setRight(t13);
									// set some visual attributes
		t0.getVisualizer().setColor("red");
									// color the leaf nodes that represent the code letters
		t1.getVisualizer().setColor("orange");
		t4.getVisualizer().setColor("orange");
		t5.getVisualizer().setColor("orange");
		t6.getVisualizer().setColor("orange");
		t9.getVisualizer().setColor("orange");
		t12.getVisualizer().setColor("orange");
		t13.getVisualizer().setColor("orange");
		t14.getVisualizer().setColor("orange");

                                  //Print the JSON to console
//		bridges.getVisualizer().setVisualizeJSON(true);
             					//set visualizer type
		bridges.setDataStructure(t0);
        						// visualize the tree
		bridges.visualize();
    }
}
