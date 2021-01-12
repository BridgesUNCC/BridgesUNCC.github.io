#include <string>
#include "Bridges.h"
#include "GraphAdjList.h"

using namespace std;
using namespace bridges;

// Part 2 of this tutorial will demonstrate how to style the edges and links of 
// an adjacency list based graph using BRIDGES and display it.
// Relevant Classes: GraphAdjList class, ElementVisualizer, 
// LinkVisualizer, Color. We will use the same graph as in  Part 1

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	// set a title 
	bridges.setTitle("A Simple Adjacency list based Graph Example.");

	// set  description
	bridges.setDescription("Demonstrate styling graph nodes and links with visual attributes");

	// create a graph with key values of type string. See the
	// the documentation for GraphAdjList for its full capabilities
	GraphAdjList<string> graph;

	// first create a few vertices 

	// create some actor names to be added to the graph
	string 	kevin_bacon = "Kevin Bacon", 
			denzel_washington = "Denzel Washington",
			morgan_freeman = "Morgan Freeman", 
			tom_cruise = "Tom Cruise", 
			angelina_jolie = "Angelina Jolie", 
			amy_adams = "Amy Adams", 
			brad_pitt = "Brad Pitt"; 
	// add them to the graph
	graph.addVertex(kevin_bacon);
	graph.addVertex(denzel_washington);
	graph.addVertex(morgan_freeman);
	graph.addVertex(tom_cruise);
	graph.addVertex(angelina_jolie);
	graph.addVertex(amy_adams);
	graph.addVertex(brad_pitt);

	// add edges
	graph.addEdge(kevin_bacon, denzel_washington);
	graph.addEdge(kevin_bacon, morgan_freeman);
	graph.addEdge(kevin_bacon, angelina_jolie);
	graph.addEdge(amy_adams, angelina_jolie);
	graph.addEdge(tom_cruise, amy_adams);
	graph.addEdge(angelina_jolie, brad_pitt);
	graph.addEdge(brad_pitt, denzel_washington);

	// style  the nodes
	
	// distinguish the male and female actors by color
    graph.getVertex(kevin_bacon)->setColor("limegreen");
    graph.getVertex(brad_pitt)->setColor("limegreen");
    graph.getVertex(morgan_freeman)->setColor("limegreen");
    graph.getVertex(denzel_washington)->setColor("limegreen");
    graph.getVertex(tom_cruise)->setColor("limegreen");
    graph.getVertex(angelina_jolie)->setColor("crimson");
    graph.getVertex(amy_adams)->setColor("crimson");

	// shape
    graph.getVertex(brad_pitt)->setShape(SQUARE);
    graph.getVertex(angelina_jolie)->setShape(SQUARE);

	// opacity
    graph.getVertex(tom_cruise)->setOpacity(0.3f);

	// style the links
	graph.getLinkVisualizer(angelina_jolie, brad_pitt)->setColor("orange");
	graph.getLinkVisualizer(angelina_jolie, brad_pitt)->setLabel("Dated/Married");
	graph.getLinkVisualizer(angelina_jolie, brad_pitt)->setThickness(5.0f);

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);

	// Visualize the graph
	bridges.visualize();

	return 0;
}
