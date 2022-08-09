import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.SymbolGroup;


public class shape_collection_textalign {

    public static SymbolGroup anchorTest(String alignLR, String alignTB) {
	SymbolGroup group = new SymbolGroup();

	// draw axes
	Polyline xaxis = new Polyline();
	xaxis.addPoint(-50.0f, 0.0f);
	xaxis.addPoint(50.0f, 0.0f);
	xaxis.setStrokeColor("black");
	xaxis.setStrokeWidth(1.0f);
	group.addSymbol(xaxis);

	Polyline yaxis = new Polyline();
	yaxis.addPoint(0.0f, -50.0f);
	yaxis.addPoint(0.0f, 50.0f);
	yaxis.setStrokeColor("black");
	yaxis.setStrokeWidth(1.0f);
	group.addSymbol(yaxis);


	//sample text
	Text l = new Text();
	l.setFontSize(10f);
	l.setStrokeWidth(1.0f);
	l.setText("Something");
	l.setStrokeColor("black");
	l.setAnchorAlignment(alignLR, alignTB);
	group.addSymbol(l);

	//title
	Text t = new Text();
	t.setFontSize(10f);
	t.setStrokeWidth(1.0f);
	t.setText(alignLR +" "+ alignTB);
	t.setStrokeColor("black");
	t.setAnchorLocation(0.0f, -50.0f);
	t.setAnchorAlignment("middle", "top");
	group.addSymbol(t);

	return group;

    }
    
	public static void main(String[] args) throws Exception {

		//create Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// title, description
		bridges.setTitle("Symbol Collection");
		bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, "
			+	"and a test label with a purple outline.");

		// create some symbols and add to symbol collection
		SymbolCollection sc = new SymbolCollection();

		sc.setViewport(-100, 400,
			       -100, 700
			       );
		
		{ 
		    SymbolGroup group = anchorTest("left", "bottom");
		    group.translate(0,0);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("middle", "bottom");
		    group.translate(120,0);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("right", "bottom");
		    group.translate(240,0);
		    sc.addSymbol(group);
		}
		

		{ 
		    SymbolGroup group = anchorTest("left", "embottom");
		    group.translate(0, 150);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("middle", "embottom");
		    group.translate(120, 150);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("right", "embottom");
		    group.translate(240, 150);
		    sc.addSymbol(group);
		}


		{ 
		    SymbolGroup group = anchorTest("left", "middle");
		    group.translate(0, 300);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("middle", "middle");
		    group.translate(120, 300);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("right", "middle");
		    group.translate(240, 300);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("left", "emtop");
		    group.translate(0, 450);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("middle", "emtop");
		    group.translate(120, 450);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("right", "emtop");
		    group.translate(240, 450);
		    sc.addSymbol(group);
		}


		{ 
		    SymbolGroup group = anchorTest("left", "top");
		    group.translate(0, 600);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("middle", "top");
		    group.translate(120, 600);
		    sc.addSymbol(group);
		}

		{ 
		    SymbolGroup group = anchorTest("right", "top");
		    group.translate(240, 600);
		    sc.addSymbol(group);
		}
		
		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize the JSON and Collection
		bridges.visualize();
	}
}

