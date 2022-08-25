from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # get the IGN game dataset
    my_list = get_game_data()

    # retrieve a random game object
    game1 = my_list[random.randrange(len(my_list))]

    # print details of the game to console
    print(game1.title)
    print(game1.platform)
    print(game1.rating)
    print(game1.genre)


if __name__ == "__main__":
    main()
