
#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "BSTElement.h"


using namespace std;
using namespace bridges;

BSTElement<float, EarthquakeUSGS> *insert (BSTElement<float, EarthquakeUSGS> *rt,
	BSTElement<float, EarthquakeUSGS> *new_el);

int max_quakes = 25;

int main(int argc, char **argv) {
	Bridges *bridges =  new Bridges(110, "YOUR_USER_ID", "YOUR_API_KEY");


	string hilite_color = "orange",
		   def_color = "green",
		   end_color = "red";

	// read the earth quake  data and build the BST
	bridges->setTitle("Recent Earthquakes (USGIS Data)");

	DataSource *ds = new DataSource;

	vector<EarthquakeUSGS> eq_list = ds->getEarthquakeUSGSData(max_quakes);

	BSTElement<float, EarthquakeUSGS> *root = nullptr;

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		BSTElement<float, EarthquakeUSGS>
		*bst_node = new BSTElement<float, EarthquakeUSGS>(eq.getMagnitude(), eq);
		bst_node->setLabel(eq.getTitle() + "\\nLat/Long: ( " +
			to_string(eq.getLatit()) + "," + to_string(eq.getLongit()) + " )\\n" +
			eq.getDateStr());
		root = insert (root, bst_node);
		root->getVisualizer()->setColor(Color("red"));
	}

	// visualize the binary search tree
	bridges->setDataStructure(root);
	bridges->visualize();

	return 0;
}

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


