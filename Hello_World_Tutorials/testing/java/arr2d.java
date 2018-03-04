import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception{

						//create the Bridges object
		Bridges bridges = new Bridges(1, "486749122386", "kalpathi60");

						//  for 2D array 5x5
						// set dimensions, create array
		int[] dims = {4, 4, 1};
		Array<Integer> my_array = new Array<Integer> (2, dims);

						// populate the array
		for (int row = 0; row < dims[1]; row++){
			for (int col = 0; col < dims[0]; col++){
				my_array.getValue(row, col).setLabel("El " + String.valueOf(row*dims[0]+col));
			}
		}

						// color some of the elements

		my_array.getValue(0,0).getVisualizer().setColor("red");
		my_array.getValue(0,3).getVisualizer().setColor("green");
		my_array.getValue(3,0).getVisualizer().setColor("blue");
		my_array.getValue(3,3).getVisualizer().setColor("magenta");
		my_array.getValue(1,1).getVisualizer().setColor("cyan");
		my_array.getValue(2,2).getVisualizer().setColor("yellow");

							//set visualizer type
		bridges.setDataStructure(my_array);

							// visualize the array
		bridges.visualize();
	}
}
