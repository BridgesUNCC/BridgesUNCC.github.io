from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
import sys

def main():

    # In the final part of this  tutorial we will build a checkerboard
    # pattern using the ColorGrid

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

    # set title
    bridges.set_title("BRIDGES Color Grid Tutorial - Part 2");

    # set description
    bridges.set_description("This example generates a checkerboard pattern");

    red =  Color(col_name="red")
    blue = Color(col_name="blue")

    col = Color(col_name="green")

    # create a 100 x100  color grid
    width = 100
    height = 100
    cg = ColorGrid(height, width, Color(col_name="white"))

    # create a checkerboard pattern
    # 10x10 grid
    num_squares_x = 10
    num_squares_y = 10

    sq_width = width/num_squares_x
    sq_height = width/num_squares_y

    for j in range(num_squares_y):
        for k in range(num_squares_x):

            # use even/odd value of pixel to figure out the color of the squares
            x_even = k % 2 == 0
            y_even = j % 2 == 0

            if (y_even == True):
                if (x_even == True):
                    col = red
                else:
                    col = blue
            else:
                if (x_even == True):
                    col = blue
                else:
                    col = red

            # find the address of the square
            origin_x = k * sq_width
            origin_y = j * sq_height

            # color the square
            for y in range(int(origin_y), int(origin_y + sq_height)):
                for x in range(int(origin_x), int(origin_x + sq_width)):
                    cg.set(x, y, col)
                    x = x + 1
                y = y + 1

    # tell Bridges the the color grid object to visualize
    bridges.set_data_structure(cg);

    # visualize
    bridges.visualize();


if __name__ == "__main__":
    main()

