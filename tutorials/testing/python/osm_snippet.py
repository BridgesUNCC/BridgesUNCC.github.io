from bridges.bridges import *
from bridges.data_src_dependent import *
import sys
import random

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    bridges.set_title("OpenStreet Map Data Access Example")

    # get the OsmData
    osmdata = data_source.get_osm_data("Charlotte, North Carolina", "default")
    # Alternatively, one can use a bounding box in latitude and longitude:
    # osmdata = data_source.get_osm_data(35.28, -80.75, 35.32, -80.71, "default")

    vertices = osmdata.vertices
    edges = osmdata.edges

    print ("Number of Vertices [Charlotte]: " + str(len(vertices)))
    print ("Number of Edges [Charlotte]: " + str(len(edges)))

    print ("Position of first vertex: lat="+str(vertices[0].latitude)+
           " long="+ str(vertices[0].longitude));

    print ("Cartesian Coordinate of first vertex: "+str(vertices[0].cartesian_coord[0])+
           ", "+ str(vertices[0].cartesian_coord[1]));

    
if __name__ == "__main__":
    main()
