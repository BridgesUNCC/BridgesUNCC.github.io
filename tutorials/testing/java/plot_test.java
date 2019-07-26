import bridges.base.Plot;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;

import java.io.IOException;
import java.util.*;
import java.util.function.Consumer;

public class plot_test {
	
	static Consumer <int[]> sort = arr -> {
		int n = arr.length; 
		  
        // One by one move boundary of unsorted subarray 
        for (int i = 0; i < n-1; i++) 
        { 
            // Find the minimum element in unsorted array 
            int min_idx = i; 
            for (int j = i+1; j < n; j++) 
                if (arr[j] < arr[min_idx]) 
                    min_idx = j; 
  
            // Swap the found minimum element with the first 
            // element 
            int temp = arr[min_idx]; 
            arr[min_idx] = arr[i]; 
            arr[i] = temp; 
        } 
	};
	
	static Consumer <int[]> bubbleSort = arr -> {
		int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
	};

	public static void main(String[] args) throws IOException, RateLimitException, InterruptedException {
		Bridges bridges = new Bridges(1001, "test", "1055982372149");
//		Bridges bridges = new Bridges(0, "kalpathi60", "486749122386");
		bridges.setServer("plotting");
		bridges.setVisualizeJSON(true);
		
		Plot plot = new Plot("Sort Runtime");
		plot.runtime("InsertSort", 100, 10000, sort);
		plot.runtime("bubblesort", 100, 10000, bubbleSort);
		
		bridges.setDataStructure(plot);
		bridges.visualize();
	}

}