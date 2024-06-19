from bridges import *

def main():
    bridges = Bridges(1, "BRIDGES_USER_NAME", "BRIDGES_API_KEY")

    bridges.set_title("UNCC BRIDGES Workshop:IMDB Actor-Movie Data")
    bridges.set_description("Building a graph from IMDB actor movie pairs")

    graph = GraphAdjList()

    # retrieve the IMDB actor movie data (returns a list of type
    # ActorMovieIMDB
    actor_list = get_actor_movie_imdb_data(1814)
    
	# TODO: You will build a graph that takes the actor-movie list (of 
	# type ActorMoviIMDB) and build a graph that connects each actor to
	# the corresponding movie and also the movie to the actor.
	# Check the graph tutorial at 
	# http://bridgesuncc.github.io/tutorials/Graph.html
	# and the related class documentation at
	# http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1graph__adj__list_1_1_graph_adj_list.html
    # http://bridgesuncc.github.io/doc/python-api/current/html/classbridges_1_1data__src__dependent_1_1actor__movie__imdb_1_1_actor_movie_i_m_d_b.html
	# for additional information
	
	# Note: The actors and movies will occur multiple times. So before you 
	# create a new movie or actor node, you must check if it has already 
	# been created. You can use the getVertex() method to check to see if
	# if an actor or movie exists in the graph (will return nullptr otherwise)
	

	# Graph has been created, give it to BRIDGES and visualize
	# bridges.setDataStructure(&graph);
	# bridges.visualize();
    # bridges.set_data_structure(graph)
    # bridges.visualize()

if __name__ == '__main__':
    main()
