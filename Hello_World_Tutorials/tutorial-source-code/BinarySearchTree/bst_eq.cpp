
#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "BSTElement.h"


using namespace std;
using namespace bridges;

BSTElement&lt;float, EarthquakeUSGS&gt; *insert (BSTElement&lt;float, EarthquakeUSGS&gt; *rt,
                    BSTElement&lt;float, EarthquakeUSGS&gt; *new_el);

int max_quakes = 25;

int main() {
	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";
		
	Bridges::initialize(14, "kalpathi60", "486749122386");
								// read the earth quake  data and build the BST
	Bridges::setTitle("Recent Earthquakes (USGIS Data)");

    vector&lt;EarthquakeUSGS&gt; eq_list = DataSource::getEarthquakeData(max_quakes);

	BSTElement&lt;float, EarthquakeUSGS&gt; *root = nullptr;

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		BSTElement&lt;float, EarthquakeUSGS&gt; 
			*bst_node = new BSTElement&lt;float, EarthquakeUSGS&gt;(eq.getMagnitude(), eq); 
			bst_node->setLabel(eq.getTitle() + "\\nLat/Long: ( " +
				to_string(eq.getLatit()) + "," + to_string(eq.getLongit()) + " )\\n" +
                eq.getDateStr());
		root = insert (root, bst_node);
	}

					// visualize the binary search tree
	Bridges::setDataStructure(root);
	Bridges::visualize();

	return 0;
}

BSTElement&lt;float, EarthquakeUSGS&gt; *insert (BSTElement&lt;float, EarthquakeUSGS&gt; *rt,
                    BSTElement&lt;float, EarthquakeUSGS&gt; *new_el) {
	if (rt == nullptr)
		return new_el;
	else if (new_el->getKey() < rt->getKey())
		rt->setLeft(insert(rt->getLeft(), new_el));
	else
		rt->setRight(insert(rt->getRight(), new_el));

	return rt;
}


