from bridges.bridges import *
from bridges.bst_element import *
import sys

def main():
    # Part 1 of this tutorial will illustrate the use of the BRIDGES in building
    # binary search trees.  We will begin by constructing the tree manually and
    # displaying it

    # create Bridgs object, set credentials

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Simple  Binary Search Tree Example")
    bridges.set_description("This example illustrates a binary search tree built using BRIDGES")


    # we will create the tree manually in this example

    # create the nodes
    root  = BSTElement(key=100)
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

    # label the nodes 
    root.label = "Root"
    node1.label =  "Node1"
    node2.label = "Node2"
    node3.label = "Node3"
    node4.label = "Node4"
    node5.label = "Node5"

    # set visualizer type
    bridges.set_data_structure(root)
    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

