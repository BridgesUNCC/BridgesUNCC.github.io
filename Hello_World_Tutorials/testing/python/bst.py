from Bridges.Bridges import *
from Bridges.BSTElement import *
from Bridges.data_src_dependent.DataSource import *

# recursive insert method to insert nodes into a binary search tree
def insertR(rt, newel):
    if (rt is None):
        return newel
    elif newel.get_key() < rt.get_key():
        rt.set_left(insertR(rt.get_left(), newel))
    else:
        rt.set_right(insertR(rt.get_right(), newel))
    return rt


class EarthquakeDriver():

    # create bridges object
    bridges = Bridges(10, "YOUR_USER_ID", "YOUR_API_KEY")
    bridges.setTitle("A Binary Search Tree Example with Earthquake Data")

    # Retrieve a list of 10 earthquake records from USGS using the BRIDGES API
    ami = getEarthquakeUSGSData(10)

    root = None
    # create BST nodes and insert into a tree
    for i in range(len(ami)):
        bst_node = BSTElement(ami[i].getMagnitude(), ami[i])
        # set label of the node
        bst_node.set_label(ami[i].getTitle() + ami[i].getTime())

        root = insertR(root, bst_node)

    # set some visual attributes
    root.get_visualizer().set_color("red")

    #set visualizer type
    bridges.set_data_structure(root)
    #visualize the tree
    bridges.visualize()



