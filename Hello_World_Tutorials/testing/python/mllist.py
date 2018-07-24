from Bridges.Bridges import *
from Bridges.MLelement import *

class MLtutorial:

    # create the bridges object
    bridges = Bridges(7, "YOUR_USER_ID", "YOUR_API_KEY")

    # create multi linked list
    el0 = MLelement("0", "0")
    el1 = MLelement("1", "1")
    el2 = MLelement("2", "2")
    el3 = MLelement("3", "3")
    el4 = MLelement("4", "4")

    #create the links
    el0.set_next(el1)
    el1.set_next(el2)
    el2.set_next(el3)
    el3.set_next(el4)

    # create the sublist from 2
    el5 = MLelement("5", "5")
    el6 = MLelement("6", "6")
    el7 = MLelement("7", "7")

    el5.set_next(el6)
    el6.set_next(el7)
    el2.set_sub_list(el5)

    el8 = MLelement("8", "8")
    el9 = MLelement("9", "9")

    #create second sublist
    el8.set_next(el9)
    el3.set_sub_list(el8)

    el10 = MLelement("10", "10")
    el11 = MLelement("11", "11")

    #create 3rd sublist
    el10.set_next(el11)
    el6.set_sub_list(el10)

    el0.get_visualizer().set_size(40)
    el0.get_link_visualizer(el1).set_color("red")
    el0.get_link_visualizer(el1).set_thickness(3)
    el1.get_link_visualizer(el2).set_color("blue")
    el1.get_link_visualizer(el2).set_thickness(3)
    el2.get_link_visualizer(el3).set_color("cyan")
    el2.get_link_visualizer(el3).set_thickness(3)

    # set visualizer type
    bridges.set_data_structure(el0)
    #visualize the multi linked list
    bridges.visualize()
