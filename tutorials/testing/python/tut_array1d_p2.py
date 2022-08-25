from bridges.bridges import *
from bridges.array import *
from bridges.array1d import *
import sys


def main():

    # Part 2 of this tutorial describes how to style arrays created 
    # using BRIDGES.  We will use the same array as Part 1 


    # create the Bridges object, set credentials
    bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")


	# set  title 
    bridges.set_title("One-Dimensional Array Example")

    # set description
    bridges.set_description("Demonstrate styling 1D array elements")

    #set array dimensions, allocate array of elements
    arraySize = 10
    arr = Array1D(arraySize)

    #populate the array with squares of indicies
    for i in range(arr.size):
        arr[i].label = i*i

    # style the array - only color, opacity and label are supported for arrays

    # color the elements
    arr.get_element(0).color = "red"
    arr.get_element(1).color = "green"
    arr.get_element(2).color = "blue"
    arr.get_element(3).color = "cyan"
    arr.get_element(4).color = "magenta"
    arr.get_element(5).color = "yellow"
    arr.get_element(6).color = "red"
    arr.get_element(7).color = "green"
    arr.get_element(8).color = "blue"
    arr.get_element(9).color = "black"

    # opacity
    arr.get_element(3).opacity = 0.2
    arr.get_element(9).opacity = 0.2


    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()
