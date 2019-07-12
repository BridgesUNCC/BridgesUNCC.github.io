from bridges import *
from bridges.data_src_dependent import data_source
from bridges.graph_adj_matrix import *
import sys

def main():

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

    # set a title for the visualization
    bridges.setTitle("A Simple Graph (Adjacency Matrix) Example using IMDB Actor/Movie Data")

    actor_movie_data = getActorMovieIMDBData(1813)
    # create an adjacency Matrix based graph
    g = GraphAdjMatrix()

    # first create vertices for two actors and add the to the graph
    a1 = "Kevin_Bacon_(I)"
    a2 = "Denzel_Washington"

    g.add_vertex(a1, "")
    g.add_vertex(a2, "")

    # add and edge between the two actors (the third parameter is the edge weight)
    g.add_edge(a1, a2, 1)

    # color the two actor nodes
    g.get_vertices().get("Kevin_Bacon_(I)").get_visualizer().set_color("red")
    g.get_vertices().get("Denzel_Washington").get_visualizer().set_color("red")
    # make them a bit bigger
    g.get_vertices().get("Kevin_Bacon_(I)").get_visualizer().set_size(20)
    g.get_vertices().get("Denzel_Washington").get_visualizer().set_size(20)

    cnt1 = 0
    cnt2 = 0

    # we will find the first 15 immediate neighbors of the two actors
    # and color those links and nodes by following their adjacency Matrix
    for k in range(len(actor_movie_data)):
        # from the actor movie data, get and actor-movie pair
        a = actor_movie_data[k].get_Actor()
        m = actor_movie_data[k].get_Movie()

        if (a == "Kevin_Bacon_(I)" and cnt1 < 15):
            # add vertices for this movie and an edge for the link
            g.add_vertex(m, "")
            g.add_edge(a1, m, 1)
            g.add_edge(m, a1, 1)
            # make the movie node a bit transparent
            g.get_vertices().get(m).get_visualizer().set_opacity(0.5)
            cnt1 += 1

        elif (a == "Denzel_Washington" and cnt2 < 15):
            # add vertices for this movie and an edge for the link
            g.add_vertex(m, "")
            g.add_edge(a2, m, 1)
            g.add_edge(m, a2, 1)
            # make the movie node a bit transparent
            g.get_vertices().get(m).get_visualizer().set_opacity(0.5)
            cnt2 += 1

    # Next, we illustrate traversing the adjacency Matrix and color the movie
    # nodes adjacent to the Kevin Bacon node

    # first get the adjacency Matrix for Kevin Bacon
    bacon_row = g.get_adjacency_matrix("Kevin_Bacon_(I)")
    for entry, key in bacon_row.items():
        if(entry != "Denzel Washington" and key != 0):
            g.get_visualizer(entry).set_color("green")

    # pass the grpah object to BRIDGES
    bridges.set_data_structure(g)
    # visualize the graph
    bridges.visualize()

if __name__ == "__main__":
    main()

