import bridges.connect.Bridges;
import bridges.base.TreeElement;

public class ExprTree {
	public static void main(String[] args) throws Exception {


		//create the Bridges object
		Bridges bridges = new Bridges(1, "YOUR_USER_ID", "YOUR_API_KEY");
		// title, description
		bridges.setTitle("An Expression Tree Example Using TreeElements");
		bridges.setDescription("A manually constructed expression tree for sqrt(Ax^2 + By + c");

		//create  tree nodes
		TreeElement<String> a = new TreeElement<String>("a", "a");
		TreeElement<String> x = new TreeElement<String>("x", "x");
		TreeElement<String> x2 = new TreeElement<String>("x", "x");
		TreeElement<String> b =  new TreeElement<String>("b", "b");
		TreeElement<String> y =  new TreeElement<String>("y", "y");
		TreeElement<String> c =  new TreeElement<String>("c", "c");
		TreeElement<String> z =  new TreeElement<String>("z", "z");
		TreeElement<String> times1 =  new TreeElement<String>("*", "*");
		TreeElement<String> times2 =  new TreeElement<String>("*", "*");
		TreeElement<String> times3 =  new TreeElement<String>("*", "*");
		TreeElement<String> times4 =  new TreeElement<String>("*", "*");
		TreeElement<String> plus1 =  new TreeElement<String>("+", "+");
		TreeElement<String> plus2 =  new TreeElement<String>("+", "+");
		TreeElement<String> plus3 =  new TreeElement<String>("+", "+");
		TreeElement<String> qrt =  new TreeElement<String>("sqrt", "sqrt");


		// increase their size
		qrt.setSize(49.0);
		plus3.setSize(30.0);

		// add links to children

		times1.addChild(a);
		times1.addChild(x);

		times2.addChild(times1);
		times2.addChild(x2);

		times3.addChild(b);
		times3.addChild(y);

		plus1.addChild(times2);
		plus1.addChild(times3);

		times4.addChild (c);
		times4.addChild (z);

		plus2.addChild (times3);
		plus2.addChild (times4);

		plus3.addChild (plus1);
		plus3.addChild (times4);

		qrt.addChild(plus3);


		// mark the operators in  red
		times1.setColor("red");
		times2.setColor("red");
		times3.setColor("red");
		times4.setColor("red");
		plus1.setColor("red");
		plus2.setColor("red");
		plus3.setColor("red");
		qrt.setColor("red");
	
		// set link attributes, color, thickness
		qrt.setShape("square");
		qrt.getLinkVisualizer(plus3).setColor("green");
		qrt.getLinkVisualizer(plus3).setThickness(5.);
		plus3.getLinkVisualizer(plus1).setThickness(3.);
		plus3.getLinkVisualizer(times4).setThickness(3.);
	
		// link colors
	
		// provide BRIDGES the  handle to the tree structure
		bridges.setDataStructure(qrt);
	
		bridges.visualize();
	
	}
}
