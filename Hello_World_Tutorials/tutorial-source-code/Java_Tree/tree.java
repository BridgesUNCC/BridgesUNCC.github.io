
import bridges.connect.Bridges;
import bridges.base.TreeElement;


public class tree{
	public static void main(String[] args) throws Exception{
    	
   					//create the Bridges object
		Bridges bridges = new Bridges<Integer, String>(11, "YOUR_API_KEY", "YOUR_USER_ID");

		bridges.setTitle("A Generalized Tree Example");

   					//create   tree nodes
		TreeElement<String> t0 = new TreeElement<String>("Hello");
		TreeElement<String> t2 = new TreeElement<String>("This");
		TreeElement<String> t3 = new TreeElement<String>("is");
		TreeElement<String> t4 = new TreeElement<String>("a");
		TreeElement<String> t5 = new TreeElement<String>("generic");
		TreeElement<String> t6 = new TreeElement<String>("Tree");
		TreeElement<String> t7 = new TreeElement<String>("Representation");

					// put in labels for each node; we simply use integers 

		t0.setLabel("10");
		t2.setLabel("20");
		t3.setLabel("30");
		t4.setLabel("40");
		t5.setLabel("50");
		t6.setLabel("60");
		t7.setLabel("100");

					// add links to children

		t0.addChild(t2);
		t0.addChild(t3);
		t0.addChild(t7);
		t2.addChild(t4);
		t2.addChild(t5);
		t3.addChild(t6);

									// set some visual attributes
		t0.getVisualizer().setColor("red");
		t0.getVisualizer().setOpacity(0.3f);

		bridges.setTitle("A General Tree Example");
             					//set visualizer type
		bridges.setDataStructure(t0);
        						// visualize the tree
		bridges.visualize();
    }
}
