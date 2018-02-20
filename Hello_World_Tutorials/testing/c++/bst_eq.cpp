
#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "BSTElement.h"
#include "BST.h"


using namespace std;
using namespace bridges;

int max_quakes = 25;

int main() {
	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";
		
	Bridges::initialize(14, "kalpathi60", "486749122386");
								// read the earth quake  data and build the BST
	Bridges::setTitle("Recent Earthquakes (USGIS Data)");

    vector<EarthquakeUSGS> eq_list = DataSource::getEarthquakeData(max_quakes);

	BST<float, EarthquakeUSGS> *bst = new BST<float, EarthquakeUSGS> ();

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		bst->insert(eq.getMagnitude(), eq);
	}

					// visualize the binary search tree
	Bridges::setDataStructure(bst->getRoot());
	Bridges::visualize();

	return 0;
}
