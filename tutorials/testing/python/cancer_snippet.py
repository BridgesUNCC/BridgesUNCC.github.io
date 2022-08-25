from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
from bridges.data_src_dependent.cancer_incidence import *
import sys
import random

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    bridges.title = "Accessing Cancer Data"

    # get cancer incidence data
    my_list = get_cancer_incident_data()

    # get an example pair of the data
    pair1 = my_list[random.randrange(len(my_list))]

    # print the first record
    print("Record 1:")
    c = my_list[0]
 
    print("\tType: " + c.get_event_type() + "\n"
             + "\tYear: " + str(c.get_year()) + "\n"
             + "\tPopulation: " + str(c.get_population()) + "\n"
             + "\tRace: " + c.get_race() + "\n"
             + "\tGender: " + c.get_gender() + "\n"
             + "\tCrudeRate: " + str(c.get_crude_rate()) + "(more rate information available) \n"
             + "\tLocation: " + str(c.get_location_x()) + ", "+ str(c.get_location_y()) + "\n"
             + "\tCount: " + str(c.get_count()));


if __name__ == "__main__":
    main()
