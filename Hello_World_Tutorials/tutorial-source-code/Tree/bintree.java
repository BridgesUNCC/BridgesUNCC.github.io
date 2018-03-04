import bridges.connect.Bridges;
import bridges.base.BinTreeElement;


public class bintree {
	public static void main(String[] args) throws Exception{
    	
   					//create the Bridges object
		Bridges bridges = new Bridges(9, "YOUR_API_KEY", "YOUR_USER_ID");

		bridges.setTitle("A Huffman Coding Tree Example");
		bridges.setDescription("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2");

   					//create  an   tree
		BinTreeElement&lt;Integer&gt; t0 = new BinTreeElement&lt;Integer&gt;("306", 0);
		BinTreeElement&lt;Integer&gt; t1 = new BinTreeElement&lt;Integer&gt;("120\\nE", 1);
		BinTreeElement&lt;Integer&gt; t2 = new BinTreeElement&lt;Integer&gt;("186", 2);
		BinTreeElement&lt;Integer&gt; t3 = new BinTreeElement&lt;Integer&gt;("79", 3);
		BinTreeElement&lt;Integer&gt; t4 = new BinTreeElement&lt;Integer&gt;("37\\nU", 4);
		BinTreeElement&lt;Integer&gt; t5 = new BinTreeElement&lt;Integer&gt;("42\\nD", 5);
		BinTreeElement&lt;Integer&gt; t6 = new BinTreeElement&lt;Integer&gt;("42\\nL", 6);
		BinTreeElement&lt;Integer&gt; t7 = new BinTreeElement&lt;Integer&gt;("107", 7);
		BinTreeElement&lt;Integer&gt; t8 = new BinTreeElement&lt;Integer&gt;("65", 8);
		BinTreeElement&lt;Integer&gt; t9 = new BinTreeElement&lt;Integer&gt;("32\\nC", 9);
		BinTreeElement&lt;Integer&gt; t10 = new BinTreeElement&lt;Integer&gt;("33", 10);
		BinTreeElement&lt;Integer&gt; t11 = new BinTreeElement&lt;Integer&gt;("9", 11);
		BinTreeElement&lt;Integer&gt; t12 = new BinTreeElement&lt;Integer&gt;("2\\nZ", 12);
		BinTreeElement&lt;Integer&gt; t13 = new BinTreeElement&lt;Integer&gt;("7\\nK", 13);
		BinTreeElement&lt;Integer&gt; t14 = new BinTreeElement&lt;Integer&gt;("24\\nM", 14);

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
		
             					//set visualizer type
		bridges.setDataStructure(t0);
        						// visualize the tree
		bridges.visualize();
    }
}
