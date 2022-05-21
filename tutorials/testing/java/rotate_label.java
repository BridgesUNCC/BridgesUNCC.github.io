import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Label;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;


public class rotate_label {

	public static void main(String[] args) throws Exception {

		// create Bridges object
		Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
		// title, description
		bridges.setTitle("Rotated Text Labels Example");
		bridges.setServer("clone");
		bridges.setDescription("Example with rotated labels with computed "
			+	"bounding boxes.");

		// create some symbols and add to symbol collection
		SymbolCollection sc = new SymbolCollection();

		// draw a rectangle


		Label l = new Label();
		l.setLocation(-30, 30);
		l.setFontSize(8.0f);
		l.setStrokeWidth(0.0f);
		l.setLabel("abcdljjjlllmmmm");
		l.setStrokeWidth(0.0f);
		l.setFillColor("purple");
		l.setRotationAngle(0.0f);

		sc.addSymbol(l);
		Label l2 = new Label();
		l2.setLocation(50, 50);
		l2.setFontSize(22.0f);
		l2.setStrokeWidth(0.0f);
		l2.setLabel("ABCDLJJJIII LLLM MMM");
		l2.setStrokeWidth(0.0f);
		l2.setFillColor("purple");
		l2.setRotationAngle(30.0f);
		sc.addSymbol(l2);

		Label l3 = new Label();
		l3.setLocation(70, 30);
		l3.setFontSize(16.0f);
		l3.setStrokeWidth(0.0f);
		l3.setLabel("ZYXabc WVU def CBA");
		l3.setStrokeWidth(0.0f);
		l3.setFillColor("green");
		l3.setRotationAngle(90.0f);
		sc.addSymbol(l3);

		float[] bbox =  l.getBoundingBox();
		Rectangle r1 = new Rectangle(bbox[0], bbox[1], bbox[2] - bbox[0], bbox[3] - bbox[1]);
		r1.setFillColor("red");
		r1.setOpacity(0.1f);
		sc.addSymbol(r1);

		bbox =  l2.getBoundingBox();
		Rectangle r2 = new Rectangle(bbox[0], bbox[1], bbox[2] - bbox[0], bbox[3] - bbox[1]);
		r2.setFillColor("red");
		r2.setOpacity(0.3f);
		sc.addSymbol(r2);

		bbox =  l3.getBoundingBox();
		System.out.println("Bbox dims:" + bbox[0] + "," + bbox[1] + "," + bbox[2] +
			"," + bbox[3]);

		Rectangle r3 = new Rectangle(bbox[0], bbox[1], bbox[2] - bbox[0], bbox[3] - bbox[1]);
		r2.setFillColor("yellow");
		r2.setOpacity(0.3f);
		sc.addSymbol(r3);


		// and a circle next to it
		Circle c2 = new Circle(0.0f, 0.0f, 1.0f);
		c2.setFillColor("green");
		c2.setOpacity(0.5f);
		sc.addSymbol(c2);

		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize the JSON and Collection
		bridges.visualize();
	}
}

