from bridges.dl_element import *
from bridges.bridges import *
import sys


def main():
    # Part 2 of the tutorial illustrates styling features in a doubly 
    # linked list. Uses the same list as part 1 
    #
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title 
    bridges.set_title("A doubly Linked List Example")

    # description
    bridges.set_description("Illustrates styling features in a doubly linked list")

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

    # style the nodes and links in the list 

    # color the elements
    el0.color = "red"
    el1.color = "green"
    el2.color = "blue"
    el3.color = "cyan"
    el4.color = "yellow"

    # element size
    el0.size = 40
    el1.size = 40

    # element opacity
    el1.opacity = 0.2
    el3.opacity = 0.2

    # shape
    el2.shape = "triangle"
    el3.shape = "square"

    # thickness
    el3.get_link_visualizer(el4).thickness = 6.0
    el4.get_link_visualizer(el3).thickness = 6.0

    # link color
    el3.get_link_visualizer(el4).color = "orange"
    el4.get_link_visualizer(el3).color = "orange"

    # link label
    el0.get_link_visualizer(el1).label = "Chaney-->Kyler"
    el1.get_link_visualizer(el0).label = "Kyler-->Chaney"


    # set data structure to be visualized
    bridges.set_data_structure(el0)

    # visualize the data structure
    bridges.visualize()


if __name__ == "__main__":
    main()

