#include "Bridges.h"
#include "SymbolCollection.h"
#include "SymbolGroup.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Text.h"

using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// title, description
	bridges.setTitle("Symbol Collection - Layers (depth)");
	bridges.setDescription("Demonstrating use of layers with shapes");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	SymbolGroup sg;

	// draw a rectangle
	Rectangle s1(-25.0f, 0.0f, 50.0f, 50.0f);
	s1.setFillColor(Color("red")).setLayer(1);
	sg.addSymbol(s1);

	// and a circle next to it
	Circle s2(25.0f, 0.0f, 25.0f);
	s2.setFillColor(Color("green")).setLayer(2);
	sg.addSymbol(s2);

	Text t;
	t.setText("group above with rectangle over circle");
	t.setFontSize(10).setStrokeWidth(1).setStrokeColor(Color("black"));
	sg.addSymbol(t);

	sg.setLayer(1);
	sc.addSymbol(sg);

	SymbolGroup sg2;
	// draw a rectangle
	Rectangle s3(-25.0f, 0.0f, 50.0f, 50.0f);
	s3.setFillColor(Color("yellow")).setLayer(4);
	sg2.addSymbol(s3);

	// and a circle next to it
	Circle s4(25.0f, 0.0f, 25.0f);
	s4.setFillColor(Color("blue")).setLayer(3);
	sg2.addSymbol(s4);

	Text t2;
	t2.setText("group below with circle over rectangle");
	t2.setFontSize(12).setStrokeWidth(1).setStrokeColor(Color("black"));
	sg2.addSymbol(t2);
	sg2.setLayer(2);

	sg2.translate(30.0f, 30.0f);

	sc.addSymbol(sg2);

	// set visualizer type
	bridges.setDataStructure(sc);

//	bridges.setVisualizeJSONFlag(true);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
