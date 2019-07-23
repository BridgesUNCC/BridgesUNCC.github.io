#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Circle.h"
#include "Label.h"

using namespace bridges;

int main (int argc, char **argv) {
    // create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
	// title, description
	bridges.setTitle("Symbol Collection - A Face Example");
	bridges.setDescription("Example of building a simple shape with transformations(translate, scale and rotation");

	SymbolCollection sc; 

	// Creae a simple face with circles and rectangles
	// face itself is a circle
	Circle s1(50);
	s1.setStrokeColor("red");
	s1.setStrokeWidth(2.0);
	sc.addSymbol(&s1);

	// left eye, use translation and scale to locate and shape it
	Circle s2(25);
	s2.setStrokeColor("green");
	s2.setStrokeWidth(1.2);
	float tf[] = {-25., 20.};
	float sf[] = {0.5, 0.5};
	s2.translate(tf[0], tf[1]);
	s2.scale(0.3);
	sc.addSymbol(&s2);

	// right eye, similarly
	Circle s3(25);
	s3.setStrokeColor("green");
	s3.setStrokeWidth(1.3);
	tf[0] = 25.; tf[1] = 20.;
	s3.translate(tf[0], tf[1]);
	s3.scale(0.3);
	sc.addSymbol(&s3);


	// nose is a rectangle, use scale and translation
	Rectangle s4(0, 0, 10, 10);
	s4.setFillColor(Color("blue"));
	s4.setStrokeWidth(1.3);
	sf[0] = 0.5; sf[1] = 3.0;
	tf[0] = 0.0; tf[1] = -10.0;
	s4.scale(sf[0], sf[1]);
	s4.translate(tf[0], tf[1]);
	sc.addSymbol(&s4);

	// mouth is a rectangle, use scale and translation
	Rectangle s5(0, 0, 10, 10);
	s5.setFillColor(Color("blue"));
	s5.setStrokeWidth(1.3);
	sf[0] = 3.; sf[1] = 0.5;
	tf[0] = 0.; tf[1] = -45.0;
	s5.scale(sf[0], sf[1]);
	s5.translate(tf[0], tf[1]);
	sc.addSymbol(&s5);

	Label l;
	l.setLocation(0,100);
	l.setFontSize(16);
	l.setStrokeWidth(1.0f);
	l.setLabel("Its a Dorky Looking Face!");
	l.setStrokeColor("purple");
	sc.addSymbol(&l);

	// set visualizer type
	bridges.setDataStructure(sc);

	bridges.visualize();
			
	return 0;
}
