#include <string>
#include <fstream>
using namespace std;

#include "ColorGrid.h"
#include "Bridges.h"

using namespace bridges;

// reads a PPM text image
ColorGrid readImage (string infile);

// image processing ops
ColorGrid toGrayScale (ColorGrid& cg);
ColorGrid blurImage(ColorGrid& cg);

int main() {

	/*
	Main function to do all image processing calls and visualize to BRIDGES.
	You will first need to read in an image and create a color grid object from it.
	You can then pass that color grid object to the image processing functions below
	to get a new color grid to be visualized with different effects.
	*/

	// create Bridges object
	Bridges bridges(1, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

	// set title, description
	bridges.setTitle("An example of Image Processing: Grayscale conversion, Image Blurring");

	//TODO: read ppm file and store in color grid and visuzlize
	ColorGrid cg = readImage("../images/yosemite.ppm");

	bridges.setDataStructure(&cg);
	bridges.visualize();

    //TODO: pass color grid to gray scale function and visualize
	ColorGrid cg_gray = toGrayScale(cg);

	// send color grid to  server and visulize

    //TODO: pass color grid to blur funciton and visualize
	ColorGrid cg_blur = blurImage(cg);

	// send color grid to  server and visulize
	return 0;
}

// reads an image from  the given input image file
ColorGrid readImage(string file_name) {

	ifstream infile(file_name.c_str());
	string magic;
	int width, height, maxVal;
	infile >> magic >> width >> height >> maxVal;

	// create a color grid
	ColorGrid cg(height, width);
	cout << "width,height, maxval:" << width << "," << height << "," << maxVal << endl;
	int r, g, b;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) { 
			infile >> r >> g >> b;
			cg.set(i, j, Color(r, g, b));
	}

	return cg;
}

ColorGrid toGrayScale (ColorGrid& cg) {

	ColorGrid cg_gray;
	/*
	TODO:
	Loop over the passed in color grid and get each pixel.
    	For each pixel, calculate the gray scale value: red*0.299 + green*0.587 + blue*0.114
    	then set the new gray value as the color grids pixel color.

	return processed color grid
	*/
	return cg_gray;
}

ColorGrid blurImage(ColorGrid& cg) {
	ColorGrid cg_blur;
	/*
	TODO:
	Loop over the color grid and use a simple 5x5 filter, 
	    ignore edges to keep it simple blur each channel separately - 
	    Just do an average (box filter) of the 5x5 neighborhood of pixel intensities.
	    Apply the new averaged pixel intensity to the color grids pixel

		return processed color grid
	*/
	return cg_blur;

	return cg;
}
