from bridges.bridges import *
from bridges.array import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

    #speify array dimensions and create 3D array
    num_slices = 4
    num_rows = 4
    num_cols = 4

    my_array = Array(x_dim=num_slices, y_dim = num_rows, z_dim= num_cols)

    #populate the elements with their array postition
    n = 0
    for k in range(num_slices):
        for j in range(num_rows):
            for i in range(num_cols):
                my_array.get_element(x=i, y=j, z=k).set_label("El " + str(n))
                n += n

    #color some of the elements
    my_array.get_element(x=0, y=0, z=0).get_visualizer().set_color("red")
    my_array.get_element(x=0, y=3, z=0).get_visualizer().set_color("green")
    my_array.get_element(x=3, y=0, z=0).get_visualizer().set_color("blue")
    my_array.get_element(x=3, y=3, z=0).get_visualizer().set_color("magenta")
    my_array.get_element(x=1, y=1, z=0).get_visualizer().set_color("cyan")
    my_array.get_element(x=2, y=2, z=0).get_visualizer().set_color("yellow")

    #set visualizer type
    bridges.set_data_structure(my_array)

    #visualize the list
    bridges.visualize()


if __name__ == "__main__":
    main()

