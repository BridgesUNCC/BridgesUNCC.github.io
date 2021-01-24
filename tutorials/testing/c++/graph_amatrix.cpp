#include <string>
#include <unordered_map>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include "GraphAdjMatrix.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	DataSource ds (bridges);
	vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1813);

	GraphAdjMatrix<string, string> graph;


	// first create vertices for two actors
	string bacon = "Kevin_Bacon_(I)", washington = "Denzel_Washington";

	// add them to the graph
	graph.addVertex(bacon, "");
	graph.addVertex(washington, "");

	// color the nodes
	graph.getVertex(bacon)->setColor("red");
	graph.getVertex(washington)->setColor("red");

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
			graph.getVertex(m)->setOpacity(0.5f);
			cnt1++;
		}
		else if ((a == "Denzel_Washington") && (cnt2 < 15)) {
			// add vertices for this movie  and an edge for the link
			graph.addVertex(m, "");
			graph.addEdge(washington, m, 1);
			graph.addEdge(m, washington, 1);
			// make the movie node a bit transparent
			graph.getVertex(m)->setOpacity(0.5f);
			cnt2++;
		}
	}


	// Next, we illustrate traversing the adacency matrix and coloring the
	// movie nodes adjacent to the Kevin Bacon node.

	// first get the adjacency matrix row corresponding to  Kevin Bacon
	unordered_map<string, int> bacon_row = graph.getMatrix(bacon);
	unordered_map<string, int> wash_row = graph.getMatrix(washington);

	// traverse the row corresponding to the Kevin Bacon vertex
	for (auto& term_vertex : bacon_row) {
		// color only the neighbors; make sure weight is non-zero
		if (term_vertex.first != "Denzel_Washington" && term_vertex.second)
			graph.getVertex(term_vertex.first)->setColor("green");
	}

	// provide BRIDGES the  handle to the tree structure
	bridges.setDataStructure(&graph);
	// Visualize the graph
	bridges.visualize();

	return 0;
}
