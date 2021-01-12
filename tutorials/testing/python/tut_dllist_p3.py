from bridges.dl_element import *
from bridges.bridges import *
import sys


def main():
    # This tutorial creates a number of BRIDGES doubly linked list elements, 
    # links them into a list and displays them
    #
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title 
    bridges.set_title("A doubly Linked List Example")

    # description
    bridges.set_description("Illustrate the user of iterators with doubly linked lists")

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

    # iterate and print elements

    # using a regular loop
    el = el0
    while (el != None): 
        print("\t" + el.label)
        el = el.next

    # using a forward iterator
    # 
    #for el in dle_iterator:
    #    print("\t" + el.label)
        
    # using a range loop 

    # using a reverse iterator

    # set data structure to be visualized
    bridges.set_data_structure(el0)

    # visualize the data structure
    bridges.visualize()


if __name__ == "__main__":
    main()

