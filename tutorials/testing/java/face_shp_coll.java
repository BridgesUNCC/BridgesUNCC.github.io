import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;


public class face_shp_coll {

	public static void main(String[] args) throws Exception {

		//create Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		// title, description
		bridges.setTitle("Symbol Collection - A Face Example");
		bridges.setDescription("Example of building a simple shape with transformations(translate, scale and rotation");

		// Creae a simple face with circles and rectangles
		SymbolCollection sc = new SymbolCollection();

		// face itself is a circle
		Circle s1 = new Circle(50.0f);
		s1.setStrokeColor("red");
		s1.setStrokeWidth(2.0f);
		sc.addSymbol(s1);

		// left eye, use translation and scale to locate and shape it
		Circle s2 = new Circle(25.0f);
		s2.setStrokeColor("green");
		s2.setStrokeWidth(1.2f);
		float tf[] = {-25.0f, 20.0f};
		float sf[] = {0.5f, 0.5f};
		s2.translate(tf[0], tf[1]);
		s2.scale(0.3f);
		sc.addSymbol(s2);

		// right eye, similarly
		Circle s3 = new Circle(25.0f);
		s3.setStrokeColor("green");
		s3.setStrokeWidth(1.3f);
		tf[0] = 25.0f;
		tf[1] = 20.0f;
		s3.translate(tf[0], tf[1]);
		s3.scale(0.3f);
		sc.addSymbol(s3);


		// nose is a rectangle, use scale and translation
		Rectangle s4 = new Rectangle(0.0f, 0.0f, 10.0f, 10.0f);
		s4.setFillColor("blue");
		s4.setStrokeWidth(1.3f);
		sf[0] = 0.5f;
		sf[1] = 3.0f;
		tf[0] = 0.0f;
		tf[1] = -10.0f;
		s4.scale(sf[0], sf[1]);
		s4.translate(tf[0], tf[1]);
		sc.addSymbol(s4);

		// mouth is a rectangle, use scale and translation
		Rectangle s5 = new Rectangle(0.0f, 0.0f, 10.0f, 10.0f);
		s5.setFillColor("blue");
		s5.setStrokeWidth(1.3f);
		sf[0] = 3.0f;
		sf[1] = 0.5f;
		tf[0] = 0.0f;
		tf[1] = -45.0f;
		s5.scale(sf[0], sf[1]);
		s5.translate(tf[0], tf[1]);
		sc.addSymbol(s5);

		// put a hat on the head
		Polyline s6 = new Polyline();
		s6.addPoint(-50.0f, 22.0f);
		s6.addPoint(0.0f, 120.0f);
		s6.addPoint(50.0f, 22.0f);
		s6.setStrokeColor("darkorchid");
		s6.setStrokeWidth(3.0f);
		sc.addSymbol(s6);

		// add a title to the figure
		Text l = new Text();
		l.setAnchorLocation(-50.0f, 100.0f);
		l.setFontSize(16.0f);
		l.setStrokeWidth(1.0f);
		l.setLabel("Its a Dorky Looking Face!");
		l.setStrokeColor("purple");
		sc.addSymbol(l);

		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize
		bridges.visualize();
	}
}

