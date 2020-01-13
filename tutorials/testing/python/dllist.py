from bridges.dl_element import *
from bridges.bridges import *
import sys


def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title, description
    bridges.set_title("A doubly Linked List Example")
    bridges.set_description("This list has five nodes all linked to the nodes before and after them and illustrates visual attributes. ")

	# create list elements
    el0 = DLelement(e="Gretel Chaney", label="Gretel Chaney")
    el1 = DLelement(e="Lamont Kyler", label="Lamont Kyler")
    el2 = DLelement(e="Gladys Serino", label="Gladys Serino")
    el3 = DLelement(e="Karol Soderman", label="Karol Soderman")
    el4 = DLelement(e="Starr McGinn", label="Starr McGinn")

	# link elements
    el0.next = el1
    el1.prev = el0
    el1.next = el2
    el2.prev = el1
    el2.next = el3
    el3.prev = el2
    el3.next = el4
    el4.prev = el3

	# add visual attributes
    el0.color = "red"
    el2.color = "aliceblue"

    el0.get_link_visualizer(el1).color = "green"
    el1.get_link_visualizer(el0).color = "magenta"

    el3.get_link_visualizer(el4).thickness = 3.0
    el4.get_link_visualizer(el3).thickness = 6.0

    el2.get_link_visualizer(el3).label = "link label"

    el4.opacity = 0.5

    el0.size = 20

    # set dat structure to be visualized
    bridges.set_data_structure(el0)

    # visualize the data structure
    bridges.visualize()


if __name__ == "__main__":
    main()

