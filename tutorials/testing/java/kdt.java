import bridges.connect.Bridges;
import bridges.base.KdTreeElement;
import java.util.List;

public class kdt {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		bridges.setTitle("A Kd Tree Example");
		bridges.setDescription("A three-level tree with partitioners cycling between X and Y."
			+ " The root node color is set to red while the leaf nodes that represent code letters are set to orange.");

		// create Kd Tree nodes
		KdTreeElement<Integer, String> t0 = new KdTreeElement<Integer, String>(50, 0);
		KdTreeElement<Integer, String> t1 = new KdTreeElement<Integer, String>(25, 1);
		KdTreeElement<Integer, String> t2 = new KdTreeElement<Integer, String>(75, 1);
		KdTreeElement<Integer, String> t3 = new KdTreeElement<Integer, String>(20, 0);
		KdTreeElement<Integer, String> t4 = new KdTreeElement<Integer, String>(30, 0);
		KdTreeElement<Integer, String> t5 = new KdTreeElement<Integer, String>(60, 0);
		KdTreeElement<Integer, String> t6 = new KdTreeElement<Integer, String>(80, 0);

		// create the tree;  a simple 3 level tree with partitioners cycling between X and Y
		t0.setLeft(t1);
		t0.setRight(t2);
		t1.setLeft(t3);
		t1.setLabel("X");
		t1.setRight(t4);
		t2.setLeft(t5);
		t2.setRight(t6);

		// set partitioning dimensions
		t0.setLabel("X");
		t1.setLabel("Y");
		t2.setLabel("Y");
		t3.setLabel("X");
		t4.setLabel("X");
		t5.setLabel("X");
		t6.setLabel("X");

		t0.setColor("red");

		// color the leaf nodes that represent the code letters
		t1.setColor("orange");
		t4.setColor("orange");
		t5.setColor("orange");
		t6.setColor("orange");

		// provide BRIDGES the  handle to the tree structure
		bridges.setDataStructure(t0);


		// visualize the tree
		bridges.visualize();
	}
}
