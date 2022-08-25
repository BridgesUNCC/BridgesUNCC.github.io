from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # get 100 earthquake records
    my_list = get_earthquake_usgs_data(100)

    # pick the first one 
    quake1 = my_list[0]

    # print details of quake
    print("Magnitude: " + str(quake1.magnitude))
    print("Date: " + str(quake1.time))
    print("Location:" + str(quake1.location))
    print("Lat/Long:" + str(quake1.latit) + "," + str(quake1.longit))


if __name__ == "__main__":
    main()
