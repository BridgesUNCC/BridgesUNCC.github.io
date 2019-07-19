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

    song = get_song("Delicate")

    print(song.get_artist())
    print(song.get_album_title())
    print(song.get_release_date())
    print(song.get_lyrics()[0:min(100, len(song.get_lyrics()))])


if __name__ == '__main__':
    main()