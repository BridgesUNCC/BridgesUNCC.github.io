from bridges.bridges import *
from bridges.data_src_dependent import *
import sys
import random

def main():
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    bridges.set_title("Amenity Data Access Example")

    print ("Retrieving all schools in Charlotte, North Carolina")
    
    # get the OsmData
    amenitydata = data_source.get_amenity_data("Charlotte, North Carolina", "school")
    # Alternately, one can use a bounding box expressed with latitude and longitude
    # There are other types than "school" available. Check documentation for details.
    #amenitydata = data_source.get_amenity_data(35.28, -80.75, 35.32, -80.71, "food")
    

    
    meta = amenitydata.meta
    
    print ("Number of amenities: " + str(meta.count))
    
    print ("Position of first amenity: lat="+str(amenitydata.data[0].lat)+
           " long="+ str(amenitydata.data[0].lon)+" name="+str(amenitydata.data[0].name)+
           " id=" + str(amenitydata.data[0].id) + " other="+str(amenitydata.data[0].other))

    #print ("Cartesian Coordinate of first vertex: "+str(vertices[0].cartesian_coord[0])+ ", "+ str(vertices[0].cartesian_coord[1]))

    
if __name__ == '__main__':
    main()
