from bridges.bridges import *
from bridges.array import *
from bridges.array1d import *
import sys


def main():

    # create the Bridges object, set credentials
    bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")


	# Bridges title, description
    bridges.set_title("One-Dimensional Array Example")
    bridges.set_description("Illustrates a one dimensional array with visual attributes")

    #set array dimensions, allocate array of elements
    arraySize = 10
    arr = Array1D(arraySize)

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

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()
