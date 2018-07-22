from Bridges.DLelement import *
from Bridges.Bridges import *
from StudentInfo import *


def insertFront(front, new_el):
    if front is None:
        return new_el

    new_el.set_next(front)
    front.set_prev(new_el)

    return new_el

class DLListtutorial:
    #create a bridges object with your credentials
    bridges = Bridges(4, "YOUR_USER_ID", "YOUR_API_KEY")

    students = []

    # load student info
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

    # insert the students in front of the list
    head = None
    for i in range(len(students)):
        head = insertFront(head, DLelement(label = "", e = students[i]))

    # add visual attributes
    curr = head
    while curr is not None:
        curr.set_label(curr.get_value().getName())
        curr.get_visualizer().set_color(curr.get_value().getDislikeColor())

        if curr.get_next()is not None:
            next = curr.get_next()
            curr.get_link_visualizer(next).set_color(curr.get_value().getDislikeColor())
            next.get_link_visualizer(curr).set_color(curr.get_value().getDislikeColor())

        curr = curr.get_next()


    # set dat structure to be visualized
    bridges.set_data_structure(head)
    # visualize the data structure
    bridges.visualize()
