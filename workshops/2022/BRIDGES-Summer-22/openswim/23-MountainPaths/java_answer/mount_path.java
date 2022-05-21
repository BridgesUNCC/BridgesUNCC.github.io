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
      
    ColorGrid cg = new ColorGrid(elev.getRows(), elev.getCols());

    float pixel_val;
    int n = 0, gray;

    for (int j = 0; j < elev.getRows(); j++)
	for (int k = 0; k < elev.getCols(); k++) {
	  pixel_val = (float) elev.getVal(j,k);

	  gray = (int) ((pixel_val - elev.getMinVal())* 255. / (elev.getMaxVal()-elev.getMinVal()));
	  cg.set(j, k, new Color(gray, gray, gray));
        
      }

    return cg;
  }


    // determines the least effort path through the mountain starting a point on
    // the left edge of the image
  public static void findPath(ElevationData elev, int startRow, ColorGrid cg) {
    int row = startRow;

    int[] options = new int[2];
    options[0] = -1;
    options[1] = +1;
      
    // iterate through the data
    for (int col=0; col != elev.getCols() - 2; ++col) {

      // calculate the elevation differences with neighbors
      int cand_col = col+1;
      int dest_row = row;
      int diff = Math.abs(elev.getVal(row,col) - elev.getVal(dest_row,cand_col));
      
      //consider options
      for (int o : options) {
	  int cand_row = row + o;
	  if (cand_row >=0 && cand_row < elev.getRows()-1) {
	      int cand_diff = Math.abs(elev.getVal(cand_row, cand_col) - elev.getVal(row, col));
	      if (cand_diff < diff) {
		  dest_row = cand_row;
		  diff = cand_diff;
	      }
	  }
      }
      
      // color the pixel, its in the path
      cg.set(row, col, new Color(255,0,255));
      
      //enact choice
      row = dest_row;
    }
  }
    
}
