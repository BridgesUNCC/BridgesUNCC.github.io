from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
import sys


def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.title = "Testing map capabilities in BRIDGES with graphs"

    # create an adjacency list based graph
    g = GraphAdjList()

    # create some nodes
    for i in range(10):
       g.add_vertex("node" + str(i), "node" + str(i))

    for i in range(10):
       if i > 0: 
          g.add_edge("node" + str(i), "node" + str(i - 1))


    #visualize in SVG AlbersUSA map
    bridges.set_coord_system_type("albersusa")
    bridges.set_map_overlay(True)

    bridges.set_data_structure(g)
    bridges.visualize()


    # visualize SVG World map
    bridges.set_coord_system_type("equirectangular")
    bridges.set_map_overlay(True)
    bridges.set_title("SVG World Map")
    bridges.visualize()

    # CANVAS VERSIONS (add >100 nodes)
    for i in range(110):
        g.add_vertex("node" + str(i), "node" + str(i))
        if i > 0:
            g.add_edge("node" + str(i), "node" + str(i - 1))

    #fix a node over Charlotte, NC
    g.get_vertex("node6").set_location(-80.8431, 35.2271)
    g.get_vertex("node6").color = "red"

    # visualize Canvas AlbersUSA map
    bridges.set_coord_system_type("equirectangular")
    bridges.set_map_overlay(True)
    bridges.title = "Canvas USA Map"
    bridges.visualize()

    #fix a node over London
    g.get_vertex("node10").set_location(-0.1278, 51.5074)
    g.get_vertex("node10").color = "red"

    # visualize Canvas World map
    bridges.set_coord_system_type("equirectangular")
    bridges.set_map_overlay(True)
    bridges.title = "Canvas World Map"
    bridges.visualize()


if __name__ == "__main__":
    main()
