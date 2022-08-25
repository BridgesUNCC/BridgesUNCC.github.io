from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")


    # get the shakespeare data
    my_list = get_shakespeare_data()

    # pick a work at random
    work1 = my_list[random.randrange(len(my_list))]

    # print to console
    print(work1.title)
    print(work1.type)
    print(work1.text[0:min(100, len(work1.text))])


if __name__ == "__main__":
    main()
