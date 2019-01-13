from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
import sys

def main():
    # This example illustrates using the Bridges color grid
    # We will build a checker grid using two different colors

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

    # set title fo visualization
    bridges.set_title("A Checkerboard Example Using Grid Type")

    width = 200
    height = 200

    blue = Color(col_name= "blue")
    red = Color(col_name= "red")

    cg = ColorGrid(width, height, red)

    # create a checkerboard pattern
    # 10x10 grid
    num_squares_x = 10
    num_squares_y = 10

    sq_width = width/num_squares_x
    sq_height = width/num_squares_y

    for j in range(num_squares_y):
        for k in range(num_squares_x):

            # use even/odd value of pixel to figure out the color of the squares
            x_even = k%2 == 0
            y_even = j%2 == 0

            if(y_even == True):
                if(x_even == True):
                    col = red
                else:
                    col = blue
            else:
                if(x_even == True):
                    col = blue
                else:
                    col = red

            # find the address of the square
            origin_x = k*sq_width
            origin_y = j*sq_height

            #color the square
            for y in range(int(origin_y), int(origin_y+sq_height)):
                for x in range(int(origin_x), int(origin_x+sq_width)):
                    cg.set(x, y, col)
                    x = x + 1
                y = y + 1

    bridges.set_data_structure(cg)

    bridges.visualize()


if __name__ == "__main__":
    main()

