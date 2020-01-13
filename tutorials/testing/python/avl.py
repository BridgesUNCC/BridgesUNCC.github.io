from bridges.bridges import *
from bridges.avl_tree_element import *
import sys

def main():

    # create the Bridges object, set credentials

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("AVL Tree Example")
    bridges.set_description("This AVL tree has six elements with some visual attributes. Hitting 'l' will show the balance factors at the nodes.")

    # create an AVL tree elements
    avl_root = AVLTreeElement(50, "Hello")

    avl2 = AVLTreeElement(30, "This")
    avl3 = AVLTreeElement(70, "is")
    avl4 = AVLTreeElement(20, "an")
    avl5 = AVLTreeElement(40, "AVL")
    avl6 = AVLTreeElement(90, "Tree")

    # put in the balance factors - done manually here
    # for illustration, but in a real project, the user will
    # implement this as part of the insert/delete
    # operations on the tree to maintain a balanced tree
    avl_root.label = '0'
    avl2.balance_factor = "0"
    avl3.balance_factor = "1"
    avl4.balance_factor = "0"
    avl5.balance_factor = "0"
    avl6.balance_factor = "0"

    # add links between nodes
    avl_root.left = avl2
    avl_root.right = avl3
    avl2.left = avl4
    avl2.right = avl5
    avl3.right = avl6

    # add some visual attributes
    avl_root.visualizer.color = "magenta"
    avl_root.visualizer.opacity = 0.8
    avl_root.get_link_visualizer(avl2).color = "cyan"
    avl_root.get_link_visualizer(avl3).color = "blue"

	# display the balance factors (on mouseover)
    avl_root.label = str(avl_root.balance_factor)
    avl2.label = str(avl2.balance_factor)
    avl3.label = str(avl3.balance_factor)
    avl4.label = str(avl4.balance_factor)
    avl5.label = str(avl5.balance_factor)
    avl6.label = str(avl6.balance_factor)

    # set visualizer type
    bridges.set_data_structure(avl_root)

    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()


