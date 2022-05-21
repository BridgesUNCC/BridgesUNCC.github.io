
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

  // create color grid
  int width = elev_data.getCols();
  int height = elev_data.getRows();
  ColorGrid cg (height, width);

  float pixel_val;
  int n = 0, gray;
  int maxVal = elev_data.getMaxVal();
  int minVal = elev_data.getMinVal();
  
  // load the elevation data
  for (int j = 0; j < height; j++)
    for (int k = 0; k < width; k++) {
      pixel_val = (float) elev_data.getVal(j, k);

      // scale value to be within 0-255, for r,g,b range
      gray = (int) ((pixel_val - minVal) * 255. / (maxVal-minVal));
      cg.set(j, k, Color(gray, gray, gray));
    }

  return cg;
}

// determines the least effort path through the mountain starting a point on
// the left edge of the image
void findPath(const ElevationData&  elev_data, int startRow, ColorGrid& cg) {
  int imgWidth = elev_data.getCols();
  int imgHeight = elev_data.getRows();
  int maxVal = elev_data.getMaxVal();

  if (startRow < 0 || startRow >= imgHeight)
    return;

  int row = startRow;

  for (auto col = 0; col < imgWidth - 1; col++) {
    // color the pixel, its in the path
    cg.set(row, col, Color(255,0,255));

    //can always go right, so use that as reference
    auto cand_col = col+1;
    auto diff = std::abs(elev_data.getVal(row, cand_col) - elev_data.getVal(row, col));
    auto dest_row = row;

    //consider options
    int options[2]  {-1, +1};
    for (auto o : options) {
      auto cand_row = row+o;

      if (cand_row >= 0 && cand_row <imgHeight-1) {
	auto cand_diff = std::abs(elev_data.getVal(cand_row, cand_col) - elev_data.getVal(row, col));
	if (cand_diff < diff) {
	  dest_row = cand_row;
	  diff = cand_diff;
	}
      }
    }

    //enact choice
    row = dest_row;
    

  }
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
