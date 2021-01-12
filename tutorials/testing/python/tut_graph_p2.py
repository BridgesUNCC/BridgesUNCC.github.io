from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
import sys


def main():
    # This tutorial will demonstrate how to build an adjacency list based graph
    # using BRIDGES and display it.
    # References: GraphAdjList class

    # create the Bridges object, set credentials

    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set a title 
    bridges.set_title("A Simple Adjacency list based Graph Example.")

    # set  description
    bridges.set_description("Demonstrate styling graph nodes and links with visual attributes")

    # create an adjacency list based graph
    graph = GraphAdjList()

    # create some actor names to be added to the graph
    kevin_bacon = "Kevin Bacon" 
    denzel_washington = "Denzel Washington"
    morgan_freeman = "Morgan Freeman"
    tom_cruise = "Tom Cruise"
    angelina_jolie = "Angelina Jolie"
    amy_adams = "Amy Adams" 
    brad_pitt = "Brad Pitt"

    # add them to the graph
    graph.add_vertex(kevin_bacon)
    graph.add_vertex(denzel_washington)
    graph.add_vertex(morgan_freeman)
    graph.add_vertex(tom_cruise)
    graph.add_vertex(angelina_jolie)
    graph.add_vertex(amy_adams)
    graph.add_vertex(brad_pitt)

    # add edges
    graph.add_edge(kevin_bacon, denzel_washington)
    graph.add_edge(kevin_bacon, morgan_freeman)
    graph.add_edge(kevin_bacon, angelina_jolie)
    graph.add_edge(amy_adams, angelina_jolie)
    graph.add_edge(tom_cruise, amy_adams)
    graph.add_edge(angelina_jolie, brad_pitt)
    graph.add_edge(brad_pitt, denzel_washington)

    # style  the nodes
    
    # distinguish the male and female actors by color
    graph.get_vertex(kevin_bacon).color = "limegreen"
    graph.get_vertex(brad_pitt).color = "limegreen"
    graph.get_vertex(morgan_freeman).color = "limegreen"
    graph.get_vertex(denzel_washington).color = "limegreen"
    graph.get_vertex(tom_cruise).color = "limegreen"
    graph.get_vertex(angelina_jolie).color = "crimson"
    graph.get_vertex(amy_adams).color = "crimson"

    # shape
    graph.get_vertex(brad_pitt).shape = "square"
    graph.get_vertex(angelina_jolie).shape = "square"

    # opacity
    graph.get_vertex(tom_cruise).opacity = 0.3

    # style the links
    graph.get_link_visualizer(angelina_jolie, brad_pitt).color = "orange"
    graph.get_link_visualizer(angelina_jolie, brad_pitt).label = "Dated/Married"
    graph.get_link_visualizer(angelina_jolie, brad_pitt).thickness = 5.0

    # Pass the graph object to BRIDGES
    bridges.set_data_structure(graph)

    # visualize the graph
    bridges.visualize()


if __name__ == "__main__":
    main()

