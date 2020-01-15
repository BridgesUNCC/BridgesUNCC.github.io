from bridges.bridges import *
from bridges.circ_dl_element import *
import sys

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Circular Doubly Linked List Example")
    bridges.set_description("This example shows circular doubly linked example with five nodes with assigned visual attributes")

	# create list elements
    el0 = CircDLelement(e="Gretel Chaney", label="Gretel Chaney")
    el1 = CircDLelement(e="Lamont Kyler", label="Lamont Kyler")
    el2 = CircDLelement(e="Gladys Serino", label="Gladys Serino")
    el3 = CircDLelement(e="Karol Soderman", label="Karol Soderman")
    el4 = CircDLelement(e="Starr McGinn", label="Starr McGinn")

    # link the elements
    el0.next = el1
    el1.prev = el0
    el1.next = el2
    el2.prev = el1
    el2.next = el3
    el3.prev = el2
    el3.next = el4
    el4.prev = el3

	# join first and last nodes
    el4.next = el0
    el0.prev = el4

	# visual attributes
    el0.visualizer.color = "red"
    el2.visualizer.color = 'aliceblue'

    el0.get_link_visualizer(el1).color = "green"
    el3.get_link_visualizer(el4).color = "magenta"

    el0.get_link_visualizer(el1).thickness = 2.0

    el4.opacity = 0.5

    el0.size = 20

    bridges.set_data_structure(el1)
    bridges.visualize()


if __name__ == "__main__":
    main()

