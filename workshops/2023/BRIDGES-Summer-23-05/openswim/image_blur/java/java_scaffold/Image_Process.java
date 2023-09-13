
import java.util.Scanner;
import java.io.*;

import bridges.connect.Bridges;
import bridges.base.ColorGrid;
import bridges.base.Color;
import java.io.IOException;


public class Image_Process {

	public static void main(String[] args) throws Exception {
		/*
		Main function to do all image processing calls and visualize to BRIDGES.
		You will first need to read in an image and create a color grid object from it.
		You can then pass that color grid object to the image processing functions below
		to get a new color grid to be visualized with different effects.
		*/

		Bridges bridges = new Bridges(40, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

		// set title, description
		bridges.setTitle("An example of Image Processing: Grayscale conversion, Image Blurring");
		
		//TODO: read ppm file and store in color grid and visuzlize

	    //TODO: pass color grid to gray scale function and visualize

	    //TODO: pass color grid to blur funciton and visualize
	}

	public static ColorGrid toGrayScale (ColorGrid cg) {
		/*
		TODO:
		Loop over the passed in color grid and get each pixel.
    	For each pixel, calculate the gray scale value: red*0.299 + green*0.587 + blue*0.114
    	then set the new gray value as the color grids pixel color.
		*/
		
		return cg;
	}

	public static ColorGrid blurImage(ColorGrid cg) {
		/*
		TODO:
		Loop over the color grid and use a simple 5x5 filter, 
	    ignore edges to keep it simple blur each channel separately - 
	    Just do an average (box filter) of the 5x5 neighborhood of pixel intensities.
	    Apply the new averaged pixel intensity to the color grids pixel
		*/

		return cg;
	}

	// reads an image from  the given input image file
	public static ColorGrid readImage(String file_name) {
		/*
		TODO:
		Write a function that reads in a ppm file and converts the image
    	into a BRIDGES color grid.
		*/
		//widht and height needs to be dimensions of ppm file
		int width = 10;
		int height = 10;

		ColorGrid cg = new ColorGrid(height, width);
		return cg;
	}
}
