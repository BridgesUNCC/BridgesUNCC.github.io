from bridges.symbol_collection import *
from bridges.bridges import *
from bridges.circle import *
from bridges.polygon import *
from bridges.rectangle import *
from bridges.text import *
from bridges.color import *
from bridges.text import *
import sys

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("Symbol Collection")
    bridges.set_description("Red square, green circle, magenta horizontal and vertical lines, "
            +	"and a test label with a purple outline.")

    sc = SymbolCollection()

    # draw a rectangle
    s1 = Rectangle(w=25, h=25, locx=-50.0, locy=0.0)
    s1.fill_color = "red"
    s1.opacity = 0.5 
    sc.add_symbol(s1)

    # draw another rectangle
    s2 = Rectangle(w=25, h=25, locx=50.0, locy=0.0)
    s2.fill_color = "orange"
    s2.opacity = 0.8 
    sc.add_symbol(s2)

    # draw a circle
    s3 = Circle(locx=50.0, locy=50.0, r=15)
    s3.fill_color = "green"
    s3.opacity = 1.0 
    sc.add_symbol(s3)

    # draw a triangle
    s4 = Polygon()
    s4.add_point(-25, -10)
    s4.add_point(25, -10)
    s4.add_point(0.0, 50.0)
    s4.stroke_color = "darkorchid"
    s4.stroke_width = 2.0
    sc.add_symbol(s4)

    # draw X axis
    s5 = Polyline()
    s5.add_point(-100, 0)
    s5.add_point(100, 0)
    s5.stroke_color = "magenta"
    s5.stroke_width = 2.0
    s5.opacity = 1.0
    sc.add_symbol(s5)

    # draw Y axis
    s6 = Polyline()
    s6.add_point(0.0, -100.0)
    s6.add_point(0.0, 100.0)
    s6.stroke_color = "magenta"
    s6.stroke_width = 2.0
    s6.opacity = 1.0
    sc.add_symbol(s6)


    l = Text()
    l.set_anchor_location(0.0, 25.0)
    l.font_size = 18.0
    l.stroke_width = 2.0
    l.text = "test label1"
    l.opacity = 0.5
    l.stroke_color = "purple"
    sc.add_symbol(l)

    bridges.set_data_structure(sc)
    bridges.visualize()


if __name__ == "__main__":
    main()
