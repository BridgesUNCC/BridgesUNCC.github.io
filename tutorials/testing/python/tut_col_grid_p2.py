from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
import sys

def main():

    # The second  part of the tutorial illustrates using the different ways
    # to specify color for cells in the color grid.

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title
    bridges.set_title("BRIDGES Color Grid Tutorial - Part 3");

    # set description
    bridges.set_description("This is an example to illustrate different ways of setting colors in the ColorGrid")

    red =  Color(col_name="red")
    green = Color(col_name="green")
    blue = Color(col_name="blue")

    # create a 10x10 color grid
    width = 10
    height = 10
    cg = ColorGrid(height, width, Color(col_name="lightgoldenrodyellow"))

    # color a few squares and make a + sign at the center
    # using named colors
    cg.set(5, 5, red);
    cg.set(5, 4, blue);
    cg.set(5, 6, blue);
    cg.set(4, 5, green);
    cg.set(6, 5, green);

    # tell Bridges the the color grid object to visualize
    bridges.set_data_structure(cg);

    # visualize
    bridges.visualize();
 
    # you can also use r,g, b, triplets to specify color (in the range 0-255)
    red = Color(255, 0, 0)
    green = Color(0, 255, 0)
    blue = Color(0, 0, 255)

    cg.set(5, 5, red);
    cg.set(5, 4, blue);
    cg.set(5, 6, blue);
    cg.set(4, 5, green);
    cg.set(6, 5, green);

    # visualize again
    bridges.visualize();

    # you can also specify a fourth component, opacity (alpha) to make
    # colors transparent. We will choose 0.5, halfway in the range 0-1.0
    
    red = Color(255, 0, 0, 0.5)
    green = Color(0, 255, 0, 0.5)
    blue = Color(0, 0, 255, 0.5)

    cg.set(5, 5, red);
    cg.set(5, 4, blue);
    cg.set(5, 6, blue);
    cg.set(4, 5, green);
    cg.set(6, 5, green);

    # visualize again
    bridges.visualize();

if __name__ == "__main__":
    main()

