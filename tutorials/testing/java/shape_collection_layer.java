import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.SymbolGroup;


public class shape_collection_layer {

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

		{
		    SymbolGroup sg = new SymbolGroup ();
		    
		    // draw a rectangle
		    Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50.0f, 50.0f);
		    s1.setFillColor("red");
		    s1.setLayer(1);
		    sg.addSymbol(s1);
		    
		    // and a circle next to it
		    Circle s2 = new Circle(25.0f, 0.0f, 25.0f);
		    s2.setFillColor("green");
		    s2.setLayer(2);
		    sg.addSymbol(s2);


		    Text t = new Text();
		    t.setText("group above with rectangle over circle");
		    t.setFontSize(10);
		    t.setStrokeWidth(1);
		    t.setStrokeColor("black");
		    sg.addSymbol(t);
		    
		    sg.setLayer(1);
		    sc.addSymbol(sg);
		}


		{
		    SymbolGroup sg = new SymbolGroup ();

		    // draw a rectangle
		    Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50.0f, 50.0f);
		    s1.setFillColor("yellow");
		    s1.setLayer(4);
		    sg.addSymbol(s1);
		    
		    // and a circle next to it
		    Circle s2 = new Circle(25.0f, 0.0f, 25.0f);
		    s2.setFillColor("blue");
		    s2.setLayer(3);
		    sg.addSymbol(s2);
		    

		    Text t = new Text();
		    t.setText("group below with circle over rectangle");
		    t.setFontSize(10);
		    t.setStrokeWidth(1);
		    t.setStrokeColor("black");
		    sg.addSymbol(t);
		    
		    sg.setFillColor("magenta");

		    sg.setLayer(2);
		    sg.translate(30,30);
		    sc.addSymbol(sg);
		}



		
		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize
		bridges.visualize();
	}
}

