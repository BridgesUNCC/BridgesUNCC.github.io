#include "Bridges.h"
#include "SymbolCollection.h"
#include "SymbolGroup.h"
#include "Rectangle.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Circle.h"
#include "Text.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// title, description
	bridges.setTitle("Symbol Collection: Display shapes supported by BRIDGES");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	Rectangle r1(50, 0, 25, 25);

	r1.setFillColor(Color("red"));
		r1.setOpacity(0.8f);
		sc.addSymbol(r1);
	sc.addSymbol(r1);
	
	Rectangle r2(-50, 0, 25, 25);
		r2.setFillColor(Color("orange"));
		r2.setOpacity(0.4f);
	sc.addSymbol(r2);

	// and a circle next to it
	Circle c1(50, 50, 15);
		c1.setFillColor(Color("green"));
		c1.setOpacity(1.0f);
	sc.addSymbol(c1);

	// add the group in the symbol collection 
	SymbolCollection sc2;

	Polygon p1;
		p1.addPoint(-25, -10);
		p1.addPoint(25, -10);
		p1.addPoint(0, 50);
		p1.setStrokeColor("darkorchid");
		p1.setStrokeWidth(2.0f);
		p1.setOpacity(1.0f);
	sc.addSymbol(p1);

	// draw axes
	Polyline p3;
		p3.addPoint(-100, 0);
		p3.addPoint(100, 0);
		p3.setStrokeColor("magenta");
		p3.setStrokeWidth(2.0f);
		p3.setOpacity(1.0f);
	sc.addSymbol(p3);

	Polyline p2;
		p2.addPoint(0, -100);
		p2.addPoint(0, 100);
		p2.setStrokeColor("magenta");
		p2.setStrokeWidth(2.0f);
		p2.setOpacity(1.0f);
	sc.addSymbol(p2);


	// an example text label
	Text l;
	float loc[2] = {10, 25};
		l.setAnchorLocation(loc);
		l.setFontSize(20.0f);
		l.setStrokeWidth(1.0f);
		l.setText("test label");
		l.setStrokeColor("purple");
		l.setOpacity(1.0f);
	sc.addSymbol(l);

	// set visualizer type
	bridges.setDataStructure(sc);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
