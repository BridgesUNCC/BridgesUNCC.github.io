#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Circle.h"
#include "Label.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");

	// title, description
	bridges.setTitle("Symbol Collection");
	bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, "
				"and a test label with a purple outline.");
			

	// create some symbols and add to symbol collection
	SymbolCollection sc; 

//	Rectangle s1(-25, 0, 50, 50);
	Rectangle s1(-25, 0, 50, 50);
	s1.setFillColor(Color("red"));
	float sf[] = {0.5, 1.};
	s1.scale(sf[0], sf[1]);
//	sc.addSymbol(&s1);

	Circle s2(25, 0, 25);
	s2.setFillColor(Color("green"));
//	s2.scale(0.5);
//	sc.addSymbol(&s2);

	// draw axes
	Polyline s5;
	s5.addPoint(-100, 0);
	s5.addPoint(100, 0);
	Polyline s6;
	s6.addPoint(0, -100);
	s6.addPoint(0, 100);
	sc.addSymbol(&s5); sc.addSymbol(&s6);

	Polyline s4;
	s4.addPoint(-25, 0);
	s4.addPoint(0, -25);
	s4.addPoint(25, 0);
	s4.addPoint(0, 25);
	s4.addPoint(-25, 0);
	s4.scale(sf[0], sf[1]);
	s4.setStrokeColor("darkorchid");
	s4.setStrokeWidth(2.0f);
	sc.addSymbol(&s4);

	Polygon s3;
	s3.addPoint(-100, 0);
	s3.addPoint(100, 0);
	s3.addPoint(0, 0);
	s3.addPoint(0, -100);
	s3.addPoint(0, 100);
	s3.addPoint(0, 0);
	s3.setStrokeColor("magenta");
//	sc.addSymbol(&s3);



	Label l;
	l.setLocation(0,25);
	l.setFontSize(12);
	l.setStrokeWidth(1.0f);
	l.setLabel("test label");
	l.setStrokeColor("purple");
//	sc.addSymbol(&l);

	// set visualizer type
	bridges.setDataStructure(sc);

	bridges.visualize();
			
	return 0;
}
