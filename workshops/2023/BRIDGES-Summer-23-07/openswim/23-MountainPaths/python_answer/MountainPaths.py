from bridges.bridges import *
from bridges.data_src_dependent import data_source
from bridges.color_grid import *
from bridges.color import *


def greedy_path(elev_data, start_y, cg):
        row = start_y
        # Run the greedy path from (0, start_y) to the right of the image
        # let row value range from 1  to max_row -1 so all are 3 element cases
        # Check the least of the 3 right pixels and move there
        for col in range(elev_data.cols-2):
                # can always go right
                cand_col = col+1
                diff = abs(elev_data.data[row][cand_col] - elev_data.data[row][col])
                dest_row = row
                
                # consider options
                options = [-1, +1]
                for o in options:
                        cand_row = row+o
                        if cand_row >=0 and cand_row < elev_data.rows-1:
                                cand_diff = abs(elev_data.data[cand_row][cand_col] - elev_data.data[row][col])
                                if cand_diff < diff:
                                        dest_row = cand_row
                                        diff = cand_diff
                
                # set the current pixel to a sentinel val
                cg.set(row, col, Color(255, 0, 255))
                # enact greedy choice
                row = dest_row

def get_image(elev_data):
        # Return this elevation data as a ColorGrid image
        cg = ColorGrid(elev_data.rows, elev_data.cols)
        for x in range(elev_data.cols):
                for y in range(elev_data.rows):
                        val = elev_data.data[y][x]
                        # associate a gray color by linear interpolation between minval and maxval
                        gray = int((val-elev_data.minVal)*255./(elev_data.maxVal-elev_data.minVal))
                        cg.set(y, x, Color(gray, gray, gray))
        
        return cg

                        
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
