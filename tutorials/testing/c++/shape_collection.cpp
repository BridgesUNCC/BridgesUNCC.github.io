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
	bridges.setTitle("Symbol Collection");
	bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, and a test label with a purple outline.");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle>(-50, 0, 25, 25);

	r1->setFillColor(Color("red"));
	r1->setOpacity(0.1f);
	sc.addSymbolPtr(r1);
	

	std::shared_ptr<Rectangle> s1 = std::make_shared<Rectangle>(-50, 0, 25, 25);

	s1->setFillColor(Color("yellow"));
	s1->setOpacity(0.1f);
	
	// and a circle next to it
	Circle s2(50, 0, 25);
	s2.setFillColor(Color("green"));
	s2.setOpacity(1.0f);

	// create a symbol group and put s1 and s2 into it
	SymbolGroup g;
		g.translate(3., 10.);
		g.addSymbolPtr(s1);
		g.addSymbol(s2);

	// add the group in the symbol collection 
	SymbolCollection sc2;
		sc2.addSymbol (g);

	Polygon s3;
	s3.addPoint(-25, -10);
	s3.addPoint(25, -10);
	s3.addPoint(0, 50);
	s3.setStrokeColor("darkorchid");
	s3.setStrokeWidth(2.0f);
	s3.setOpacity(1.0f);
	sc.addSymbol(s3);

	// draw axes
	Polyline s4;
	s4.addPoint(-100, 0);
	s4.addPoint(100, 0);
	s4.setStrokeColor("magenta");
	s4.setStrokeWidth(2.0f);
	s4.setOpacity(1.0f);
	sc.addSymbol(s4);

	Polyline s5;
	s5.addPoint(0, -100);
	s5.addPoint(0, 100);
	s5.setStrokeWidth(2.0f);
	s5.setOpacity(1.0f);
	sc.addSymbol(s5);

	Polygon s6;
	s6.addPoint (-30.0f, 40.0f);
	s6.addPoint (30.0f, 40.0f);
	s6.addPoint (0.0f, 80.0f);
	s6.setStrokeColor("cyan");
	s6.setFillColor("yellow");
	s6.setStrokeWidth(3.0f);
	s6.setOpacity(1.0f);
	sc.addSymbol(s6);

	// an example text label
	Text l;
	float loc[2] = {0, 25};
	l.setAnchorLocation(loc);
	l.setFontSize(50.0f);
	l.setStrokeWidth(1.0f);
	l.setText("test label");
	l.setStrokeColor("purple");
	l.setOpacity(1.0f);
	sc.addSymbol(l);

	sc.addSymbol(g);

	// set visualizer type
	bridges.setDataStructure(sc);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
