
#include "Bridges.h"
#include "ColorGrid.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;
using namespace bridges;

// This program implements the mountain paths assignment in C++. See the README.md for a 
// detailed description

// function prototypes
ColorGrid *getImage (int *img_arr, int imgWidth, int imgHeight, int maxVal);
int *readData (int *imgWidth, int *imgHeight, int *maxVal, string file_name);
void findPath(int *img_arr, int imgWidth, int imgHeight, int startRow, int maxVal);

int main(int argc, char **argv) {

	// bridges object initialization
	
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
        "YOUR_API_KEY");
	
	// defaults for row number and data file
	int startRow = 300;
	string dataFile = "./colorado1.dat";

	// set title
	bridges.setTitle("Mountain Paths - Greedy Algorithms Example");
	

	// read input elevation data
	int width, height, maxVal;
	int *elev_data;

	elev_data = readData(&width, &height, &maxVal, dataFile);

	// find path by applying a greedy algorithm
	findPath (elev_data, width, height, startRow, maxVal);

	
	// get the path written into a color grid for visualization
	ColorGrid *cg = getImage(elev_data, width, height, maxVal);

	// visualize
	bridges.setDataStructure(cg);
	bridges.visualize();

	return 0;
}

int *readData(int *width, int *height, int *maxVal, string file_name) {

	// open input, output files
	ifstream infile(file_name.c_str());
	ofstream outfile("colorado1.ppm");

	// read header 
	int min = INT_MAX, max = INT_MIN, w, h, val;
	cout << "Min, Max:" << min << "," << max << endl;
	infile >> w >> h;

	*width = w; *height = h;

	// allocate space for the input data
	// we will use a 1D array
	int size = w*h;
	int *elev_data = new int[size];

	// read the elevation data
	for (int k = 0; k < size; k++) {
		infile >>  val;

		// update the min, max val
		min = (val < min) ? val : min;
		max = (val > max) ? val : max;
	
		// store  in elevation array
		elev_data[k] = val;
	}
	// deal with negative elevation values - yes, you can be below sealevel!

	cout << "Min, Max:" << min << "," << max << endl;

	if (min < 0) {
		int offset = -min;
		for (int k = 0; k < size; k++) 
			elev_data[k] += offset;
		max += offset; 
	}
	
	// record the max value
	*maxVal = max;

	return elev_data;
}

// takes in the processed elevation data and returns a color grid for 
// visualization using BRIDGES
ColorGrid *getImage(int *elev_data, int width, int height, int maxVal) {

	// create color grid
	ColorGrid *cg = new ColorGrid(height, width);

	float pixel_val;
	int n = 0, gray;

	// load the elevation data
	for (int j = 0; j < height; j++)
	for (int k = 0; k < width; k++) {
		pixel_val = (float) elev_data[n++];
		if (pixel_val == -1.) {
			// this is the path drawn in yellow across the image
			cg->set(j, k, Color(255, 0, 255));
		}
		else {
			// scale value to be within 0-255, for r,g,b range
			gray = (int) (pixel_val*255./maxVal);	
			cg->set(j, k, Color(gray, gray, gray));
		}
	}

	return cg;
		
}

// determines the least effort path through the mountain starting a point on
// the left edge of the image
void findPath(int *elev_data, int imgWidth, int imgHeight, int startRow, int maxVal) {
	
	if (startRow < 0 || startRow >= imgHeight) 
		return;

	int col = 0, row = startRow; 
	int pix_addr = startRow*imgWidth + col;

	while (col != imgWidth-2) {
		// hold neighbors in array
		int neighb[3] = {0, 0, 0};

		// compute 2D address of pixel from 1D address
		row = pix_addr/imgWidth;
		col = pix_addr - row*imgWidth;
		int top_right = pix_addr - imgWidth + 1;
		int right = pix_addr + 1;
		int bottom_right = pix_addr + imgWidth + 1;
		int cnt;

		// color the pixel, its in the path
		elev_data[pix_addr] = -1; 

		// deal with boundary cases first
		if (row == 0) { 
			// must  go right or down
			cnt = 2;
			neighb[0] = right; neighb[1] = bottom_right;
		}
		else if (row == imgHeight-1){ 
			// must go right or up
			cnt = 2;
			neighb[0] = right; neighb[1] = top_right;
		}
		else { 	
			// general case
			// check the 3 right neighbors, make greedy decision 
			cnt = 3;
			neighb[0] = top_right; neighb[1] = right; neighb[2] = bottom_right;
		}

		// compute differences with right neighbors
		int min = maxVal;
		int diff[3];
		for (int k = 0; k < cnt; k++)  {
			int d = elev_data[pix_addr] - elev_data[neighb[k]];
			diff[k] = (d < 0) ? -d : d;
		}
		// choose pixe with the smallest difference
		switch (cnt) {
			case 2: 
				pix_addr =  (diff[0] <= diff[1]) ? neighb[0] : neighb[1];
				break;
			case 3:
				if (diff[0] < diff[1] && diff[0] < diff[2])
					pix_addr = neighb[0];
				else 
					if (diff[1] < diff[0] && diff[1] < diff[2])
						pix_addr = neighb[1];
				else 
					if (diff[2] < diff[0] && diff[2] < diff[1])
						pix_addr = neighb[2];
				else if ((diff[0] == diff[1]) || (diff[1] == diff[2]))
						pix_addr = neighb[1];
				else { 
					double val = drand48();
					pix_addr = (val < 0.5) ? neighb[0] : neighb[2];
			}
		}
		col++;
	}
}
