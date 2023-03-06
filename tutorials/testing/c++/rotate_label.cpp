#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"
#include "Label.h"
#include "Circle.h"

#include <vector>

using namespace std;

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
        "YOUR_API_KEY");

	// works only with clone, need to be removed later
	bridges.setServer("clone");
	// title, description
	bridges.setTitle("Rotated Labels Test");
	bridges.setDescription("Labels in Bridges can be rotated and their bounding boxes displayed");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	

	Label l;
	l.setLocation(0, 0);
	l.setFontSize(8.);
	l.setStrokeWidth(0.0f);
	l.setLabel("abcdljjjlllmmmm");
	l.setStrokeColor("purple");
	l.setRotationAngle(15.);
	sc.addSymbol(&l);

	// draw a rectangle

	Label l2;
	l2.setLocation(50, 50);
	l2.setFontSize(12.);
	l2.setStrokeWidth(0.0f);
	l2.setLabel("ABCDLJJJIIILLLMMMM");
	l2.setStrokeWidth(0.0f);
	l2.setFillColor("purple");
	l2.setRotationAngle(-50.0f);
	sc.addSymbol(&l2);
	
	vector<float> bbox =  l.getBoundingBox();
	Rectangle r1(bbox[0], bbox[1], bbox[2]-bbox[0], bbox[3]- bbox[1]);
	r1.setFillColor("red");
	r1.setOpacity(0.1f);
	sc.addSymbol(&r1);

	bbox =  l2.getBoundingBox();
	Rectangle r2(bbox[0], bbox[1], bbox[2]-bbox[0], bbox[3]- bbox[1]);
	r2.setFillColor("green");
	r2.setOpacity(0.3f);
	sc.addSymbol(&r2);

	// draw a small circle
	Circle c1 (0,0, 3);
	c1.setFillColor(Color("green"));
	c1.setOpacity(0.5f);
	sc.addSymbol(&c1);


	Label l3;
	l3.setLocation(-50, -20);
	l3.setFontSize(12.);
	l3.setStrokeWidth(0.0f);
	l3.setLabel("ZYX cba TUV def CBA");
	l3.setStrokeWidth(0.0f);
	l3.setFillColor("purple");
	l3.setRotationAngle(-90.0f);
	sc.addSymbol(&l3);

	bbox =  l3.getBoundingBox();
	Rectangle r3(bbox[0], bbox[1], bbox[2]-bbox[0], bbox[3]- bbox[1]);
	r3.setFillColor("red");
	r3.setOpacity(0.3f);
	sc.addSymbol(&r3);
	// set visualizer type
	bridges.setDataStructure(sc);

//	bridges.setVisualizeJSONFlag(true);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
