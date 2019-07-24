import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.base.BSTElement;
import bridges.data_src_dependent.EarthquakeUSGS;
import bridges.data_src_dependent.Tweet;
import bridges.data_src_dependent.USGSaccount;
import java.util.List;

public class bst_eq {
	public static void main(String[] args) throws Exception {

		if (args.length < 2)
			throw new IllegalArgumentException("Need to provide user ID and API key as command-line arguments!");

		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");

		// Retrieve a list of 10 earthquake  records  from USGS using the BRIDGES API
		DataSource ds = bridges.getDataSource();
		List<EarthquakeUSGS> eqlist = ds.getEarthquakeUSGSData(10);

		// create BST nodes and insert into a tree
		BSTElement<Double, EarthquakeUSGS> root = null;
		for (int k = 0; k < 10; k++) {
			BSTElement<Double, EarthquakeUSGS> bst_node =
				new BSTElement<Double, EarthquakeUSGS>(eqlist.get(k).getMagnitude(), eqlist.get(k));
			// set label of the node
			bst_node.setLabel(eqlist.get(k).getTitle() + "\n\nLat/Long: ( " +
				eqlist.get(k).getLatit() + "," + eqlist.get(k).getLongit() + " )\n\n" +
				eqlist.get(k).getTime());
			root = insert_R (root, bst_node);
		}


		// set some visual attributes
		root.setColor("red");

		//set visualizer type
		bridges.setDataStructure(root);
		// visualize the tree
		bridges.visualize();
	}
	// recursive insert method to insert nodes into a binary search tree
	public static BSTElement<Double, EarthquakeUSGS> insert_R (BSTElement<Double, EarthquakeUSGS> rt,
		BSTElement<Double, EarthquakeUSGS> new_el) {
		if (rt == null)
			return new_el;
		else if (new_el.getKey() < rt.getKey())
			rt.setLeft(insert_R(rt.getLeft(), new_el));
		else
			rt.setRight(insert_R(rt.getRight(), new_el));
		return rt;
	}
}
