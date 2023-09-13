from bridges import *

def main():
    bridges = Bridges(1, "BRIDGES_USER_NAME", "BRIDGES_API_KEY")

    bridges.set_title("UNCC BRIDGES Workshop Number: IMDB Actor-Movie Data")
    bridges.set_description("Building a graph from IMDB actor movie pairs")

    graph = GraphAdjList()

    # retrieve the IMDB actor movie data
    actor_list = get_actor_movie_imdb_data(1814)
    
    # Traverse the list and populate the graph with actors and movies
    for m in range(len(actor_list)):
        actor = actor_list[m].actor
        movie = actor_list[m].movie

        # Add vertices for unique actor/movies
        if graph.get_vertex(actor) == None:
            graph.add_vertex(actor, None)

        if graph.get_vertex(movie) == None:
            graph.add_vertex(movie, None)

        # Add edge between this actor and movie both ways
        graph.add_edge(movie, actor)
        graph.add_edge(actor, movie)

        # If the actors are the target actors highlight the links and vertices
        if actor == 'Cate_Blanchett':
            graph.get_link_visualizer(actor, movie).color = "red"
            graph.get_visualizer(actor).color = "red"
            graph.get_visualizer(actor).size = 49.0 
            graph.get_visualizer(movie).color = "red"
        elif actor == 'Kevin_Bacon_(I)':
            graph.get_link_visualizer(actor, movie).color = "green"
            graph.get_visualizer(actor).size = 49.0 
            graph.get_visualizer(actor).color = "green"
            graph.get_visualizer(movie).color = "green"

    bridges.set_data_structure(graph)
    bridges.visualize()

if __name__ == '__main__':
    main()
