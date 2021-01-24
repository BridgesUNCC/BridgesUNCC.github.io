from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
import sys


def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("Open Street Map Test")

    # create an adjacency list based graph
    osm_data = data_source.get_osm_data("Charlotte, North Carolina", "default")
    # Alternatively, one can use a bounding box in latitude and longitude
    # osm_data = data_source.get_osm_data(35.28, -80.75, 35.32, -80.71, "default")
    

    print ("Number of Vertices [Charlotte]: " + str(len(osm_data.vertices)))
    print ("Number of Edges [Charlotte]: " + str(len(osm_data.edges)))

    # get the graph of this dataset
    g = osm_data.get_graph()

    g.force_large_visualization(True)

    # Pass the graph object to BRIDGES
    bridges.set_data_structure(g)
    # visualize the graph
    bridges.visualize()


if __name__ == "__main__":
    main()

