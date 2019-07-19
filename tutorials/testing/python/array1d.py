import sys
print(sys.path)

from bridges.bridges import *
from bridges.array import *

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #Title and Description
    bridges.set_title("One-Dimensional Array Example")
    bridges.set_description("OneD array with colors in order left to right: "
            +	"red, green, blue, cyan, magenta, yellow, red, green, blue, black.")

    #set array dimensions, allocate array fo elements
    arraySize = 10

    arr = Array(num_elements = arraySize)

    #populate the array with squares of indicies
    for i in range(arr.size):
        arr[i].label = i*i

    #color the array elements
    arr[0].set_color("red")
    arr[1].set_color("green")
    arr[2].set_color("blue")
    arr[3].set_color("cyan")
    arr[4].set_color("magenta")
    arr[5].set_color("yellow")
    arr[6].set_color("red")
    arr[7].set_color("green")
    arr[8].set_color("blue")
    arr[9].set_color("black")

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()

