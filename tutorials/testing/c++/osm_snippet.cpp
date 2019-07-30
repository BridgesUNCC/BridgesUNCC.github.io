#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "data_src/OSMData.h"
#include "data_src/OSMVertex.h"
#include "data_src/OSMEdge.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	DataSource  *ds = new DataSource;
	OSMData osm_data = ds->getOSMDataOld("uncc_campus");

	vector<OSMVertex> vertices = osm_data.getVertices();
	vector<OSMEdge> edges = osm_data.getEdges();

	double coords[2];
	cout << "Number of Vertices [UNC Charlotte Campus]:" << vertices.size() << endl;
	cout << "Number of Edges [UNC Charlotte Campus]:" << edges.size() << endl;

	// get cartesian coordinate  location of first vertex
	osm_data.getVertices()[0].getCartesianCoords(coords);
	cout << "Location of first vertex [Cartesian Coord]: " <<  coords[0] << ","
		<< coords[1] << endl;
	return 0;
}
