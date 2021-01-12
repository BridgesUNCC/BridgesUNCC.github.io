from bridges.bridges import *
from bridges.bst_element import *
import sys

def main():
    # Part 2 of this tutorial will illustrate the use of the BRIDGES in styling
    # nodes and links of binary search trees.  For instance you might want to
    # illustrate the nodes and links that were visited during an insertion 
    # operation. Or color the tree based on a particular type of traversal.

    # We will use the same tree as in Part 1 and illustrate styling.

    # create Bridgs object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Simple  Binary Search Tree Example")
    bridges.set_description("This example illustrates styling a binary search tree nodes and links using BRIDGES");


    # we will create the tree manually in this example

    # create the nodes
    root  = BSTElement(key = 100)
    node1 = BSTElement(key = 50)
    node2 = BSTElement(key = 200)
    node3 = BSTElement(key = 250)
    node4 = BSTElement(key = 75)
    node5 = BSTElement(key = 33)

    # construct the tree
    root.left = node1
    root.right = node2
    node2.right = node3
    node1.right = node4
    node1.left = node5

    #  style the nodes and links. Nodes have properties of label shape, size,
    #  color and opacity. Links have properties of a label, color and thickness

    root.color = "red";
    root.size = 40

    #  path to largest key
    node2.shape = "square"
    node3.shape = "square"
    node2.color = "magenta"
    node3.color = "magenta"

    # style link from root to node2
    root.get_link_visualizer(node2).thickness = 3.0
    root.get_link_visualizer(node2).color = "orange"

    # style link from node2 to node3
    node2.get_link_visualizer(node3).thickness = 3.0
    node2.get_link_visualizer(node3).color = "orange"

    #  path to smallest key
    node1.shape = "triangle"
    node5.shape = "triangle"
    node5.color = "cyan"
    node5.color = "cyan"

    # style link from root to node2
    root.get_link_visualizer(node1).thickness = 2.0
    root.get_link_visualizer(node1).color = "purple"

    # style link from node2 to node3
    node1.get_link_visualizer(node5).thickness = 2.0
    node1.get_link_visualizer(node5).color = "purple"

    # deemphasize node 4, make it a bit transparent
    node4.opacity = 0.2



    # set visualizer type
    bridges.set_data_structure(root)
    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

