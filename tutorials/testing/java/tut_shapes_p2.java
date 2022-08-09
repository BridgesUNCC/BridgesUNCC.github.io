import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.SymbolGroup;


public class tut_shapes_p2 {

	public static void main(String[] args) throws Exception {

		//create Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// title, description
		bridges.setTitle("Symbol Collection");
		bridges.setDescription("Illustrates using two groups of symbols, transformedat the group level");

		// create some symbols and add to symbol collection
		SymbolCollection sc = new SymbolCollection();

		// draw a rectangle
		Rectangle s1 = new Rectangle(-50.0f, 0.0f, 25.0f, 25.0f);
			s1.setFillColor("red");
			s1.setOpacity(0.3f);

		Rectangle s2 = new Rectangle(50, 0, 25, 25);
			s2.setFillColor("orange");
			s2.setOpacity(1.0f);

		// and a circle next to it
		Circle c1 = new Circle(50.0f, 0.0f, 25.0f);
			c1.setFillColor("green");
			c1.setOpacity(1.0f);
			c1.translate(50.f, 0.f);
		sc.addSymbol(c1);

		SymbolGroup g = new SymbolGroup();
        	g.rotate(30.0f);
        	g.addSymbol(s1);
        	g.addSymbol(s2);

		sc.addSymbol(g);


		// draw axes
		Polyline s4 = new Polyline();
			s4.addPoint(-100.0f, 0.0f);
			s4.addPoint(100.0f, 0.0f);
			s4.setStrokeColor("magenta");
			s4.setStrokeWidth(2.0f);

		Polyline s5 = new Polyline();
			s5.addPoint(0.0f, -100.0f);
			s5.addPoint(0.0f, 100.0f);
			s5.setStrokeColor("magenta");
			s5.setStrokeWidth(2.0f);

		
		Polygon s6 = new Polygon();
			s6.addPoint (-30.0f, 40.0f);
			s6.addPoint (30.0f, 40.0f);
			s6.addPoint (0.0f, 80.0f);
			s6.setStrokeColor("cyan");
			s6.setFillColor("yellow");
			s6.setStrokeWidth(3.0f);

		SymbolGroup g2 = new SymbolGroup();;
			g2.scale(0.5f);
			g2.translate(100.0f, 0.0f);
			g2.addSymbol(s4);
			g2.addSymbol(s5);
			g2.addSymbol(s6);

		sc.addSymbol(g2);

		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize 
		bridges.visualize();
	}
}

