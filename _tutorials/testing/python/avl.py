from bridges.bridges import *
from bridges.avl_tree_element import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

    # create an AVL tree elements
    avl_root = AVLTreeElement(50, "Hello")

    avl_2 = AVLTreeElement(30, "This")
    avl_3 = AVLTreeElement(70, "is")
    avl_4 = AVLTreeElement(20, "an")
    avl_5 = AVLTreeElement(40, "AVL")
    avl_6 = AVLTreeElement(90, "Tree")


    # put in the balance factors - done manually here
    # for illustration, but in a real project, the user will
    # implement this as part of the insert/delete
    # operations on the tree to maintain a balanced tree
    avl_root.set_label("0")
    avl_2.set_label("0")
    avl_3.set_label("-1")
    avl_4.set_label("0")
    avl_5.set_label("0")
    avl_6.set_label("0")

    # add links between nodes
    avl_root.set_left(avl_2)
    avl_root.set_right(avl_3)
    avl_2.set_left(avl_4)
    avl_2.set_right(avl_5)
    avl_3.set_right(avl_6)

    # add some visual attributes
    avl_root.get_visualizer().set_color("magenta")
    avl_root.get_visualizer().set_opacity(0.8)

    # set visualizer type
    bridges.set_data_structure(avl_root)

    # visualize the tree
    bridges.visualize()

if __name__ == "__main__":
    main()


