from bridges.bridges import *
from bridges.bst_element import *
from bridges.data_src_dependent.data_source import *
import sys

# recursive insert method to insert nodes into a binary search tree
def insertR(rt, newel):
    if (rt is None):
        return newel
    elif newel.key < rt.key:
        rt.left = insertR(rt.left, newel)
    else:
        rt.right = insertR(rt.right, newel)
    return rt


def main():
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Binary Search Tree Example with Earthquake Data")
    bridges.set_description("10 sets of earthquake are gathered and sorted with nodes whos magnitude is greater than "
        + "the parent is set to the right and nodes with a magnitude less than the parent set to the left. "
        + "The root is set to red the leaf nodes are neutral.")

    # Retrieve a list of 25 earthquake records from USGS using the BRIDGES API
    ami = get_earthquake_usgs_data(25)

    root = None
    # create BST nodes and insert into a tree
    for i in range(len(ami)):
        bst_node = BSTElement(key=ami[i].magnitude, e=ami[i])

        # set label of the node
        bst_node.label = ami[i].title + "\n" + ami[i].time

        # insert node into tree
        root = insertR(root, bst_node)

    # set some visual attributes
    root.color = "red"

    # set visualizer type
    bridges.set_data_structure(root)
    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

