from bridges.bridges import *
from bridges.tree_element import *

def main():
    # create the Bridges object, set credentials

    bridges = Bridges(20, "YOUR_USER_ID", "YOUR_API_KEY")


    # title, description
    bridges.set_title("An Expression Tree Example Using TreeElements")
    bridges.set_description("A manually constructed expression tree for sqrt(Ax^2 + By + c")

    #TODO:  Create tree elements for each element of the above expression.
    # Refer to the document for TreeElement using its constructor to create
    # each element (refer to the TreeElement BRIDGES tutorial for more 
    # information
    
    # TODO: Tree elements can have visual attributes: color, opacity, shape
    # for the nodes and thickness, color for the links
    # Useful Links: 
    # 		http://bridgesuncc.github.io/tutorials/Tree.html
    #		http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1tree__element_1_1_tree_element.html

    # TODO: Increase the size of the root node, colors of operator nodes, 
    #      thickness of links.


    # provide BRIDGES the  handle to the tree structure
    # you will provide the root of the tree to the following function

    # bridges.set_data_structure(qrt)
    # bridges.visualize();
	

if __name__ == "__main__":
    main()
