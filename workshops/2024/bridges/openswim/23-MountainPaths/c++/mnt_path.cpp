
#include "Bridges.h"
#include "ColorGrid.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

#include "DataSource.h"
#include "data_src/ElevationData.h"
using namespace std;
using namespace bridges;

// This program implements the mountain paths assignment in C++. See the README.md for a
// detailed description


// takes in the processed elevation data and returns a color grid for
// visualization using BRIDGES
ColorGrid getImage(const ElevationData& elev_data) {
  //TODO
  //
  //return a Color Grid that represents the elevation as gray scale
  //
  // access elevation with elev_data.getVal(row, col)
  // compute the intensity by linear interpolation between elev_data.getMinVal(); and elev_data.getMaxVal();
  //
  // create ColorGrid with ColorGrid(nbrows, nbcols)
  // fill ColorGrid with .set(row, col, color)
  ColorGrid cg (1,1);
  
  return cg;
}

// determines the least effort path through the mountain starting a point on
// the left edge of the image
void findPath(const ElevationData&  elev_data, int startRow, ColorGrid& cg) {
  //        Run the greedy path from (0, startRow) to the right of the image
  //
  // always move right, but select the right cell, the top right cell, or bottom right cell
  // by minimizing the difference of elevation.
  //
  // Write path to the colorgrid
}

int main(int argc, char **argv) {

  // bridges object initialization


  // initialize Bridges
  Bridges bridges(123, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

  // defaults for row number and data file
  int startRow = 50;

  // set title
  bridges.setTitle("Mountain Paths - Greedy Algorithms Example");

  // get elevation data

  DataSource ds;
  ElevationData elev_data = ds.getElevationData(6.02, 44.10, 9.70, 47.77, 0.02);

  // color grid for visualization
  ColorGrid cg = getImage(elev_data);

  // find path by applying a greedy algorithm
  startRow = elev_data.getRows()/2;
  findPath (elev_data, startRow, cg);

  // visualize
  bridges.setDataStructure(cg);
  bridges.visualize();

  return 0;
}
