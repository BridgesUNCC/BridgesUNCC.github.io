from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
from bridges.data_src_dependent import data_source
import sys
import os

def main():

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")


    ele_obj = data_source.get_elevation_data([-98.02593749997456, 41.03133177632377, -96.94531249997696, 42.508577297430456])
    print("Width: " +str(ele_obj.cols))
    print("Height: "+ str(ele_obj.rows))
    print(ele_obj._xll)
    print(ele_obj._yll)
    print("Resolution: "+str(ele_obj.cellsize))
    print(ele_obj.data)

    

if __name__ == "__main__":
    main()