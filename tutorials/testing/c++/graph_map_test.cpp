#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
        "YOUR_API_KEY");

	// create an adjacency list based graph
	GraphAdjList<string, string> g;

	for (int i = 0; i < 10; i++) {
		g.addVertex("node" + std::to_string(i), "node" + std::to_string(i));
		if (i > 0) {
			g.addEdge("node" + std::to_string(i), "node" + std::to_string(i - 1));
		}
	}

	// Pass the graph object to BRIDGES
	bridges.setDataStructure(g);

	// visualize SVG AlbersUSA map
	bridges.setCoordSystemType("albersusa");
	bridges.setMapOverlay(true);
	bridges.visualize();

	// visualize SVG World map
	bridges.setCoordSystemType("equirectangular");
	bridges.setMapOverlay(true);
	bridges.setTitle("SVG World Map");
	bridges.visualize();


	// CANVAS VERSIONS (add >100 nodes)
	for (int i = 10; i < 110; i++) {
		g.addVertex("node" + std::to_string(i), "node" + std::to_string(i));
		if (i > 0) {
			g.addEdge("node" + std::to_string(i), "node" + std::to_string(i - 1));
		}
	}

	// fix a node over Charlotte, NC
	g.getVertex("node6")->setLocation(-80.8431, 35.2271);
	g.getVertex("node6")->setColor("red");

	// visualize Canvas AlbersUSA map
	bridges.setCoordSystemType("albersusa");
	bridges.setMapOverlay(true);
	bridges.setTitle("Canvas USA Map");
	bridges.visualize();

	// fix a node over London
	g.getVertex("node10")->setLocation(-0.1278, 51.5074);
	g.getVertex("node10")->setColor("red");

	// visualize Canvas World map
	bridges.setCoordSystemType("equirectangular");
	bridges.setMapOverlay(true);
	bridges.setTitle("Canvas World Map");
	bridges.visualize();
}
