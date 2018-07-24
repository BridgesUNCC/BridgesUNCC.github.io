#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include "GraphAdjList.h"

using namespace std;
using namespace bridges;

int main() {
	Bridges::initialize(12, "YOUR_USER_ID", "YOUR_API_KEY");

	Bridges::setTitle("Graph Adj List Example: IMDB Data");
	vector<ActorMovieIMDB> actor_list = DataSource::getActorMovieIMDBData(1800);

	GraphAdjList<string, string> graph;


	// first create vertices for two actors
	string bacon = "Kevin_Bacon_(I)", washington = "Denzel_Washington";
	// add them to the graph
	graph.addVertex(bacon, "");
	graph.addVertex(washington, "");

	// color the nodes
	graph.getVertex(bacon)->getVisualizer()->setColor(Color("red"));
	graph.getVertex(washington)->getVisualizer()->setColor(Color("red"));

	graph.addEdge(bacon, washington, 1);

	// we will find the first 15 immediate neighbors of of the two actors
	// and color those links and nodes by followng their adjacency lists
	int cnt1 = 0, cnt2 = 0;
	for (int k = 0; k < actor_list.size(); k++) {
		// from the actor movie data, get an actor-movie pair
		string a = actor_list.at(k).getActor();
		string m = actor_list.at(k).getMovie();

		if ((a == "Kevin_Bacon_(I)") && (cnt1 < 15)) {

			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(bacon, m, 1);
			graph.addEdge(m, bacon, 1);

			// make the movie node a bit transparent
			graph.getVertex(m)->getVisualizer()->setOpacity(0.5f);
			cnt1++;
		}
		else if ((a == "Denzel_Washington") && (cnt2 < 15)) {
			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(washington, m, 1);
			graph.addEdge(m, washington, 1);
			// make the movie node a bit transparent
			graph.getVertex(m)->getVisualizer()->setOpacity(0.5f);
			cnt2++;
		}
	}


	// Next, we illustrate traversing the adacency list and color the
	// movie nodes adjacent to the Kevin Bacon node.

	// first get the adjacency list for Kevin Bacon
	SLelement<Edge<string>>  *head = graph.getAdjacencyList().at(bacon);
	// traverse the adjacency list
	for (SLelement<Edge<string>> *sle = head; sle != nullptr;
		sle = sle->getNext() ) {
		// get the terminating vertex
		string term_vertex = sle->getValue().getVertex();
		// find the corresponding element
		Element<string> *el = graph.getVertex(term_vertex);
		// set the  color of the node except the Denzel W. node
		if (term_vertex != "Denzel_Washington")
			el->getVisualizer()->setColor(Color("green"));
	}

	// provide BRIDGES the  handle to the tree structure
	Bridges::setDataStructure(&graph);
	// Visualize the graph
	Bridges::visualize();

	return 0;
}
