#include "Bridges.h"
#include "SymbolCollection.h"
#include "SymbolGroup.h"
#include "Rectangle.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Circle.h"
#include "Text.h"

using namespace bridges;

SymbolGroup anchorTest(string alignLR, string alignTB);

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

	// title, description
	bridges.setTitle("Symbol Collection");
	bridges.setDescription("Illustrates features aligning text in BRIDGES; follows SVG features");

	SymbolCollection sc;
	sc.setViewport(-100, 400, -100, 700);

	SymbolGroup g[15];

	g[0] = anchorTest("left", "bottom"); g[0].translate(0,0); sc.addSymbol(g[0]);


	g[1] = anchorTest("middle", "bottom"); g[1].translate(120,0); sc.addSymbol(g[1]);

	g[2] = anchorTest("right", "bottom"); g[2].translate(240, 0); sc.addSymbol(g[2]);

	g[3] = anchorTest("left", "embottom"); g[3].translate(0, 150); sc.addSymbol(g[3]);

	g[4] = anchorTest("middle", "embottom"); g[4].translate(120, 150); sc.addSymbol(g[4]);

	g[5] = anchorTest("right", "embottom"); g[5].translate(240, 150); sc.addSymbol(g[5]);

	g[6] = anchorTest("left", "middle"); g[6].translate(0, 300); sc.addSymbol(g[6]);

	g[7] = anchorTest("middle", "middle"); g[7].translate(120, 300); sc.addSymbol(g[7]);

	g[8] = anchorTest("right", "middle"); g[8].translate(240, 300); sc.addSymbol(g[8]);

	g[9] = anchorTest("left", "emtop"); g[9].translate(0, 450); sc.addSymbol(g[9]);

	g[10] = anchorTest("middle", "emtop"); g[10].translate(120, 450); sc.addSymbol(g[10]);

	g[11] = anchorTest("right", "emtop"); g[11].translate(240, 450); sc.addSymbol(g[11]);

	g[12] = anchorTest("left", "top"); g[12].translate(0, 600); sc.addSymbol(g[12]);

	g[13] = anchorTest("middle", "top"); g[13].translate(120, 600); sc.addSymbol(g[13]);

	g[14] = anchorTest("right", "top"); g[14].translate(240, 600); sc.addSymbol(g[14]);

	// set visualizer type
	bridges.setDataStructure(sc);

//	bridges.setVisualizeJSONFlag(true);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}

SymbolGroup anchorTest(string alignLR, string alignTB) {
	SymbolGroup sg;

	Polyline xaxis;
	xaxis.addPoint (-50.0f, 0.0f);
	xaxis.addPoint (50.0f, 0.0f);
	xaxis.setStrokeColor(Color("black")).setStrokeWidth(1.0f);
	sg.addSymbol(xaxis);


	Polyline yaxis;
	yaxis.addPoint (0.0f, -50.0f);
	yaxis.addPoint (0.0f, 50.0f);
	yaxis.setStrokeColor(Color("black")).setStrokeWidth(1.0f);
	sg.addSymbol(yaxis);

	//sample text
	Text l;
    l.setFontSize(10.f).setStrokeWidth(1.0f).setStrokeColor(Color("black"));
    l.setText("Something").setAnchorAlignment(alignLR, alignTB);
    sg.addSymbol(l);

    //title
    Text t;
    t.setFontSize(10.0f).setStrokeWidth(1.0f).setStrokeColor(Color("black"));
    t.setText(alignLR +" "+ alignTB).setAnchorLocation(0.0f, -50.0f).setAnchorAlignment("middle", "top");
    sg.addSymbol(t);

	return  sg;
}
