from Bridges import *
from Array import *
from Element import *


class Array1d():

    bridges = Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY")

    arraySize = 10

    arr = Array(num_elements = arraySize)

    for i in range(arr.get_size()):
        arr.get_element(i).set_label(i*i)

    arr.get_element(0).get_visualizer().set_color("red")
    arr.get_element(8).get_visualizer().set_color("green")

    bridges.set_data_structure(arr)
    bridges.visualize()
