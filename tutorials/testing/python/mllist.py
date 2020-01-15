from bridges.bridges import *
from bridges.ml_element import *
import sys

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A Multilist Example")
    bridges.set_description("The large red node is the  beginning of list. Smaller red nodes spawn sublists, {2,5,{6, 10, 11},7}, {6, 10, 11} and {3,4}. Sublist origins are large green squares")

    # create  list nodes
    el0 = MLelement(e="0", label="0")
    el1 = MLelement(e="1", label="1")
    el2 = MLelement(e="2", label="2")
    el3 = MLelement(e="3", label="3")
    el4 = MLelement(e="4", label="4")
    el5 = MLelement(e="5", label="5")
    el6 = MLelement(e="6", label="6")
    el7 = MLelement(e="7", label="7")
    el8 = MLelement(e="8", label="8")
    el9 = MLelement(e="9", label="9")
    el10 = MLelement(e="10", label="10")
    el11 = MLelement(e="11", label="11")

    # create the main list
    el0.next = el1
    el1.next = el2
    el2.next = el3
    el3.next = el4

    # create the sublist from 2 to 5, 6, 7
    el2.sub_list = el5
    el5.next = el6
    el6.next = el7


    # create sublist from 3 to 8, 9
    el3.sub_list = el8
    el8.next = el9


    # create the sublist from 6 to 10, 11
    el6.sub_list = el10
    el10.next = el11

	# visual attributes
    el0.color = "red"

	# mark sublist origins
    el2.color = "green"
    el3.color = "green"
    el6.color = "green"

    el0.size = 40
    el0.get_link_visualizer(el1).color = "green"
    el0.get_link_visualizer(el1).thickness = 3
    el1.get_link_visualizer(el2).color = "blue"
    el1.get_link_visualizer(el2).thickness = 3
    el2.get_link_visualizer(el3).thickness = 3

    # set visualizer type
    bridges.set_data_structure(el0)

    # visualize the multi linked list
    bridges.visualize()


if __name__ == "__main__":
    main()

