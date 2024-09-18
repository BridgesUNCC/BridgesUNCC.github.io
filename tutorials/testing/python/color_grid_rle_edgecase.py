from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
import sys

def main():
    # This example illustrates using the Bridges color grid
    # We will build a checker grid using two different colors


    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # title, description
    bridges.set_title("A CheckerBoard Example Using Grid Type")
    bridges.set_description("This is an example of the color grid with height and width 10. "
        +   "This example alternates between blue and red starting with red at the top left corner of the grid.")


    blue = Color(col_name="blue")
    red = Color(col_name="red")

    width = 128
    height = 128
    cg = ColorGrid(width, height, blue)

    ### This particular test checks for an edge case in how RLE encoding works.
    ### If the last chunk of the RLE encoding is exactly the size of the RLE supported buffer
    ### does it handle it correctly?
    
    # color the square
    for y in range(0,width):
        for x in range(0, height):
            cg.set(x, y, red)

    bridges.set_data_structure(cg)

    bridges.visualize()


if __name__ == "__main__":
    main()

