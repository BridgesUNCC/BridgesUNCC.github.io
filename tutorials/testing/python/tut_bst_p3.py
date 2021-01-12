from bridges.bridges import *
from bridges.bst_element import *
import sys

def main():

    # Part 3 of this tutorial will illustrate traversing a binary search tree
    # to find a specific key value and mark it as well as style the path to it

    # create Bridges object, set credentials

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Simple  Binary Search Tree Example")
    bridges.set_description("This example illustrates finding a key in a constructed binary search tree and styling the visited nodes and links")


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

    # traverse the tree to the largest node and style them to find 
    # key value 75
    r = root
    left = None
    right = None 
    found = False
    search_key = 75
    while (not found and (r != None)):
        # style the node
        r.color = "red"
        r.shape = "square"
        r.size = 20

        if (r.key  == search_key):
            found = True
            r.color = "orange"
            r.size = 49
            print("Yay! Found it!\n")
        elif (search_key < r.key):  # go left
            left = r.left    
            if (left):   # style link
                r.get_link_visualizer(left).color = "cyan"
                r.get_link_visualizer(left).thickness = 5.0
            r = left
        else:
            right = r.right  
            if (right):  # style link
                r.get_link_visualizer(right).color = "cyan"
                r.get_link_visualizer(right).thickness = 5.0
            r = right

    # set visualizer type
    bridges.set_data_structure(root)
    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

