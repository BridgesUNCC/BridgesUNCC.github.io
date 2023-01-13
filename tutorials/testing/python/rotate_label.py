from bridges.symbol_collection import *
from bridges.bridges import *
from bridges.circle import *
from bridges.polygon import *
from bridges.rectangle import *
from bridges.label import *
from bridges.color import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    bridges.connector.set_server("clone")

    # title, description
    bridges.set_title("Label Test")

    sc = SymbolCollection()

    l = Label()
    l.set_location(-20, 50)
    l.font_size =  8.
    l.stroke_width = 0.1
    l.label = "abcdljjjlllmmmm"
    l.stroke_color = "purple"
    l.rotation_angle = -45.
    sc.add_symbol(l)

    bbox = l.get_bounding_box()

    # draw a rectangle
    r1 = Rectangle(locx=bbox[0], locy=bbox[1], w = bbox[2]-bbox[0], h = bbox[3]-bbox[1])
    r1.fill_color = "red"
    r1.opacity = 0.2
    sc.add_symbol(r1)


    l2 = Label()
    l2.set_location(20, 50)
    l2.font_size =  18.
    l2.label = "ABCDLJJJIIILLLMMMM"
    l2.stroke_width = 0.1
    l2.stroke_color = "purple"
    l2.rotation_angle = 25.
    sc.add_symbol(l2)
    bbox = l2.get_bounding_box()

    r2 = Rectangle(locx=bbox[0], locy=bbox[1], w = bbox[2]-bbox[0], h = bbox[3]-bbox[1])
    r2.fill_color = "red"
    r2.opacity = 0.2
    sc.add_symbol(r2)

    bridges.set_data_structure(sc)
    bridges.visualize()


if __name__ == "__main__":
    main()
