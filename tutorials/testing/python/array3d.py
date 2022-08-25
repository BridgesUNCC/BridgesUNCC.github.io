from bridges.bridges import *
from bridges.array import *
from bridges.array3d import *
import sys

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")


    # Bridges title, description
    bridges.set_title("Three-Dimensional Array Example")
    bridges.set_description("A 3 dimensional array with visual attributes. The third dimension is illustrated as a sequence of 2D slices")

    # specify array dimensions and create 3D array
    num_slices = 4
    num_rows = 4
    num_cols = 4

    my_array = Array3D(slices=num_slices, rows=num_rows, cols=num_cols)

    # populate the elements with their array postition
    n = 0
    for k in range(num_slices):
        for j in range(num_rows):
            for i in range(num_cols):
                my_array[k, j, i].label = "El " + str(n)
                n += 1



    # color some of the elements
    my_array[0, 0, 0].visualizer.color = "red"
    my_array[0, 3, 0].visualizer.color = "green"
    my_array[1, 1, 0].visualizer.color = "cyan"
    my_array[2, 2, 0].visualizer.color = "yellow"
    my_array[3, 0, 0].visualizer.color = "blue"
    my_array[3, 3, 3].visualizer.color = "magenta"

    # set visualizer type
    bridges.set_data_structure(my_array)

    # visualize the list
    bridges.visualize()


if __name__ == "__main__":
    main()

