from bridges.bridges import *
from bridges.data_src_dependent import *
import sys
import random

def main():
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    bridges.set_title("OpenStreet Map Data Access Example")

    # get the OsmData
    osmdata = data_source.get_osm_data("Charlotte, North Carolina", "default")

    vertices = osmdata.vertices
    edges = osmdata.edges

    print ("Number of Vertices [Charlotte]: " + str(len(vertices)))
    print ("Number of Edges [Charlotte]: " + str(len(edges)))

    print ("Position of first vertex: lat="+str(vertices[0].latitude)+
           " long="+ str(vertices[0].longitude));
    
if __name__ == '__main__':
    main()
