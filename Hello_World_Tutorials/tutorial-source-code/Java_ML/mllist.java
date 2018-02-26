
import bridges.connect.Bridges;
import bridges.base.MLelement;

public class mllist {
	public static void main(String[] args) throws Exception{
    	
    								//create the Bridges object
		Bridges<String, String> bridges = new Bridges<String,String>(13, 
								"997924677918", "bridges_public");
        
		bridges.setTitle("A Multilist Example");

   							//create  nodes for the main list

		MLelement<String> el0 = new MLelement<String>("0", "0");
		MLelement<String> el1 = new MLelement<String>("1", "1");
		MLelement<String> el2 = new MLelement<String>("2", "2");
		MLelement<String> el3 = new MLelement<String>("3", "3");
		MLelement<String> el4 = new MLelement<String>("4", "4");

							// link them
		el0.setNext(el1);
		el1.setNext(el2);
		el2.setNext(el3);
		el3.setNext(el4);
							// create a sublist from node 2
		MLelement<String> el5 = new MLelement<String>("5", "5");
		MLelement<String> el6 = new MLelement<String>("6", "6");
		MLelement<String> el7 = new MLelement<String>("7", "7");

							// link the sublist
		el5.setNext(el6);
		el6.setNext(el7);
		el2.setSubList(el5);

							// create a second sublist from 3
		MLelement<String> el8 = new MLelement<String>("8", "8");
		MLelement<String> el9 = new MLelement<String>("9", "9");

							// link the sublist
		el8.setNext(el9);
		el3.setSubList(el8);

							// create a (sub)sublist from 5
		MLelement<String> el10 = new MLelement<String>("10", "10");
		MLelement<String> el11 = new MLelement<String>("11", "11");

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
