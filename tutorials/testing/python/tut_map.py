from bridges import *

def main():

    # create the Bridges object, set credentials
        bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")

    #Set the projection to equirectangular. Currently for using the World map
    #Only equirectangular is supported
    bridges.set_coord_system_type("equirectangular")
    bridges.set_map_overlay(True)
    #Here we set the properties of the map. The first element is the map we are using,
    #The second is what part of the map we want. Here we get all countries.
    bridges.map = ["world", "all"]

    #here we create a symbol collection structure. This data structure will be
    #displayed over the map with cities drawn as circles in their lat long location.
    sc = SymbolCollection()

    #First we get cities with a population greater than 500,000
    cities  = get_us_cities_data(min_pop=500000)

    #for each of these cities we create a circle with the cities lat long and its position and add it to the symbol collection
    for i in range(len(cities)):
        s3 = Circle(locx=cities[i].lon, locy=cities[i].lat, r=0.5)
        s3.fill_color = "green"
        s3.opacity = 1.0
        sc.add_symbol(s3)

    #visualize the structure
    bridges.set_data_structure(sc)
    bridges.visualize()


    #now we set the world map to just show the US.
    bridges.map = ["world", "united states of america"]

    bridges.set_data_structure(sc)
    bridges.visualize()

    #We can also set the map the to a more detailed version if the US.
    #The map only supports albersusa as a projection type
    bridges.set_coord_system_type("albersusa")
    #Here we set the first element to show the US map and the second to show all states.
    bridges.map = ["us", "all"]

    bridges.set_data_structure(sc)
    bridges.visualize()

    #Changing the second element we can choose which state of the US to visualize
    #Here we visualize north carolina
    bridges.map = ["us", "north carolina"]


    bridges.set_data_structure(sc)
    bridges.visualize()

if __name__ == "__main__":
    main()
