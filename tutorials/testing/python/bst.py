from bridges.bridges import *
from bridges.bst_element import *
from bridges.data_src_dependent.data_source import *
import sys

# recursive insert method to insert nodes into a binary search tree
def insertR(rt, newel):
    if (rt is None):
        return newel
    elif newel.get_key() < rt.get_key():
        rt.set_left(insertR(rt.get_left(), newel))
    else:
        rt.set_right(insertR(rt.get_right(), newel))
    return rt


def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Binary Search Tree Example with Earthquake Data")
    bridges.set_description("10 sets of earthquake are gathered and sorted with nodes whos magnitude is greater than "
        + "the parent is set to the right and nodes with a magnitude less than the parent set to the left. "
        + "The root is set to red the leaf nodes are neutral.")

    # Retrieve a list of 10 earthquake records from USGS using the BRIDGES API
    ami = get_earthquake_usgs_data(10)

    root = None
    # create BST nodes and insert into a tree
    for i in range(len(ami)):
        bst_node = BSTElement(ami[i].get_magnitude(), ami[i])
        # set label of the node
        bst_node.set_label(ami[i].get_title() + ami[i].get_time())

        root = insertR(root, bst_node)

    # set some visual attributes
    root.get_visualizer().set_color("red")

    #set visualizer type
    bridges.set_data_structure(root)
    #visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

