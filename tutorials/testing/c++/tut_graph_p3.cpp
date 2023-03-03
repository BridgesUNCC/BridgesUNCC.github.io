#include <string>
#include "Bridges.h"
#include "GraphAdjList.h"
#include "SLelement.h"

using namespace std;
using namespace bridges;

// In Part 3 of this tutorial will demonstrate some advanced features 
// of adjacency list // based graphs in BRIDGES, such as graph traversal 
// and iterators that make it more convenient.
//
// We will continue using the same graph of actors
//
// References: GraphAdjList class

int main(int argc, char **argv) {
	// create Bridges object, set credentials
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	// set a title 
	bridges.setTitle("A Simple Adjacency list based Graph Example.");

	// set  description
	bridges.setDescription("Demonstrate advanced features of graphs, traversal of adjacency lists, use of iterators");

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

	// Next, we illustrate traversing the adacency list  in different ways

	// using core BRIDGES classes to print the movies that Kevin Bacon is adjacent to
	cout << "Using core Bridges classes\n" << endl;
	for (SLelement<Edge<string>> *sle = graph.getAdjacencyList(kevin_bacon);
						sle != nullptr; sle = sle->getNext()) {
		Edge<string> edge = sle->getValue();
		cout << edge.from() << " --> " << edge.to() << endl;
	}


	// using iterators to print the movies that Kevin Bacon is adjacent to
	cout << "Using iterators\n" << endl;
	for (auto& edge : graph.outgoingEdgeSetOf(kevin_bacon)) {
		string from = edge.from(), to = edge.to();
		cout << from << " --> " << to << endl;
    }

	// finally, list the vertices of the graph, using iterators
	cout << "Using iterators to print the graph vertices..\n";
	for (auto vert: graph.keySet()) {
		cout << vert << "\n";
	}

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);

	// Visualize the graph
	bridges.visualize();

	return 0;
}
