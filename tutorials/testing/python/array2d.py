from bridges.bridges import *
from bridges.array import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("Two-Dimensional Array Example")
    bridges.set_description("A TwoD array with four rows and four columns. "
                        + "Row one left to right: red, neutral, neutral, blue. "
                        + "Row two left to right: neutral, cyan, neutral, neutral. "
                        + "Row three left to right: neutral, neutral, yellow, neutral. "
                        + "Row four left to right: green, neutral, neutral, magenta.")


    # for 2D array 4x4
    num_rows = 4
    num_cols = 4
    my_array = Array(x_dim = 4, y_dim = 4)

    #populate the array
    for row in range(num_rows):
        for col in  range(num_cols):
            my_array[row, col].set_label("El " + str(row*num_cols + col))

    #color some of the elements
    my_array[0, 0].set_color("red")
    my_array[0, 3].set_color("green")
    my_array[3, 0].set_color("blue")
    my_array[3, 3].set_color("magenta")
    my_array[1, 1].set_color("cyan")
    my_array[2, 2].set_color("yellow")

    #set visualizer type
    bridges.set_data_structure(my_array)

    #visualize tha array
    bridges.visualize()

if __name__ == "__main__":
    main()

