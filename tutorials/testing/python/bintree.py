from bridges.bridges import *
from bridges.bin_tree_element import *
import sys


def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Huffman Coding Tree Example")
    bridges.set_description("[Binary Tree Application]: Huffman tree coding the symbols C, D, E, K, L, M, U, Z with frequencies 32, 42, 120, 7, 42, 24, 37, 2 "
            + "Root is set to red and leaf nodes are set to orange.")

    #build the tree
    t0 = BinTreeElement(label = "306", e = 0)
    t1 = BinTreeElement(label = "120\\nE",e = 1)
    t2 = BinTreeElement(label = "186",e = 2)
    t3 = BinTreeElement(label = "79",e = 3)
    t4 = BinTreeElement(label = "37\\nU",e = 4)
    t5 = BinTreeElement(label = "42\\nD",e = 5)
    t6 = BinTreeElement(label = "42\\nL",e = 6)
    t7 = BinTreeElement(label = "107",e = 7)
    t8 = BinTreeElement(label = "65",e = 8)
    t9 = BinTreeElement(label = "32\\nC",e = 9)
    t10 = BinTreeElement(label = "33",e = 10)
    t11 = BinTreeElement(label = "9",e = 11)
    t12 = BinTreeElement(label = "2\\nZ",e = 12)
    t13 = BinTreeElement(label = "7\\nK",e = 13)
    t14 = BinTreeElement(label = "24\\nM",e = 14)


    t0.set_left(t1)
    t0.set_right(t2)
    t2.set_left(t3)
    t2.set_right(t7)
    t3.set_left(t4)
    t3.set_right(t5)
    t7.set_left(t6)
    t7.set_right(t8)
    t8.set_left(t9)
    t8.set_right(t10)
    t10.set_left(t11)
    t10.set_right(t14)
    t11.set_left(t12)
    t11.set_right(t13)

    # color the leaf nodes to represent the code letters
    t0.get_visualizer().set_color("red")
    t1.get_visualizer().set_color("orange")
    t4.get_visualizer().set_color("orange")
    t5.get_visualizer().set_color("orange")
    t6.get_visualizer().set_color("orange")
    t9.get_visualizer().set_color("orange")
    t12.get_visualizer().set_color("orange")
    t13.get_visualizer().set_color("orange")
    t14.get_visualizer().set_color("orange")

    # set visualizer type
    bridges.set_data_structure(t0)
    #visualize the tree
    bridges.visualize()

if __name__ == "__main__":
    main()

