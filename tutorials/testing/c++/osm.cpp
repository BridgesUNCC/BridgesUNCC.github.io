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

	DataSource ds;
	OSMData osm_data;
	try {
	   osm_data = ds.getOSMData(35.28, -80.75, 35.32, -80.71);
	  // osm_data = ds.getOSMData("Charlotte, North Carolina");
	}
	catch (std::string s) {
		std::cerr << "Exception: " << s << "\n";
	}

	GraphAdjList<int, OSMVertex, double> graph;
	osm_data.getGraph (&graph);

	graph.forceLargeVisualization(true);
	bridges.setDataStructure(&graph);
	bridges.visualize();

	// create graph object

	return 0;
}
