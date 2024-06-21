from bridges.bridges import *
from bridges.color_grid import *

def main():

    bridges = Bridges(10, "BRIDGES_USER_ID", "BRIDGES_API_KEY")

    bridges.set_title("An example of image processing: Grayscale conversion, Image Blurring.")

    #read image into colorgrid
    cg = read('../images/yosemite.ppm')

    #display colorgrid image
    bridges.set_data_structure(cg)
    bridges.visualize()

    #convert to grayscale image
    cg_gs = to_gray_scale(cg)

    #display grayscale colorgrid image
    bridges.set_data_structure(cg_gs)
    bridges.visualize()

    #blur colorgrid image
    cg_blur = blur_image(cg)

    #display blurred colorgrid image
    bridges.set_data_structure(cg_blur)
    bridges.visualize()


def read(file_name):
    with open(file_name, 'r') as sc:
        # read the header (Assumes PPM text images)
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

    cg_processed = ColorGrid(cg.dimensions[0], cg.dimensions[1])

    for i in range(cg.dimensions[0]):
        for j in range( cg.dimensions[1]):
            #get r, g, b of pixel
            c = cg.get(i,j)
            #compute gray scale value
            gray = int(c.red * 0.299 + c.green * 0.587 + c.blue * 0.114)

            #store in processed colorgrid
            cg_processed.set(i,j, Color(gray, gray, gray))

    return cg_processed

def blur_image(cg):

    height = cg.dimensions[0]
    width = cg.dimensions[1]

    cg_processed = ColorGrid(height, width)

    #use a simple 5x5 filter, ignore edges to keep it simple
    #blur each channel separately - just do an average (box
    #filter) of the 5x5 neighborhood of pixel intensities

    kernal_sum = [None, None, None]
    c = Color()

    #note: iteration is 2 pixels away from the image edges
    for i in range(height-2):
        for j in range(width-2):
            kernal_sum[0] = 0
            kernal_sum[1] = 0
            kernal_sum[2] = 0
            #filter the pixel - simple box filter
            for m in range(-2, 3):
                for n in range(-2, 3):
                    c = cg.get(i+m, j+n)
                    kernal_sum[0] += c.red
                    kernal_sum[1] += c.green
                    kernal_sum[2] += c.blue

            nc = Color()
            nc.red = int(kernal_sum[0]/25)
            nc.green = int(kernal_sum[1]/25)
            nc.blue = int(kernal_sum[2]/25)

            cg_processed.set(i,j,nc)
    return cg_processed

if __name__ == "__main__":
    main()
