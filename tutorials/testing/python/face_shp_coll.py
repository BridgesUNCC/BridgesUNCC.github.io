from bridges.symbol_collection import *
from bridges.bridges import *
from bridges.circle import *
from bridges.rectangle import *
from bridges.polygon import *
from bridges.polyline import *
from bridges.rectangle import *
from bridges.text import *
from bridges.color import *
from bridges.text import *
import sys

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("Drawing a Face Example")

    sc = SymbolCollection()

    # left eye
    s1 = Circle(r = 25.0)
    s1.set_stroke_color = "green"
    s1.set_stroke_width = 1.2
    tf = [-25., 20.]
    sf = [0.3]
    s1.translate(tf[0], tf[1])
    s1.scale(sf[0])
    sc.add_symbol (s1)


    # right eye
    s2 = Circle(r = 25.0)
    s2.set_stroke_color = "green"
    s2.set_stroke_width = 1.3
    tf = [25., 20.]
    s2.translate(tf[0], tf[1])
    s2.scale(sf[0])
    sc.add_symbol (s2)


    #nose
    s3 = Rectangle(w=10.0, h=10.0, locx=0.0, locy=0.0)
    s3.fill_color = "red"
    s3.set_stroke_width = 1.3
    sf = [0.5, 3.0]
    tf = [0.0, -10.0]
    s3.translate(tf[0], tf[1])
    s3.scale(sf[0], sf[1])
    sc.add_symbol(s3)

    # mouth is a rectangle, use scale and translation
    s4 = Rectangle(w=10, h=10, locx=0.0, locy=0.0)
    s4.fil_color = "blue"
    s4.set_stroke_width = 1.3
    sf= [3., 0.5]
    tf = [-10., -40.]
    s4.scale(sf[0], sf[1]);
    s4.translate(tf[0], tf[1]);
    sc.add_symbol(s4);


    # put a hat on the head
    s5 = Polyline();
    s5.stroke_color = "darkorchid";
    s5.stroke_width = 3.0;
    s5.add_point(-50.0, 22.0);
    s5.add_point(0.0, 120.0);
    s5.add_point(50.0, 22.0);
    sc.add_symbol(s5);

    # add a title to figure
    l = Text()
    l.set_anchor_location(-70, 120)
    l.font_size = 16
    l.stroke_width = 1.0
    l.label = "Its a Dorky Looking Face!"
    l.stroke_color = "purple"
    sc.add_symbol(l)

    bridges.set_data_structure(sc)
    bridges.visualize()


if __name__ == "__main__":
    main()
