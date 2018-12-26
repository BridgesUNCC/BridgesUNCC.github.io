
import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Label;
import bridges.base.Polygon;
import bridges.base.Color;


public class shape_collection {

	public static void main(String[] args) throws Exception {

		if (args.length < 2)
			throw new IllegalArgumentException("Need to provide user ID and API key as command-line arguments!");
		// note: you must fill in with your Bridges credentials
        Bridges bridges = new Bridges(216, "YOUR_USER_ID", "YOUR_API_KEY");

		bridges.setTitle("Symbol Collection");
		bridges.setDescription("Some Shapes and Symbols");

		SymbolCollection sc = new SymbolCollection();
		Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50, 50);
		s1.setFillColor(new Color("red"));
		sc.addSymbol(s1);

		Circle s2 = new Circle(25.0f, 0.0f, 25);
		s2.setFillColor(new Color("green"));
		sc.addSymbol(s2);


		Polygon s3 = new Polygon();
		//	vector<float> pts = {-100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 100.0, 0.0, 0.0};
		//	s3->setPolygon (pts);

		s3.addPoint(-100, 0);
		s3.addPoint(100, 0);
		s3.addPoint(0, 0);
		s3.addPoint(0, -100);
		s3.addPoint(0, 100);
		s3.addPoint(0, 0);
		s3.setStrokeColor(new Color("magenta"));
		sc.addSymbol(s3);

		Label l = new Label();
		l.setLocation(0, 25);
		l.setFontSize(12);
		l.setStrokeWidth(1.0f);
		l.setLabel("test label");
		l.setStrokeColor(new Color("purple"));
		sc.addSymbol(l);


		// set visualizer type

		bridges.setDataStructure(sc);
		// visualize the JSON and Collection
		bridges.visualize();
	}
}

