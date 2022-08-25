from bridges.bridges import *
from bridges.array import *
from bridges.array1d import *
import sys


def main():
    # Part 3 of this tutorial describes how to use iterators with arrays
    # We will use the same example array 


    # create the Bridges object, set credentials
    bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")


	# set  title 
    bridges.set_title("One-Dimensional Array Example")

    # set description
    bridges.set_description("Illustrates using iterators to print array elements")

    # set array dimensions, allocate array of elements
    arraySize = 10
    arr = Array1D(arraySize)

    # populate the array with squares of indicies
    for i in range(arr.size):
        arr[i].label = i*i

    # print elements of list

    # using a regular while loop
    print("Printing array elements using a regular while loop")
    k = 0
    while (k < 10):
        print(arr[k].label)
        k = k+1
    
    # using an iterator
    array_iterator = iter(arr)
    el = next(array_iterator)
    print("Printing array elements using an iterator")
    while True:
        try:
            el = next(array_iterator)
            print(el.label)
        except StopIteration:
            break 

    # use range loop
    print("Printing array elements using a range loop")
    for el in arr:
        print(el.label)

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()

if __name__ == "__main__":
    main()
