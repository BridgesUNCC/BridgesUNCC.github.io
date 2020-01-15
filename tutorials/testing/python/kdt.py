from bridges.bridges import *
from bridges.kd_tree_element import *
import sys


# create the Bridges object, set credentials
def main():

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description 
    bridges.set_title("A Kd Tree Example")
    bridges.set_description("A three-level tree with partitioners cycling between X and Y.  The root node color is set to red while the leaf nodes that represent code letters are set to orange. Hit the 'l' button to see the partitioning dimension at each node")
    
	# create tree nodes
    t0 = KDTreeElement(key = 50, dim = 0)
    t1 = KDTreeElement(key = 25, dim = 1)
    t2 = KDTreeElement(key = 75, dim = 1)
    t3 = KDTreeElement(key = 20, dim = 0)
    t4 = KDTreeElement(key = 30, dim = 0)
    t5 = KDTreeElement(key = 60, dim = 0)
    t6 = KDTreeElement(key = 80, dim = 0)
    
	# form links
    t0.left = t1
    t0.right = t2
    t1.left = t3
    t1.label = "X"
    t1.right = t4
    t2.left = t5
    t2.right = t6
    
	# visual attributes
    t0.label = "X"
    t1.label = "Y"
    t2.label = "Y"
    t3.label = "X"
    t4.label = "X"
    t5.label = "X"
    t6.label = "X"
    
    t0.color = "red"
    
    t1.color = "orange"
    t4.color = "orange"
    t5.color = "orange"
    t6.color = "orange"
    
    bridges.set_data_structure(t0)
    bridges.visualize()

if __name__ == "__main__":
    main()
