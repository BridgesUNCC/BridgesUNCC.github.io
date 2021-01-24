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

	// get the actor - movie data from IMDB dataset
	DataSource ds (bridges);
	vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1813);

	// create a graph
	GraphAdjList<string, string, int> graph;

	// first create vertices for two actors
	string kevin_bacon = "Kevin_Bacon_(I)", denzel_washington = "Denzel_Washington";

	// add them to the graph
	graph.addVertex(kevin_bacon, "");
	graph.addVertex(denzel_washington, "");

	// color the nodes
	graph.getVertex(kevin_bacon)->setColor("red");
	graph.getVertex(kevin_bacon)->setSize(30);
	graph.getVertex(denzel_washington)->setColor("red");
	graph.getVertex(denzel_washington)->setSize(30);

	graph.addEdge(kevin_bacon, denzel_washington, 1);
	graph.getLinkVisualizer(kevin_bacon, denzel_washington)->setColor("magenta");
	graph.getLinkVisualizer(kevin_bacon, denzel_washington)->setThickness(4.0f);

	// we will find the first 15 immediate neighbors of of the two actors
	// and color those links and nodes by followng their adjacency lists

	int cnt1 = 0, cnt2 = 0;
	for (int k = 0; k < actor_list.size(); k++) {
		// from the actor movie data, get an actor-movie pair
		string a = actor_list[k].getActor();
		string m = actor_list[k].getMovie();

		if ((a == "Kevin_Bacon_(I)") && (cnt1 < 15)) {

			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(kevin_bacon, m, 1);
			graph.addEdge(m, kevin_bacon, 1);

			// make the movie node a bit transparent
			graph.getVertex(m)->setOpacity(0.7f);
			cnt1++;
		}
		else if ((a == "Denzel_Washington") && (cnt2 < 15)) {
			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(denzel_washington, m, 1);
			graph.addEdge(m, denzel_washington, 1);

			// make the movie node a bit transparent
			graph.getVertex(m)->setOpacity(0.7f);
			cnt2++;
		}
	}


	// Next, we illustrate traversing the adacency list and color the
	// movie nodes adjacent to the two actors

	// we will use iterators to traverse the adjacency list

	for (auto& edge : graph.outgoingEdgeSetOf(kevin_bacon)) {
		string from = edge.from(), to = edge.to();
		if (to != "Denzel_Washington")
			graph.getVisualizer(to)->setColor("turquoise");
	}
	for (auto& edge : graph.outgoingEdgeSetOf(denzel_washington)) {
		string from = edge.from(), to = edge.to();
		if (to != kevin_bacon)
			graph.getVisualizer(to)->setColor("orange");
	}

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);
	// Visualize the graph
	bridges.visualize();

	return 0;
}
