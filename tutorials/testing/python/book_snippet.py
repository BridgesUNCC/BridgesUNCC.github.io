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

        book_list = get_gutenberg_book_data()

        book1 = book_list[random.randrange(len(book_list))]

        print(book1.title)
        print(book1.name)
        print(book1.genre)

    if __name__ == '__main__':
        main()