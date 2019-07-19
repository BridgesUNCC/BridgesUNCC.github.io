from bridges.bridges import *
from bridges.circ_dl_element import *
from StudentInfo import *
import sys

#helper funtction
def insertFront(tailElement, newElement):
    tailNextElement = tailElement.get_next()

    newElement.set_next(tailNextElement)
    newElement.set_prev(tailElement)

    tailNextElement.set_prev(newElement)
    tailElement.set_next(newElement)

    return tailElement


def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Circular Doubly Linked List Example")
    bridges.set_description("This example shows five nodes each linked to their parent and child node. "
            +	"Colors are: Magenta node with blue links size 9, Red node with magenta links size 11, blue node with magenta links size 9, "
            +	"yellow node with red links size 15, and green node with yellow links size 12.")

    students = []

    # create a list of student data
    students.append(Student("00000000000",
                            "Gretel Chaney",
                            "CS",
                            "g.chaney@generated.com",
                            "magenta",
                            "blue",
                            9.0))

    students.append(Student("00000000001",
                            "Karol Soderman",
                            "SIS",
                            "k.soderman@generated.com",
                            "magenta",
                            "red",
                            11.0))

    students.append(Student("00000000002",
                            "Lamont Kyler",
                            "BIO",
                            "l.kyler@generated.com",
                            "yellow",
                            "green",
                            50.0))

    students.append(Student("00000000003",
                            "Gladys Serino",
                            "CS",
                            "g.serino@generated.com",
                            "green",
                            "magenta",
                            9.0))

    students.append(Student("00000000004",
                            "Starr Mcginn",
                            "CS",
                            "s.mcginn@generated.com",
                            "red",
                            "cyan",
                            15.0))

    head = None

    # init all student elements
    for i in range(len(students)):
        if i > 0:
            head = insertFront(head, CircDLelement(label = "", e = students[i]))
        else:
            head = CircDLelement(label = "", e = students[i])

    current = head

    # add visual attributes
    for i in range(len(students)):
        current.set_label(current.get_value().getName())
        current.get_visualizer().set_color(col_name=current.get_value().getLikeColor())

        current.get_link_visualizer(current.get_next()).set_color(col_name=current.get_value().getDislikeColor())
        current.get_link_visualizer(current.get_next()).set_thickness(current.get_value().getCreditHours()*.2)

        current.get_link_visualizer(current.get_prev()).set_color(col_name=current.get_value().getDislikeColor())
        current.get_link_visualizer(current.get_prev()).set_thickness(current.get_value().getCreditHours()*.2)

        current = current.get_next()

    # set data structure to point to head
    bridges.set_data_structure(head)
    # visualize the circular list
    bridges.visualize()

if __name__ == "__main__":
    main()

