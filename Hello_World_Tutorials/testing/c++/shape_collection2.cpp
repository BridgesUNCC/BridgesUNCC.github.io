#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Circle.h"
#include "Label.h"

using namespace bridges;

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");

	bridges->setTitle("Symbol Collection");
	bridges->setDescription("Some Shapes and Symbols");

	SymbolCollection *sc = new SymbolCollection(); 
	Rectangle *s1 = new Rectangle(-25, 0, 50, 50);
	s1->setFillColor(Color("red"));
	sc->addSymbol(s1);

	Circle *s2 = new Circle(25, 0, 25);
	s2->setFillColor(Color("green"));
	sc->addSymbol(s2);
	

	Polygon *s3 = new Polygon();

	s3->addPoint(-100, 0);
	s3->addPoint(100, 0);
	s3->addPoint(100, 100);
	s3->addPoint(100, -100);
	s3->setStrokeColor(Color("magenta"));
	sc->addSymbol(s3);

	Label *l = new Label();
	l->setLocation(0,25);
	l->setFontSize(12);
	l->setStrokeWidth(1.0f);
	l->setLabel("test label");
	l->setStrokeColor(Color("purple"));
	sc->addSymbol(l);


	// set visualizer type

	bridges->setDataStructure(sc);
				// visualize the JSON and Collection
	bridges->visualize();
			
	return 0;
}

