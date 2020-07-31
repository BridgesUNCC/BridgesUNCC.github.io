#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Polyline.h"
#include "Polygon.h"
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

	// draw a rectangle
	Rectangle s1(-25, 0, 50, 50);
	s1.setFillColor(Color("red"));
	s1.setOpacity(0.3f);
	sc.addSymbol(&s1);
	

	// and a circle next to it
	Circle s2(25, 0, 25);
	s2.setFillColor(Color("green"));
	sc.addSymbol(&s2);

	// draw a triangle above
	Polygon s3;
	s3.addPoint(-25, -10);
	s3.addPoint(25, -10);
	s3.addPoint(0, 50);
	s3.setStrokeColor("darkorchid");
	s3.setStrokeWidth(2.0f);
	sc.addSymbol(&s3);

	// draw axes
	Polyline s4;
	s4.addPoint(-100, 0);
	s4.addPoint(100, 0);
	s4.setStrokeColor("magenta");
	s4.setStrokeWidth(2.0f);
	sc.addSymbol(&s4);

	Polyline s5;
	s5.addPoint(0, -100);
	s5.addPoint(0, 100);
	s5.setStrokeWidth(2.0f);
	sc.addSymbol(&s5);

	Polygon s6;
	s6.addPoint (-30.0f, 40.0f);
	s6.addPoint (30.0f, 40.0f);
	s6.addPoint (0.0f, 80.0f);
	s6.setStrokeColor("cyan");
	s6.setFillColor("yellow");
	s6.setStrokeWidth(3.0f);
	sc.addSymbol(&s6);



	Label l;
	l.setLocation(0, 25);
	l.setFontSize(12);
	l.setStrokeWidth(1.0f);
	l.setLabel("test label");
	l.setStrokeColor("purple");
	sc.addSymbol(&l);

	// set visualizer type
	bridges.setDataStructure(sc);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
