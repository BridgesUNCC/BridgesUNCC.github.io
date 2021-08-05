from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # get 100 earthquake records
    my_list = get_earthquake_usgs_data(100)

    # pick one at random
    quake1 = my_list[random.randrange(len(my_list))]

    # print details of quake
    print(quake1.latit)
    print(quake1.longit)
    print(quake1.location)
    print(quake1.title)
    print(quake1.magnitude)
    print(quake1.time)


if __name__ == '__main__':
    main()
