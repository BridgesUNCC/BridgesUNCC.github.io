from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    my_list = get_earthquake_usgs_data(1000)

    quake1 = my_list[random.randrange(len(my_list))]

    print(quake1.latit)
    print(quake1.longit)
    print(quake1.location)
    print(quake1.title)
    print(quake1.magnitude)


if __name__ == '__main__':
    main()