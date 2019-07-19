from bridges.bridges import *
from StudentInfo import *
from bridges.circ_sl_element import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("A Circle Singly Linked List Example")
    bridges.set_description("This example shows five nodes. Each node is linked only to its child node. "
            +	"Colors are: A green node with a yellow link size 12, a blue node with a magenta link size 9, "
            +	"a magenta node with a blue link size 9, a red node with a magenta link size 11, and a yellow node with "
            +	"a red link size 15.")

    students = []

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


    head = CircSLelement(label = "", e = students[0])
    current = head

    for i in range(1, len(students)):
        current.set_next(CircSLelement(label = "", e = students[i]))

        #handle the last element
        if i is len(students)-1:
            #getting the last element
            current = current.get_next()

            # point the last element to the first element
            # so the list becomes circular
            current.set_next(head)
        # set the current element to be the next element
        current = current.get_next()

    current = head

    # add visual attributes
    for i in range(len(students)):

        current.set_label(current.get_value().getName())
        current.get_visualizer().set_color(col_name=current.get_value().getLikeColor())

        current.get_link_visualizer(current.get_next()).set_color(col_name=current.get_value().getDislikeColor())

        current.get_link_visualizer(current.get_next()).set_thickness(current.get_value().getCreditHours() *.03)

        current = current.get_next()

    bridges.set_data_structure(head)
    bridges.visualize()

if __name__ == "__main__":
    main()

