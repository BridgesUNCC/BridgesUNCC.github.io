from bridges.bridges import *
from bridges.sl_element import *
import sys

#
# In part 3 of this tutorial we demonstrate more advanced features such as 
# using iterators to traverse lists, which are more convenient than working
# with the underlying element objects. To keep the tutorial simple, we will ignore
# styling (that was illustrated in part 2).
#
# Reference Classes: SLelement, Bridges 
#


def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title, description
    bridges.set_title("A Singly Linked List Example")
    bridges.set_description("Demonstrate advanced features, looping, iterators")

	# create the list elements
    st0 = SLelement(e="Gretel Chaney")
    st1 = SLelement(e="Lamont Kyler")
    st2 = SLelement(e="Gladys Serino")
    st3 = SLelement(e="Karol Soderman")
    st4 = SLelement(e="Starr McGinn")

    # link the elements
    st0.next = st1
    st1.next = st2
    st2.next = st3
    st3.next = st4

    # we want to see these names in the visualization so we will 
    #set them as the nodes' labels. We will retrieve the nodes' 
    #generic data for the label
    st0.label = st0.value
    st1.label = st1.value
    st2.label = st2.value
    st3.label = st3.value
    st4.label = st4.value

    # print the names of the students in the list using iteration

    # Using a regular for loop on BRIDGES elements
    print("\nUsing a regular while loop..\n"); 
    el = st0
    while el != None:
        print (el.value)
        el = el.next


    print("\nUsing a list iterator..\n"); 
    list_iter = SLelementIterator(st0);
    i = 0
    st = st0
    while list_iter.has_next():
        print (st.value)
        st = list_iter.next()
        i = i+1

    # tell Bridges the head of the list
    bridges.set_data_structure(st0)

    # visualize
    bridges.visualize()


if __name__ == "__main__":
    main()

