from StudentInfo import *
from Bridges.Bridges import *
from Bridges.SLelement import *

class SLListtutorial:

	#note: you must fill in with your Bridges credentials
    bridges = Bridges(3, "YOUR_USER_ID", "YOUR_API_KEY")

	#create the linked list elements with student data
    e01 = SLelement(e = Student("00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				9.0), label ="")

    e02 = SLelement(e = Student("00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				11.0), label="")

    e03 = SLelement(e=Student("00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				50.0), label="")

    e04 = SLelement(e=Student("00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"green",
				"magenta",
				9.0), label="")

    e05 = SLelement(e=Student("00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"cyan",
				15.0), label="")

	# link the elements
    e01.set_next(e02)
    e02.set_next(e03)
    e03.set_next(e04)
    e04.set_next(e05)

	# iterate through the list and add visual attributes
	# to the elements; set the element color to the favorite
	# color and the link to the disliked color
    currentElement = e01
    while currentElement is not None:
		# color the node
        si = currentElement.get_value()
        currentElement.get_visualizer().set_color(si.getLikeColor())

        if currentElement.get_next() is not None:
			# color the link
            currentElement.get_link_visualizer(currentElement.get_next()).set_color(si.getDislikeColor())
            # adjust link thickness
            currentElement.get_link_visualizer(currentElement.get_next()).set_thickness(si.getCreditHours() * 0.75)

		# set the label to the student info (label created in
		#StudentInfo class
        currentElement.set_label(si.getName())

        currentElement = currentElement.get_next()

	# set the data structure to be visualized
    bridges.set_data_structure(e01)
	#visualize the data structure
    bridges.visualize()
