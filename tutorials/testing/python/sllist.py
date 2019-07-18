from StudentInfo import *
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

    # create the linked list elements with student data

    e01 = SLelement(e=Student("00000000000",
                          "Gretel Chaney",
                          "CS",
                          "g.chaney@generated.com",
                          "magenta",
                          "blue",
                          9.0), label="")

    e02 = SLelement(e=Student("00000000001",
                          "Karol Soderman",
                          "SIS",
                          "k.soderman@generated.com",
                          "magenta",
                          "red",
                          11.0), label="")

    e03 = SLelement(e=Student("00000000002",
                          "Lamont Kyler",
                          "BIO",
                          "l.kyler@generated.com",
                          "yellow",
                          "green",
                          50.0), label="")

    e04 = SLelement(e=Student("00000000003",
                          "Gladys Serino",
                          "CS",
                          "g.serino@generated.com",
                          "green",
                          "magenta",
                          9.0), label="")

    e05 = SLelement(e=Student("00000000004",
                          "Starr Mcginn",
                          "CS",
                          "s.mcginn@generated.com",
                          "red",
                          "cyan",
                          15.0), label="")

    # link the elements
    e01.set_next(e02)
    e02.set_next(e03)
    e03.set_next(e04)
    e04.set_next(e05)

    # iterate through the list and add visual attributes
    # to the elements; set the element color to the favorite
    # color and the link to the disliked color
    currentElement = e01
    while currentElement is not None:
        # color the node
        si = currentElement.get_value()
        currentElement.get_visualizer().set_color(col_name=si.getLikeColor())

        if currentElement.get_next() is not None:
            # color the link
            currentElement.get_link_visualizer(currentElement.get_next()).set_color(col_name=si.getDislikeColor())
            # adjust link thickness
            currentElement.get_link_visualizer(currentElement.get_next()).set_thickness(si.getCreditHours() * 0.75)

        # set the label to the student info (label created in
        # StudentInfo class
        currentElement.set_label(si.getName())

        currentElement = currentElement.get_next()

    # set the data structure to be visualized
    bridges.set_data_structure(e01)
    # visualize the data structure
    bridges.visualize()

if __name__ == "__main__":
    main()

