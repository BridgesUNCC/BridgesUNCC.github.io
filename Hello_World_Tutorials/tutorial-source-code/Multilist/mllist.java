import bridges.connect.Bridges;
import bridges.base.MLelement;

public class mllist {
	public static void main(String[] args) throws Exception{
    	
    								//create the Bridges object
		Bridges bridges = new Bridges(7, "YOUR_API_KEY", "YOUR_USER_ID");
        
		bridges.setTitle("A Multilist Example");

   							//create  nodes for the main list

		MLelement&lt;String&gt; el0 = new MLelement&lt;String&gt;(0", "0");
		MLelement&lt;String&gt; el1 = new MLelement&lt;String&gt;(1", "1");
		MLelement&lt;String&gt; el2 = new MLelement&lt;String&gt;(2", "2");
		MLelement&lt;String&gt; el3 = new MLelement&lt;String&gt;(3", "3");
		MLelement&lt;String&gt; el4 = new MLelement&lt;String&gt;(4", "4");

							// link them
		el0.setNext(el1);
		el1.setNext(el2);
		el2.setNext(el3);
		el3.setNext(el4);
							// create a sublist from node 2
		MLelement&lt;String&gt; el5 = new MLelement&lt;String&gt;(5", "5");
		MLelement&lt;String&gt; el6 = new MLelement&lt;String&gt;(6", "6");
		MLelement&lt;String&gt; el7 = new MLelement&lt;String&gt;(7", "7");

							// link the sublist
		el5.setNext(el6);
		el6.setNext(el7);
		el2.setSubList(el5);

							// create a second sublist from 3
		MLelement&lt;String&gt; el8 = new MLelement&lt;String&gt;(8", "8");
		MLelement&lt;String&gt; el9 = new MLelement&lt;String&gt;(9", "9");

							// link the sublist
		el8.setNext(el9);
		el3.setSubList(el8);

							// create a (sub)sublist from 5
		MLelement&lt;String&gt; el10 = new MLelement&lt;String&gt;(10", "10");
		MLelement&lt;String&gt; el11 = new MLelement&lt;String&gt;(11", "11");

							// link the sublist
		el10.setNext(el11);
		el6.setSubList(el10);

							// set visual attributes
		el0.getVisualizer().setSize (40);
		el0.getLinkVisualizer(el1).setColor("red");
		el0.getLinkVisualizer(el1).setThickness(3);
		el1.getLinkVisualizer(el2).setColor("blue");
		el1.getLinkVisualizer(el2).setThickness(3);
		el2.getLinkVisualizer(el3).setColor("cyan");
		el2.getLinkVisualizer(el3).setThickness(3);

		el0.getVisualizer().setColor("red");
             						//set visualizer type
		bridges.setDataStructure(el0);
        							// visualize the multilist
		bridges.visualize();
    }
}

