from bridges.bridges import *
from bridges.array import *
import sys


def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])
    #set array dimensions, allocate array fo elements
    arraySize = 10

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    bridges.set_title("One-Dimensional Array Example")
    bridges.set_description("OneD array with colors in order left to right: "
                            + "red, green, blue, cyan, magenta, yellow, red, green, blue, black.")

    arr = Array(num_elements=arraySize)

    #populate the array with squares of indicies
    for i in range(arr.size):
        arr[i].label = i*i

    #color the array elements
    arr[0].visualizer.color = "red"
    arr[1].visualizer.color = "green"
    arr[2].visualizer.color = "blue"
    arr[3].visualizer.color = "cyan"
    arr[4].visualizer.color = "magenta"
    arr[5].visualizer.color = "yellow"
    arr[6].visualizer.color = "red"
    arr[7].visualizer.color = "green"
    arr[8].visualizer.color = "blue"
    arr[9].visualizer.color = "black"

    arr[5].color = "white"

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()