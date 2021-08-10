from bridges.dl_element import *
from bridges.bridges import *
import sys


def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title, description
    bridges.set_title("A Visualization Attributes Related Example")

	# create list elements
    el0 = DLelement(e="element0",  label="Element 0")
    el1 = DLelement(e="element1",  label="Element 1")

	# link elements
    el0.next = el1
    el1.prev = el0

	# add visual attributes

	# set color, size , shape for list elements - see the Color class 
    # for supported colors
    el0.color = "red"
    el0.setSize = 20.
    el1.setShape = "diamond"

    # set node transparency
    el0.opacity = 0.3

    # color the links - must specify a valid terminating element
    # color the link from el0 to el1
    el0.get_link_visualizer(el1).color = "green"

    # color the link from el1 to el0, using rgb color
    el1.get_link_visualizer(el0).color = [255., 0., 255., 1.]

    # adjust link thickness
    el0.get_link_visualizer(el1).thickness = 2.0
    el1.get_link_visualizer(el0).thickness = 4.0

    # set link label
    el1.get_link_visualizer(el0).set_label("Link Label")

    # set dat structure to be visualized
    bridges.set_data_structure(el0)

    # visualize the data structure
    bridges.visualize()


if __name__ == "__main__":
    main()

