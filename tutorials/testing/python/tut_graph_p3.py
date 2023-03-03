from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
import sys


def main():
    # In Part 3 of this tutorial will demonstrate some advanced features 
    # of adjacency list  based graphs in BRIDGES, such as graph traversal 
    # and iterators that make it more convenient.
    # 
    # We will continue using the same graph of actors
    # 
    # References: GraphAdjList class
    #
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set a title 
    bridges.set_title("A Simple Adjacency list based Graph Example.")

    # set  description
    bridges.set_description("Demonstrate advanced features of graphs, traversal of adjacency lists, use of iterators")

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

    # Next, we illustrate traversing the adacency list  in different ways

    # using core BRIDGES classes to print movies that Kevin Bacon is  adjacent to
    print("Using core Bridges classes to print movies that Kevin Bacon is adjacent to\n")
    sle = graph.get_adjacency_list(kevin_bacon)
    while sle != None:
        edge = sle.value;
        print(edge.fromv + " --> " + sle.value.tov)
        sle = sle.next

    # using iterators to print the movies that Kevin Bacon is adjacent to
    print("\nUsing iterator to print the movies that Kevin Bacon is adjacent to\n")
    for edge in graph.out_going_edge_set_of(kevin_bacon):
        print(edge.fromv + "--->" + edge.tov)

    # finally, list the vertices of the graph, using iterators
    print("\nUsing iterator to print the graph vertices..")
    for key in graph.key_set():
        print("\t"  + key)


    # Pass the graph object to BRIDGES
    bridges.set_data_structure(graph)

    # visualize the graph
    bridges.visualize()


if __name__ == "__main__":
    main()

