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

    my_list = get_game_data()

    game1 = my_list[random.randrange(len(my_list))]

    print(game1.title)
    print(game1.platform)
    print(game1.rating)
    print(game1.genre)



if __name__ == '__main__':
    main()