from bridges.bridges import *
from bridges.data_src_dependent import data_source
from bridges.color_grid import *
from bridges.color import *

def get_image(elev_data):
        # TODO
        # Return this elevation data as a ColorGrid image
        #cg = None
        # the following line simply creates a color grid (so it doesnt generate a compiler error!); 
        # your implementation should process
        # the elevation data and return the color grid
        cg = ColorGrid(elev_data.rows, elev_data.cols)
        # use elev_data.rows, elev_data.cols, elev_data.data[r][c] to access data.
        # create colorgrid with ColorGrid(nbrows, nbcols)
        # fill with .set(row, col, Color())
        
        return cg


def greedy_path(elev_data, start_y, cg):
        # TODO
        # Run the greedy path from (0, start_y) to the right of the image
        #
        # always move right, but select the right cell, the top right cell, or bottom right cell
        # by minimizing the difference of elevation.
        #
        # Write path to the colorgrid
        pass

                        
def main():
        bridges = Bridges(223, "BRIDGES_USER_ID", "BRIDGES_API_KEY")
        
        bridges.set_title("Mountain Paths - Greedy Algorithms Example")
        bridges.set_description("Path through the mountains through the lowest elevation.")
        
        elev_data = data_source.get_elevation_data ([6.02, 44.10, 9.70, 47.77], 0.02)
        
        cg = get_image(elev_data)
        
        # apply the greedy algorithm to find hte path
        greedy_path(elev_data, int(elev_data.rows/2), cg)
        
        bridges.set_data_structure(cg)
        bridges.visualize()

if __name__ == '__main__':
        main()
