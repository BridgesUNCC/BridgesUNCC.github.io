#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// create a graph
	GraphAdjList<string, string, int> graph;

	// read the data
	ifstream infile("/Users/kalpathi/gr/bridges/testing/c++/web_tutorial_mastercopy/map.txt");
	int num_verts, num_edges, src, dest;
	string s; 
	float thickness;
	vector<string> verts;

	infile >>  num_verts;
cout << "Num Vertices:" << num_verts << endl;
	for (int k = 0; k < num_verts; k++) {
		infile >>  s;
cout << "Vertex:" << s << endl;
		verts.push_back(s);
		graph.addVertex(s, s);
	}
	infile >>  num_edges;
	for (int k = 0; k < num_edges; k++) {
		infile >>  src >> dest >> thickness;
		graph.addEdge(verts[src], verts[dest]);
		graph.getLinkVisualizer(verts[src],verts[dest])->setThickness(thickness);
		if (thickness > 1.)
		graph.getLinkVisualizer(verts[src],verts[dest])->setColor("red");
	}

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);
	// Visualize the graph
	bridges.visualize();

	return 0;
}
