from bridges.bridges import *
import sys
from bridges.data_src_dependent import data_source

#how to use the USCities Dataset
def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")


    #-the function can take 6 parameters
    #-ommiting all parameters will return all results in db
    #-these parameters can be used in any combination to filter results further
    
    #int: limit - which is to limit the number of results returned
    #str: state - get only results with this state. the state must be the Acronym ex: NC, NV, CA...etc
    #int: min_elevation - get only results with elevation greater than this number
    #int: max_elevation - get only results with elevation lesser than this number
    #int: min_pop - get only results with populationg greater than this number
    #int: max_pop - get only results with populationg lesser than this number

    #double: min_lat - get cities with latitude greater than this number
    #double: max_lat - get cities with latitude smaller than this number
    #double: min_long - get cities with longitude greater than this number
    #double: max_long - get cities with longitude smaller than this number
    
    # omitting all arguments will get all data within the database
    # cities_data = data_source.get_us_cities_data()

    #getting a limit of 5 results
    # cities_data = data_source.get_us_cities_data(limit = '5')

    #getting only results from NC
    # cities_data = data_source.get_us_cities_data(state = 'NC')

    #getting only results with elevation greater than 100
    # cities_data = data_source.get_us_cities_data(elevation = '100')

    #getting only results with population greater than 2000
    # cities_data = data_source.get_us_cities_data(population = '2000')

    #getting only results within a NC bounding box
    #cities_data = data_source.get_us_cities_data(minll = '[34.025348,-85.352783]', maxll = '[36.800488,-75.300293]')

    #cities_data = data_source.get_us_cities_data(limit = 10, min_pop=2000000)

    #combining all parameters

    cities_data = data_source.get_us_cities_data(limit = 25, state = 'NC', min_elev= -100, min_pop =  200000, max_pop = 1000000, min_lat = 34.025348, min_long = -85.352783, max_lat = 36.800488, max_long = -75.300293)

    for c in cities_data:
       print(c.city + ", " + c.state + ": population: " + str(c.population) + ", " + "elevation: " + str(c.elevation) + ", lat/long: " + str(c.lat) + "," + str(c.lon))

    print ("\nCities with negative elevation..\n");

    cities_data2 = data_source.get_us_cities_data(limit='25', min_elev='-100', max_elev='0')
    for c in cities_data2:
       print(c.city + ", " + c.state + ": population: " + str(c.population) + ", " + "elevation: " + str(c.elevation) + ", lat/long: " + str(c.lat) + "," + str(c.lon))


if __name__ == "__main__":
    main()
