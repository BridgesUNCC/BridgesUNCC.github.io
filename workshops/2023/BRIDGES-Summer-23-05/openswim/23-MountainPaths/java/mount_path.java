import bridges.connect.Bridges;
import bridges.base.Color;
import bridges.base.ColorGrid;
import bridges.connect.DataSource;
import bridges.data_src_dependent.*;

import java.io.File;
import java.util.Scanner;
import java.util.Random;
import java.lang.String;
import java.io.FileNotFoundException;

public class mount_path {
  public static void main(String[] args) throws Exception {

      // bridges object initialization
    Bridges bridges = new Bridges(23, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

    // datasource initialization
    DataSource ds = bridges.getDataSource();

    // get the elevation data - pass in lat/long rectangular bounding box
	// lat min, longit min, lat max, longit max
    ElevationData ele_data = ds.getElevationData(6.02, 44.10, 
						 9.70, 47.77, 0.02);

    // set title
    bridges.setTitle("Mountain Paths - Greedy Algorithms Example");


    // get the path written into a color grid for visualization
    ColorGrid cg = getImage(ele_data);


    // find path by applying a greedy algorithm
    findPath (ele_data, ele_data.getRows()/2, cg);

    
    // visualize
    bridges.setDataStructure(cg);
    bridges.visualize();
  }


  public static ColorGrid getImage(ElevationData elev) {
      // TODO
      // the following line just creates an empty color grid object so the compiler is happy
      // your solution will process the elevation data and return a color grid object with the 
	  // the processed output
      ColorGrid cg = new ColorGrid(elev.getRows(), elev.getCols());

      //
      // Use elev.getRows(), elev.getCols(), elev.get(r,c) to access data.
      // create colorgrid with ColorGrid(nbrows, nbcols)
      // fill with .set(row, col, Color())
      //
      //pick gray scale color interpolated from elev.getMinVal() to elev.getMaxVal()
      
    return cg;
  }


    // determines the least effort path through the mountain starting a point on
    // the left edge of the image
  public static void findPath(ElevationData elev, int startRow, ColorGrid cg) {
    //        Run the greedy path from (0, startRow) to the right of the image
    //
    // always move right, but select the right cell, the top right cell, or bottom right cell
    // by minimizing the difference of elevation.
    //
    // Write path to the colorgrid

  }
    
}
