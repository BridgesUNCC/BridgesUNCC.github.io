from bridges.bridges import *
import sys
from bridges.data_src_dependent import data_source

#how to use the USCities Dataset
def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    # getting cities in North Carolina with populatino range or 200K-1M, limit to 25 cities
	# other parameters include elevation range, lat/long range
    cities_data = data_source.get_us_cities_data(state = 'NC', min_pop =  200000, max_pop = 10000000, limit =25)
    for c in cities_data:
       print(c.city + ", " + c.state + ": population: " + str(c.population) + ", " + "elevation: " + str(c.elevation) + ", lat/long: " + str(c.lat) + "," + str(c.lon))


if __name__ == "__main__":
    main()
