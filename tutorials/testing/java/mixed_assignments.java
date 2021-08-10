import bridges.connect.Bridges;
import bridges.base.TreeElement;
import bridges.base.CircSLelement;
import bridges.base.Array2D;
import bridges.base.Element;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Polygon;
import bridges.base.Color;
import bridges.base.ColorGrid;

public class mixed_assignments {
	public static void main(String[] args) throws Exception {


		//create the Bridges object
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

		/*
				T R E E
		*/
		TreeElement<String> t0 = new TreeElement<String>("Root");
		TreeElement<String> t1 = new TreeElement<String>("Child1");
		TreeElement<String> t2 = new TreeElement<String>("Child2");
		TreeElement<String> t3 = new TreeElement<String>("Child3");

		// add links to children
		t0.addChild(t1);
		t0.addChild(t2);
		t0.addChild(t3);

		// set some visual attributes
		t0.setColor("red");
		t0.setShape("diamond");
		t0.setOpacity(0.5f);

		// set data structure and visualize
		bridges.setTitle("A multiple subassignment example");
		bridges.setDataStructure(t0);
		bridges.visualize();


		/*
				L I S T
		*/
		CircSLelement<String> head = new CircSLelement<String>("", "head");
		CircSLelement<String> csl1 = new CircSLelement<String>("", "el1");
		CircSLelement<String> csl2 = new CircSLelement<String>("", "el2");
		CircSLelement<String> tail = new CircSLelement<String>("", "tail");

		// add links to list
		head.setNext(csl1);
		csl1.setNext(csl2);
		csl2.setNext(tail);
		tail.setNext(head);

		// set data structure and visualize
		bridges.setTitle("A small circular singly linked list");
		bridges.setDataStructure(head);
		bridges.visualize();


		/*
				A R R A Y		2 D
		*/
		int num_rows = 4, num_cols = 4;
		Array2D<Integer> my_array = new Array2D<Integer> (num_rows, num_cols);

		// populate the array
		for (int row = 0; row < num_rows; row++) {
			for (int col = 0; col < num_cols; col++) {
				my_array.getElement(row, col).setLabel("El " +
					String.valueOf(row * num_cols + col));
			}
		}

		// set a color
		my_array.getElement(0, 0).setColor("purple");

		// set data structure and visualize
		bridges.setTitle("A 2D Array");
		bridges.setDataStructure(my_array);
		bridges.visualize();



		/*
				S H A P E 	C O L L E C T I O N
		*/
		SymbolCollection sc = new SymbolCollection();

		Rectangle r1 = new Rectangle(0.0f, 0.0f, 25, 25);
		r1.setFillColor("black");
		sc.addSymbol(r1);

		Circle s1 = new Circle(25.0f, 0.0f, 10);
		s1.setFillColor("yellow");
		sc.addSymbol(s1);

		Circle s2 = new Circle(-25.0f, 0.0f, 10);
		s2.setFillColor("yellow");
		sc.addSymbol(s2);

		Circle s3 = new Circle(0.0f, 25.0f, 10);
		s3.setFillColor("yellow");
		sc.addSymbol(s3);

		Circle s4 = new Circle(0.0f, -25.0f, 10);
		s4.setFillColor("yellow");
		sc.addSymbol(s4);

		// set data structure and visualize
		bridges.setTitle("A Symbol Collection");
		bridges.setDataStructure(sc);
		bridges.visualize();


		/*
				C O L O R		G R I D
		*/
		int rows = 30, cols = 30;
		Color purple = new Color("purple");
		Color black = new Color("black");

		ColorGrid cg  = new ColorGrid(rows, cols, purple);

		cg.set(12, 12, black);
		cg.set(12, 18, black);

		for (int i = 0; i < 10; i++) {
			cg.set(18, 10 + i, black);
		}

		// set data structure and visualize
		bridges.setTitle("Color Grid Example");
		bridges.setDataStructure(cg);
		bridges.visualize();
	}
}
