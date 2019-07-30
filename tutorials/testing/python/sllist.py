from bridges.bridges import *
from bridges.sl_element import *
import sys


def main():

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Single Linked List Example")
    bridges.set_description("A list of student data where each node is linked only to the next "
            +	"node in the list. Node and link colors from top of list to bottom: Blue with magenta link, "
            +	"red with magenta link, green with yellow link, magenta with green link, cyan.")

    # link the elements
    el1 = SLelement(e="Gretel Chaney", label="Gretel Chaney")
    el2 = SLelement(e="Gretel Chaney", label="Gretel Chaney")
    el3 = SLelement(e="Gretel Chaney", label="Gretel Chaney")
    el4 = SLelement(e="Gretel Chaney", label="Gretel Chaney")
    el5 = SLelement(e="Gretel Chaney", label="Gretel Chaney")

    el1.next = el2
    el2.next = el3
    el3.next = el4
    el4.next = el5

    el1.visualizer.color = "red"
    el2.visualizer.color = 'magenta'

    bridges.set_data_structure(el1)
    bridges.visualize()


if __name__ == "__main__":
    main()

