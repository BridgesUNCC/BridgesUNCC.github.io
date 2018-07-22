from Bridges.Bridges import *
from Bridges.Array import *

class array2d:

    #create the Bridges object
    bridges = Bridges(1, "YOUR_USER_ID", "YOUR_API_KEY")

    # for 2D array 4x4
    num_rows = 4
    num_cols = 4
    my_array = Array(x_dim = 4, y_dim = 4)

    #populate the array
    for row in range(num_rows):
        for col in  range(num_cols):
            my_array.get_element(x=row, y=col).set_label("El " + str(row*num_cols + col))

    #color some of the elements
    my_array.get_element(x=0, y=0).get_visualizer().set_color("red")
    my_array.get_element(x=0, y=3).get_visualizer().set_color("green")
    my_array.get_element(x=3, y=0).get_visualizer().set_color("blue")
    my_array.get_element(x=3, y=3).get_visualizer().set_color("magenta")
    my_array.get_element(x=1, y=1).get_visualizer().set_color("cyan")
    my_array.get_element(x=2, y=2).get_visualizer().set_color("yellow")

    #set visualizer type
    bridges.set_data_structure(my_array)

    #visualize tha array
    bridges.visualize()
