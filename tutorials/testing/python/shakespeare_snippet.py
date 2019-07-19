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

    my_list = get_shakespeare_data()

    work1 = my_list[random.randrange(len(my_list))]

    print(work1.get_title())
    print(work1.get_type())
    print(work1.get_text()[0:min(100, len(work1.get_text()))])


if __name__ == '__main__':
    main()