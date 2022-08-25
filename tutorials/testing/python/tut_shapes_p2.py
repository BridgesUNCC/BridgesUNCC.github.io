from bridges.symbol_collection import *
from bridges.bridges import *
from bridges.circle import *
from bridges.polygon import *
from bridges.rectangle import *
from bridges.text import *
from bridges.color import *
from bridges.symbol_group import *
import sys

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("Symbol Collection: Groups")
    bridges.set_description("Illustrates using two groups of symbols, transformedat the group level.")

    # draw a rectangle
    sc = SymbolCollection()
    s1 = Rectangle(w=25, h=25, locx=-50.0, locy=0.0)
    s1.fill_color = "red"
    s1.opacity = 0.3

    # draw a rectangle
    sc = SymbolCollection()
    s2 = Rectangle(w=25, h=25, locx=50.0, locy=0.0)
    s2.fill_color = "orange"
    s2.opacity = 1.0

    # draw a circle
    s3 = Circle(locx=50.0, locy=0.0, r=25)
    s3.fill_color = "green"
    s3.opacity = 1.0
    s3.translate(50., 0.)
    sc.add_symbol(s3)

    # add these symbols to a group
    g = SymbolGroup()

    # apply a rotation to this group
    g.rotate(30.)
    g.add_symbol(s1)
    g.add_symbol(s2)


    # draw X axis
    s4 = Polyline()
    s4.add_point(-100, 0)
    s4.add_point(100, 0)
    s4.stroke_color = "magenta"
    s4.stroke_width = 2.0

    # draw Y axis
    s5 = Polyline()
    s5.add_point(0.0, -100.0)
    s5.add_point(0.0, 100.0)
    s5.stroke_color = "magenta"
    s5.stroke_width = 2.0

    # draw another triangle
    s6 = Polygon()
    s6.add_point(-30.0, 40.0)
    s6.add_point(30.0, 40.0)
    s6.add_point(0.0, 80.0)
    s6.stroke_color = "cyan"
    s6.fill_color = "yellow"
    s6.stroke_width = 3.0

    # a second group
    g2 = SymbolGroup()
    g2.scale(0.5)
    g2.translate(100., 0.)
    g2.add_symbol(s4)
    g2.add_symbol(s5)
    g2.add_symbol(s6)

    sc.add_symbol(g)
    sc.add_symbol(g2)

    bridges.set_data_structure(sc)
    bridges.visualize()


if __name__ == "__main__":
    main()
