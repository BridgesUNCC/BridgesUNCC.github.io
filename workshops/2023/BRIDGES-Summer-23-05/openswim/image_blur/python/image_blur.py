from bridges.bridges import *
from bridges.color_grid import *

def main():

    """
    TODO:
    Main function to do all image processing calls and visualize to BRIDGES.
    You will first need to read in an image and create a color grid object from it.
    you can then pass that color grid object to the image processing functions below
    to get a new color grid to be visualized with different effects.
    """
    bridges = Bridges(10, "bridges_user_id", "bridges_api_key")

    bridges.set_title("an example of image processing: grayscale conversion, image blurring.")

    # read ppm file and store in color grid and visuzlize
    cg = read ("../images/yosemite.ppm");
    bridges.set_data_structure(cg)
    bridges.visualize();

    #todo: pass color grid to gray scale function and visualize
    cg_gray = to_gray_scale(cg)

    # send color grid to server and visualize

    #todo: pass color grid to blur funciton and visualize
    cg_blur = blur_image(cg)
    
    # send color grid to server and visualize


def read(file_name):
    with open(file_name, 'r') as sc:
        # read the header (assumes ppm text images)
        magic = sc.readline()
        line = sc.readline().split(" ")
        width = int(line[0])
        height = int(line[1])
        max_val = int(sc.readline())

        cg = ColorGrid(height, width)

        values = []
        for l in sc:
            values.extend(l.split())

        #read pixel values
        k = 0
        for i in range(height):
            for j in range(width):
                r = values[k]
                g = values[k+1]
                b = values[k+2]

                cg.set(i, j, Color(r, g, b))
                k+=3

        return cg


def to_gray_scale(cg):
    cg_gray = ColorGrid(cg.dimensions[0], cg.dimensions[1])

    """
    todo: loop over the passed in color grid and get each pixel.
    for each pixel, calculate the gray scale value: red*0.299 + green*0.587 + blue*0.114
    then set the new gray value as the color grids pixel color.
    """

    return cg_gray;

def blur_image(cg):
    cg_blur = ColorGrid(cg.dimensions[0], cg.dimensions[1])
    """
    TODO: Loop over the color grid and use a simple 5x5 filter, 
    ignore edges to keep it simple blur each channel separately - 
    Just do an average (box filter) of the 5x5 neighborhood of pixel intensities.
    Apply the new averaged pixel intensity to the color grids pixel
    """
    return cg_blur


if __name__ == "__main__":
    main()
