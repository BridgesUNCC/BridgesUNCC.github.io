#include <string>
#include <fstream>
using namespace std;

#include "ColorGrid.h"
#include "Bridges.h"

using namespace bridges;

// reads a PPM text image
ColorGrid read (string infile);

// image processing ops
ColorGrid toGrayScale (ColorGrid& cg);
ColorGrid blurImage(ColorGrid& cg);

int main() {

	// create Bridges object
	Bridges bridges(1, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

	// set title, description
	bridges.setTitle("An example of Image Processing: Grayscale conversion, Image Blurring");

	// read an input image (PPM text format)
	ColorGrid cg = read("../images/yosemite.ppm");

	//  display the original image
	bridges.setDataStructure(&cg);
	bridges.visualize();

	// convert to grayscale and display
	ColorGrid cg_gs = toGrayScale(cg);
	bridges.setDataStructure(&cg_gs);
	bridges.visualize();

	// blur image and display
	ColorGrid cg_blurred = blurImage(cg);

	bridges.setDataStructure(&cg_blurred);
	bridges.visualize();

	return 0;
}

// reads an image from  the given input image file
ColorGrid read(string file_name) {

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
	ColorGrid cg_processed(cg.getHeight(), cg.getWidth());

	for (int i = 0; i < cg.getHeight(); i++)  {
		for (int j = 0; j < cg.getWidth(); j++) { 
			// get the rgb of pixel
			Color c  = cg.get(i, j);
			// compute the gray value
			int gray = int(c.getRed() * 0.299 + c.getGreen() * 0.587 + 
								c.getBlue() * 0.114);

			// store in processed array 
			cg_processed.set(i, j, Color(gray, gray, gray));
		}
	}
	return cg_processed;
}

ColorGrid blurImage(ColorGrid& cg) {
	ColorGrid cg_processed(cg.getHeight(), cg.getWidth());

	// use a simple 3x3 filter, ignore edges to keep it simple
	// blur each channel separately - just do an average (box
	// filter) of the 3x3 neighborhood of pixel intensities
	int kernel_sum[3];
	Color c;
	int height  = cg.getHeight(), width = cg.getWidth();
	for (int i = 2; i < height - 2; i++)  {
		for (int j = 2; j < width - 2; j++) { 
			kernel_sum[0] = kernel_sum[1] = kernel_sum[2] = 0;	
			for (int m = -1; m < 2; m++) {
				for (int n = -1; n < 2; n++) {
					c = cg.get(i+m, j+n);
					kernel_sum[0] += c.getRed();
					kernel_sum[1] += c.getGreen();
					kernel_sum[2] += c.getBlue();
				}
			}
			c.setRed((int) (kernel_sum[0]/9.));
			c.setGreen((int) (kernel_sum[1]/9.));
			c.setBlue((int) (kernel_sum[2]/9.));
			cg_processed.set(i, j, c);
		}
	}

	return cg_processed;
}
