from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # get imdb actor movie data
    my_list = get_actor_movie_imdb_data()

    # get an example pair of the data
    pair1 = my_list[random.randrange(len(my_list))]

    # print the actor and movie
    print(pair1.actor)
    print(pair1.movie)

if __name__ == "__main__":
    main()
