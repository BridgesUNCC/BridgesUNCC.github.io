import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception{

						//create the Bridges object
		Bridges<String, Integer> bridges = 
					new Bridges<String, Integer>(2, "YOUR_API_KEY", "YOUR_USER_ID");

						//  for 2D array 5x5
		int columns = 5;
		int rows = 5;
		int[] dims = {columns, rows, 1};
		Array<Integer> my_array = new Array<Integer> (2, dims);

		int k = 0;
		for (int row = 0; row < rows; row++){
			for (int col = 0; col < columns; col++){
				my_array.setValue(row, col,  new Element<Integer>(String.valueOf(k), k*k));
				k++;
			}
		}

		my_array.getValue(0,0).getVisualizer().setColor("green");
		my_array.getValue(0,4).getVisualizer().setColor("blue");
		my_array.getValue(2,2).getVisualizer().setColor("cyan");
		my_array.getValue(4,0).getVisualizer().setColor("magenta");
		my_array.getValue(4,4).getVisualizer().setColor("yellow");

							//set visualizer type
		bridges.setDataStructure(my_array);

							// visualize the array
		bridges.visualize();
	}
}
