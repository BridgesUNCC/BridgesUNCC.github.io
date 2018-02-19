#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "GraphAdjList.h"

using namespace bridges;

int main() {
	Bridges::initialize(12, "kalpathi60", "486749122386");
//	Bridges::initialize(12, "bridges_public", "997924677918");

	GraphAdjList<string, string> gr;

					// create the nodes
	gr.addVertex("John", "");
	gr.addVertex("Becky", "");
	gr.addVertex("Sam", "");


	gr.addEdge("John", "Becky", 5);
	gr.addEdge("John","Sam", 1);
	gr.addEdge("Becky", "John", 1);

	
//	Element<string> el = gr.getVertices().at("John");
//	el = gr.getVertices().at("Becky");
	

	unordered_map<string, Element<string>* > *v = gr.getVertices(); 

	Element<string> *el2 = v->at("Becky");
	v->at("John")->getLinkVisualizer(el2)->setColor(Color("cyan"));
	Bridges::setTitle("Graph Adjacency List Example");
	
					// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(&gr);
//	Bridges::setVisualizeJSON(true);

	Bridges::visualize();

	return 0;
}
