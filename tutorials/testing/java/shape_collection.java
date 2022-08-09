import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.SymbolGroup;


public class shape_collection {

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
		Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50.0f, 50.0f);
		s1.setFillColor("red");
		s1.setOpacity(0.3f);
		sc.addSymbol(s1);

		// and a circle next to it
		Circle s2 = new Circle(25.0f, 0.0f, 25.0f);
		s2.setFillColor("green");
		s1.setOpacity(0.1f);
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
		sc.addSymbol(s5);

		Polyline s5b = new Polyline();
		s5b.addPoint(50.0f, -100.0f);
		s5b.addPoint(50.0f, 100.0f);
		s5b.addPoint(70.0f, 120.0f);
		s5b.setStrokeWidth(2.0f);
		sc.addSymbol(s5b);
		
		Polygon s6 = new Polygon();
		s6.addPoint (-30.0f, 40.0f);
		s6.addPoint (30.0f, 40.0f);
		s6.addPoint (0.0f, 80.0f);
		s6.setStrokeColor("cyan");
		s6.setFillColor("yellow");
		s6.setStrokeWidth(3.0f);
		sc.addSymbol(s6);



		Text l = new Text();
		l.setAnchorLocation(0.0f, 25.0f);
		l.setFontSize(18f);
		l.setStrokeWidth(2.0f);
		l.setOpacity(.3f);
		l.setText("test label1");
		l.setStrokeColor("purple");
		sc.addSymbol(l);


		SymbolGroup group = new SymbolGroup();
		sc.addSymbol(group);
		group.setTransform(1,0,0,1,30,20);
		
		
		Text l2 = new Text();
		l2.setAnchorLocation(0.0f, 25.0f);
		l2.setFontSize(12f);
		l2.setStrokeWidth(1.0f);
		l2.setText("test label translated and scaled");
		l2.setStrokeColor("purple");
		l2.scale(2.0f, 1.0f);
		group.addSymbol(l2);
		
		SymbolGroup group2 = new SymbolGroup();
		group.addSymbol(group2);
		group2.setTransform(1,0,0,1,30,20);
		group2.rotate(20);
		
		Text l3 = new Text();
		l3.setAnchorLocation(0.0f, 25.0f);
		l3.setFontSize(12f);
		l3.setStrokeWidth(1.0f);
		l3.setText("test label translated more");
		l3.setStrokeColor("purple");
		l3.setAnchorAlignment("top", "middle");
		group2.addSymbol(l3);
		
		
		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize the JSON and Collection
		bridges.visualize();
	}
}

