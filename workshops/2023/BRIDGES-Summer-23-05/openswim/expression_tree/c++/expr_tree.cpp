#include <string>
#include "Bridges.h"
#include "TreeElement.h"

using namespace bridges;
using std::string;

int main(int argc, char **argv) {


	Bridges bridges (100, "BRIDGEs_USER_ID", "BRIDGES_API_KEY");

	bridges.setTitle("An Expression Tree Example Using TreeElements");
	bridges.setDescription("A manually constructred expression tree for sqrt(Ax^2 + By + c");

	//TODO:  Create tree elements for each element of the above expression.
	// Refer to the document for TreeElement using its constructor to create
	// each element (refer to the TreeElement BRIDGES tutorial for more 
	// information

	// TODO: Tree elements can have visual attributes: color, opacity, shape
	// for the nodes and thickness, color for the links
	// Useful Links: 
	// 		http://bridgesuncc.github.io/tutorials/Tree.html
	//		http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_tree_element.html

	// 		Increase the size of the root node, colors of operator nodes, 
	//      thickness of links.


	// provide BRIDGES the  handle to the tree structure
	// you will provide the root of the tree to the following function

	// bridges.setDataStructure(root);
	// bridges.visualize();
	
	return 0;
}
