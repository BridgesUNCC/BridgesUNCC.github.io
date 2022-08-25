from bridges.bridges import *
from bridges.data_src_dependent import *
import sys
import random

def main():
    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    bridges.set_title("Amenity Data Access Example")

    print ("Retrieving all schools in Charlotte, North Carolina")
    
    # get the OsmData
    amenities = data_source.get_amenity_data("Charlotte, North Carolina", "school")
    # Alternately, one can use a bounding box expressed with latitude and longitude
    # There are other types than "school" available. Check documentation for details.
    #amenitydata = data_source.get_amenity_data(35.28, -80.75, 35.32, -80.71, "food")
    

    
    print ("Number of amenities: " + str(len(amenities)))

    for i in range(5):
    	print ("\nAmenity " + str(i) + ": " + " Lat="+str(amenities[i].lat) +
           " Long="+ str(amenities[i].lon)+" Name="+str(amenities[i].name)+
           " Id=" + str(amenities[i].id) + " Other="+str(amenities[i].other))

    #print ("Cartesian Coordinate of first vertex: "+str(vertices[0].cartesian_coord[0])+ ", "+ str(vertices[0].cartesian_coord[1]))

    
if __name__ == "__main__":
    main()
