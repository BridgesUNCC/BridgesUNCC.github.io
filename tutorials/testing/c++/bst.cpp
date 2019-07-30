
#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;
using namespace bridges::dataset;

BSTElement<float, EarthquakeUSGS> *insert (BSTElement<float, EarthquakeUSGS> *rt,
	BSTElement<float, EarthquakeUSGS> *new_el);

int max_quakes = 25;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// set title, description
	bridges.setTitle("A Binary Search Tree Example with Earthquake Data");
	bridges.setDescription("10 sets of earthquake are gathered and sorted with nodes whos magnitude is greater than the parent is set to the right and nodes with a magnitude less than the parent set to the left. The root is set to red the leaf nodes are neutral.");

	// get earthquake data
	DataSource *ds = new DataSource;
	vector<EarthquakeUSGS> eq_list = ds->getEarthquakeUSGSData(max_quakes);

	// create the binary tree root
	BSTElement<float, EarthquakeUSGS> *root = nullptr;

	// insert quake records into the tree
	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		BSTElement<float, EarthquakeUSGS>
		*bst_node = new BSTElement<float, EarthquakeUSGS>(eq.getMagnitude(), eq);
		bst_node->setLabel(eq.getTitle() + "\nLat/Long: ( " +
			to_string(eq.getLatit()) + "," + to_string(eq.getLongit()) + " )\n" +
			eq.getDateStr());
		root = insert (root, bst_node);
		root->setColor("red");
	}

	// visualize the binary search tree
	bridges.setDataStructure(root);
	bridges.visualize();

	return 0;
}

// inserts a record into the tree
BSTElement<float, EarthquakeUSGS> *insert (BSTElement<float, EarthquakeUSGS> *rt,
	BSTElement<float, EarthquakeUSGS> *new_el) {
	if (rt == nullptr)
		return new_el;
	else if (new_el->getKey() < rt->getKey())
		rt->setLeft(insert(rt->getLeft(), new_el));
	else
		rt->setRight(insert(rt->getRight(), new_el));

	return rt;
}


