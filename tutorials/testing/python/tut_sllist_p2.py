from bridges.bridges import *
from bridges.sl_element import *
import sys

#
# In part 2 of this tutorial we demonstrate how we can style the nodes and links
# of the singly linked list  and displays them
#
# Reference: SLelement, Bridges classes, ElementVisualizer, LinkVisualizer, Color
#

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title, description
    bridges.set_title("A Singly Linked List Example")
    bridges.set_description("Demonstrate styling linked list nodes and links");

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


    # now we want to style the nodes and links to illustrate the visual
    # attributes that can be applied to elements and links between links
    # Elements have color, opacity, shape and opacity attributes. Links
    # have color, thickness and label attributes

    # set colors for list elements - see the Color class for supported colors
    st0.color = "red";
    st2.color = "aliceblue";
    
    # color the links - must specify a valid terminating element
    st0.get_link_visualizer(st1).color = "green"
    st3.get_link_visualizer(st4).color = "magenta"
    
    # adjust link thickness
    st2.get_link_visualizer(st3).thickness = 5.0
    
    # set node transparency
    st4.opacity = 0.5
    
    # set link labels
    st0.get_link_visualizer(st1).label = "Gretel Chaney --> Lamont Kyler";
    
    # set shape of node
    st2.shape = "square";
    st4.shape = "triangle";


    # tell Bridges the head of the list
    bridges.set_data_structure(st0)

    # visualize
    bridges.visualize()


if __name__ == "__main__":
    main()

