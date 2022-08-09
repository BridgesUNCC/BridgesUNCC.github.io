import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.SymbolGroup;


public class tut_shapes_p1 {

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

		// draw a rectangle
		Rectangle s1 = new Rectangle(-50.0f, 0.0f, 25.0f, 25.0f);
			s1.setFillColor("red");
			s1.setOpacity(0.3f);
		sc.addSymbol(s1);

		// draw a rectangle
		Rectangle r1 = new Rectangle(50.0f, 0.0f, 25.0f, 25.0f);
			r1.setFillColor("orange");
			r1.setOpacity(0.8f);
		sc.addSymbol(r1);

		// and a circle next to it
		Circle s2 = new Circle(50.0f, 50.0f, 15.0f);
			s2.setFillColor("green");
			s1.setOpacity(0.6f);
		sc.addSymbol(s2);

		// draw a triangle above
		Polygon s3 = new Polygon();
			s3.addPoint(-25.0f, -10.0f);
			s3.addPoint(25.0f, -10.0f);
			s3.addPoint(0.0f, 50.0f);
			s3.setStrokeColor("darkorchid");
			s3.setStrokeWidth(2.0f);
		sc.addSymbol(s3);

		// draw axes
		Polyline s4 = new Polyline();
			s4.addPoint(-100.0f, 0.0f);
			s4.addPoint(100.0f, 0.0f);
			s4.setStrokeColor("magenta");
			s4.setStrokeWidth(2.0f);
		sc.addSymbol(s4);

		Polyline s5 = new Polyline();
			s5.addPoint(0.0f, -100.0f);
			s5.addPoint(0.0f, 100.0f);
			s5.setStrokeWidth(2.0f);
			s5.setStrokeColor("magenta");
		sc.addSymbol(s5);

		Text l = new Text();
		l.setAnchorLocation(0.0f, 25.0f);
		l.setFontSize(18f);
		l.setStrokeWidth(2.0f);
		l.setOpacity(.3f);
		l.setText("test label1");
		l.setStrokeColor("purple");
		sc.addSymbol(l);


		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize 
		bridges.visualize();
	}
}

