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

	//create the Bridges object, set credentials

	bridges.setServer("clone");

	DataSource  *ds = new DataSource;
	/*
		OSMData osm_data = ds->getOSMData("uncc_campus");
	*/
	OSMData osm_data;
	try {
		osm_data = ds->getOSMDataOld("uncc_campus");
	}
	catch (std::string s) {
		std::cerr << "Exception: " << s << "\n";
	}
	vector<OSMVertex> vertices = osm_data.getVertices();
	vector<OSMEdge> edges = osm_data.getEdges();

	GraphAdjList<int, int>  *gr = new GraphAdjList<int, int>;
	double coords[2];

	for (int k = 0; k < vertices.size(); k++) {
		gr->addVertex(k);
		vertices[k].getCartesianCoords(coords);
		gr->getVertex(k)->setLocation(coords[0], coords[1]);
		gr->getVertex(k)->setColor(Color("green"));
	}
	for (int k = 0; k < edges.size(); k++) {
		gr->addEdge(edges[k].getSourceVertex(), edges[k].getDestinationVertex(),
			edges[k].getEdgeLength() );
		gr->getLinkVisualizer(edges[k].getSourceVertex(), edges[k].getDestinationVertex())->setColor(Color("red"));

	}

	gr->forceLargeVisualization(true);
	bridges.setDataStructure(gr);
	bridges.visualize();

	// create graph object

	return 0;
}
