from bridges.bridges import *
from bridges.circ_dl_element import *
from python.web_tutorial.StudentInfo import *
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
    bridges = Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

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
        current.get_visualizer().set_color(current.get_value().getLikeColor())

        current.get_link_visualizer(current.get_next()).set_color(current.get_value().getDislikeColor())
        current.get_link_visualizer(current.get_next()).set_thickness(current.get_value().getCreditHours()*.2)

        current.get_link_visualizer(current.get_prev()).set_color(current.get_value().getDislikeColor())
        current.get_link_visualizer(current.get_prev()).set_thickness(current.get_value().getCreditHours()*.2)

        current = current.get_next()

    # set data structure to point to head
    bridges.set_data_structure(head)
    # visualize the circular list
    bridges.visualize()

if __name__ == "__main__":
    main()

