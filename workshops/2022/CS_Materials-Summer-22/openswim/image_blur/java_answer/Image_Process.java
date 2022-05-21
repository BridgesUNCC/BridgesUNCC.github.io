
import java.util.Scanner;
import java.io.*;

import bridges.connect.Bridges;
import bridges.base.ColorGrid;
import bridges.base.Color;
import java.io.IOException;


public class Image_Process {

	public static void main(String[] args) throws Exception {

		Bridges bridges = new Bridges(40, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

		// set title, description
		bridges.setTitle("An example of Image Processing: Grayscale conversion, Image Blurring");

		// read in the input image 
		ColorGrid cg = readImage("../images/yosemite.ppm");

		//  display the original image
		bridges.setDataStructure(cg);
		bridges.visualize();

		// convert to grayscale and display
		ColorGrid cg_gs = toGrayScale(cg);
		bridges.setDataStructure(cg_gs);
		bridges.visualize();

		// blur image and display
		ColorGrid cg_blurred = blurImage(cg);
	
		bridges.setDataStructure(cg_blurred);
		bridges.visualize();
	}

	public static ColorGrid toGrayScale (ColorGrid cg) {

		ColorGrid cg_processed = new ColorGrid(cg.getHeight(), cg.getWidth());

		for (int i = 0; i < cg.getHeight(); i++)  {
			for (int j = 0; j < cg.getWidth(); j++) { 
				// get the rgb of pixel
				Color c  = cg.get(i, j);
				// compute the gray value
				int gray = (int) (c.getRed() * 0.299 + c.getGreen() * 0.587 + 
									c.getBlue() * 0.114);

				// store in processed array 
				cg_processed.set(i, j, new Color(gray, gray, gray));
			}
		}
		return cg_processed;
	}

	public static ColorGrid blurImage(ColorGrid cg) {

		int height  = cg.getHeight(), width = cg.getWidth();
		ColorGrid cg_processed = new ColorGrid(height, width);

		// use a simple 5x5 filter, ignore edges to keep it simple
		// blur each channel separately - just do an average (box
		// filter) of the 5x5 neighborhood of pixel intensities
		int[] kernel_sum = new int[3];
		Color c = new Color(); 
		// note: iteration 2 pixels away from the image edges
		for (int i = 2; i < height - 2; i++)  {
			for (int j = 2; j < width - 2; j++) { 
				kernel_sum[0] = 0; kernel_sum[1] = 0; kernel_sum[2] = 0;	
				// filter the pixel - simple box filter
				for (int m = -2; m < 3; m++) {
					for (int n = -2; n < 3; n++) {
						c = cg.get(i+m, j+n);
						kernel_sum[0] += c.getRed();
						kernel_sum[1] += c.getGreen();
						kernel_sum[2] += c.getBlue();
					}
				}
				Color nc = new Color();
				nc.setRed((int) (kernel_sum[0]/25.));
				nc.setGreen((int) (kernel_sum[1]/25.));
				nc.setBlue((int) (kernel_sum[2]/25.));
				cg_processed.set(i, j, nc);
			}
		}

		return cg_processed;
	}

	// reads an image from  the given input image file
	public static ColorGrid readImage(String file_name) {
		// open the file
		try {
			Scanner sc = new Scanner(new File(file_name));

			// read the header (assumes PPM text images)
			String magic;
			magic = sc.next();
			int width = sc.nextInt();
			int height = sc.nextInt();
			int maxVal = sc.nextInt();

			ColorGrid cg = new ColorGrid(height, width);

			System.out.println("Header:" + magic + " " + width + " " + height +
					" " + maxVal);

			// read the pixels
			int k = 0;
			for (int i = 0; i < height; i++) { 
				for (int j = 0; j < width; j++) { 
					int r = sc.nextInt();
					int g = sc.nextInt();
					int b = sc.nextInt();
					cg.set(i, j, new Color(r, g, b));
				}
			}
			return cg;
		}
		catch (FileNotFoundException ex)  {
            System.out.println ("Input image file not found!" + ex);
			ex.printStackTrace();
			return null;
        }
	}
}
