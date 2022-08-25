from bridges.bridges import *
from bridges.array import *
from bridges.array1d import *
import sys


def main():
    # This tutorial describes how to create a 1 dimensional array, populate
    # it with integer values and display them


    # create the Bridges object, set credentials
    bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")


	# set  title 
    bridges.set_title("One-Dimensional Array Example")

    # set description
    bridges.set_description("Create a 1 dimensional array with integer values and display them");

    #set array dimensions, allocate array of elements
    arraySize = 10
    arr = Array1D(arraySize)

    #populate the array with squares of indicies
    for i in range(arr.size):
        arr[i].label = i*i

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()
