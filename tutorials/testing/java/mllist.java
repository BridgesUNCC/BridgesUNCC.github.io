import bridges.connect.Bridges;
import bridges.base.MLelement;

public class mllist {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		bridges.setTitle("A Multilist Example");
		bridges.setDescription("The large red node is the  beginning of list. Smaller red nodes spawn sublists, {2,5,{6, 10, 11},7}, {6, 10, 11} and {3,4}. Sublist origins are large green squares");
		// create  the list nodes

		MLelement<Integer> el0 = new MLelement<Integer>("0", 0);
		MLelement<Integer> el1 = new MLelement<Integer>("1", 1);
		MLelement<Integer> el2 = new MLelement<Integer>("2", 2);
		MLelement<Integer> el3 = new MLelement<Integer>("3", 3);
		MLelement<Integer> el4 = new MLelement<Integer>("4", 4);
		MLelement<Integer> el5 = new MLelement<Integer>("5", 5);
		MLelement<Integer> el6 = new MLelement<Integer>("6", 6);
		MLelement<Integer> el7 = new MLelement<Integer>("7", 7);
		MLelement<Integer> el8 = new MLelement<Integer>("8", 8);
		MLelement<Integer> el9 = new MLelement<Integer>("9", 9);
		MLelement<Integer> el10 = new MLelement<Integer>("10", 10);
		MLelement<Integer> el11 = new MLelement<Integer>("11", 11);
		// create the main list: 1, 2, 3, 4
		el0.setNext(el1);
		el1.setNext(el2);
		el2.setNext(el3);
		el3.setNext(el4);

		// create a sublist from 2 to 5, 6, 7
		el2.setSubList(el5);
		el5.setNext(el6);
		el6.setNext(el7);

		// create a second sublist from 6 to 10, 11
		el6.setSubList(el10);
		el10.setNext(el11);

		//create a third sublist from 3 to 8, 9
		el3.setSubList(el8);
		el8.setNext(el9);

		// some visual attributes
		el0.setSize (40);
		el0.setColor("red");

		// set sublist origins to be green and size 30
		el2.setColor("green");
		el3.setColor("green");
		el6.setColor("green");
		el3.setSize (30);
		el6.setSize (30);
		el2.setSize (30);

		el0.getLinkVisualizer(el1).setColor("red");
		el0.getLinkVisualizer(el1).setThickness(3);
		el1.getLinkVisualizer(el2).setColor("blue");
		el1.getLinkVisualizer(el2).setThickness(3);
		el2.getLinkVisualizer(el3).setThickness(3);


		//set visualizer type
		bridges.setDataStructure(el0);

		// visualize the list
		bridges.visualize();
	}
}
