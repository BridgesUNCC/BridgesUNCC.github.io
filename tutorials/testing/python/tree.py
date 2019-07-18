from bridges.bridges import *
from bridges.tree_element import *
import sys

def main():

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A General Tree Example")
    bridges.set_description("A basic tree with seven nodes. Three on one side and three on the other. The root node is set to red with 0.3 opacity. "
            +	"The other six nodes are neutral color.")

    # create tree nodes
    t0 = TreeElement(e = "Hello")
    t1 = TreeElement(e= "this")
    t2 = TreeElement(e="is")
    t3 = TreeElement(e="a")
    t4 = TreeElement(e="generic")
    t5 = TreeElement(e="tree")
    t6 = TreeElement(e="representation")

    # put in labels for each node; simply use integers
    t0.set_label("10")
    t1.set_label("20")
    t2.set_label("30")
    t3.set_label("40")
    t4.set_label("50")
    t5.set_label("60")
    t6.set_label("70")

    # add links to children
    t0.add_child(t1)
    t0.add_child(t2)
    t0.add_child(t5)
    t2.add_child(t4)
    t2.add_child(t5)
    t3.add_child(t6)

    # set some visual attributes
    t0.get_visualizer().set_color("red")
    t0.get_visualizer().set_opacity(0.3)

    # set visualizer type
    bridges.set_data_structure(t0)

    # visualize the tree
    bridges.visualize()

if __name__ == "__main__":
    main()

