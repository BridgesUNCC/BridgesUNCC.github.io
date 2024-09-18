import bridges.base.Plot;
import bridges.base.BenchMarking;
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
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
    //bridges.setVisualizeJSON(true);
		
		Plot plot = new Plot("Sort Runtime");
		BenchMarking bench = new BenchMarking(plot);
		bench.run("InsertSort", 100, 10000, sort);
		bench.run("bubblesort", 100, 10000, bubbleSort);
		
		bridges.setDataStructure(plot);
		bridges.visualize();
	}

}
