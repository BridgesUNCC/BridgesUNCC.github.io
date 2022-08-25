#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
        "YOUR_API_KEY");

	// create a graph
    GraphAdjList<string, string, int> graph;
/*
	string 1212 = "ITCS 1212";
	string 1213 = "ITCS 1213";
	string 2175 = "ITCS 2175";
	string 2214 = "ITCS 2214";
	string 3120 = "ITCS 3120";
	string 3134 = "ITCS 3134";
	string 3181 = "ITCS 3181";
	string 3146 = "ITCS 3146";
	string 3155 = "ITCS 3155";
	string 1241 = "MATH 1241";
	string 1242 = "MATH 1242";
	string 2164 = "MATH 2164";
*/
	unordered_map<int, string> courses;
	courses[0] = "ITCS 1212";
	courses[1] = "ITCS 1213";
	courses[2] = "ITCS 2175";
	courses[3] = "ITCS 2214";
	courses[4] = "ITCS 3120";
	courses[5] = "ITCS 3134";
	courses[6] = "ITCS 3181";
	courses[7] = "ITCS 3146";
	courses[8] = "ITCS 3155";
	courses[9] = "MATH 1241";
	courses[10] = "MATH 1242";
	courses[11] = "MATH 2164";

	for (auto & k : courses)  {
		graph.addVertex(k.second, "");
		graph.getVertex(k.second)->setColor("red");
		graph.getVertex(k.second)->setSize(49);
	}
	// edges
	graph.addEdge(courses[0], courses[1]);
	graph.getLinkVisualizer(courses[0], courses[1])->setThickness (8.0);
	graph.addEdge(courses[1], courses[2]);
	graph.addEdge(courses[2], courses[3]);

//	graph.addEdge(kevin_bacon, denzel_washington, 1);
//	graph.getLinkVisualizer(kevin_bacon, denzel_washington)->setColor("magenta");
//	graph.getLinkVisualizer(kevin_bacon, denzel_washington)->setThickness(4.0f);

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);
	// Visualize the graph
	bridges.visualize();

	return 0;
}
