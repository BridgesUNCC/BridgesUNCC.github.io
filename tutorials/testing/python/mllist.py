from bridges.bridges import *
from bridges.ml_element import *
import sys

def main():

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Multilist Example")
    bridges.set_description("The multilist example should have one large red node, three small square red nodes, "
            +	"and eight neutral nodes. The larger red node is connected via a red link to a neutral node. The next "
            +	"link from the neutral node is blue followed by a cyan link between two of the small square red nodes.")

    # create multi linked list
    el0 = MLelement(e="0", label="0")
    el1 = MLelement(e="1", label="1")
    el2 = MLelement(e="2", label="2")
    el3 = MLelement(e="3", label="3")
    el4 = MLelement(e="4", label="4")

    # create the links
    el0.next = el1
    el1.next = el2
    el2.next = el3
    el3.next = el4

    # create the sublist from 2
    el5 = MLelement(e="5", label="5")
    el6 = MLelement(e="6", label="6")
    el7 = MLelement(e="7", label="7")

    el5.next = el6
    el6.next = el7
    el2.sub_list = el5

    el8 = MLelement(e="8", label="8")
    el9 = MLelement(e="9", label="9")

    # create second sublist
    el8.next = el9
    el3.sub_list = el8

    el10 = MLelement(e="10", label="10")
    el11 = MLelement(e="11", label="11")

    # create 3rd sublist
    el10.next = el11
    el6.sub_list = el10

    el0.visualizer.size = 40
    el0.get_link_visualizer(el1).color = "green"
    el0.get_link_visualizer(el1).thickness = 3
    el1.get_link_visualizer(el2).color = "red"
    el1.get_link_visualizer(el2).thickness = 3
    el2.get_link_visualizer(el3).color = "cyan"
    el2.get_link_visualizer(el3).thickness = 3

    # set visualizer type
    bridges.set_data_structure(el0)
    # visualize the multi linked list
    bridges.visualize()


if __name__ == "__main__":
    main()

