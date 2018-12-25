
#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "BSTElement.h"
#include "BST.h"


using namespace std;
using namespace bridges;

int max_quakes = 25;

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(50, "YOUR_USER_ID", "YOUR_API_KEY");

	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";
		
								// read the earth quake  data and build the BST
	bridges->setTitle("Recent Earthquakes (USGIS Data)");

    vector<EarthquakeUSGS> eq_list = DataSource::getEarthquakeData(max_quakes);

	BST<float, EarthquakeUSGS> *bst = new BST<float, EarthquakeUSGS> ();

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		bst->insert(eq.getMagnitude(), eq);
	}

					// visualize the binary search tree
	bridges->setDataStructure(bst->getRoot());
	bridges->visualize();

	return 0;
}
