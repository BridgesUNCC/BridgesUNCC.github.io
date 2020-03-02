import bridges.base.LineChart;
import bridges.benchmark.SortingBenchmark;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;

import java.io.IOException;
import java.util.*;
import java.util.function.Consumer;

public class sortingbenchmark {

	static Consumer <int[]> sort = arr -> {
		int n = arr.length;

		// One by one move boundary of unsorted subarray
		for (int i = 0; i < n - 1; i++) {
			// Find the minimum element in unsorted array
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;

			// Swap the found minimum element with the first
			// element
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	};

	static Consumer <int[]> javasort = arr -> {
		Arrays.sort(arr);

	};


	static Consumer <int[]> bubbleSort = arr -> {
		int n = arr.length;
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
	};

	public static void main(String[] args) throws IOException, RateLimitException, InterruptedException {
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		//bridges.setVisualizeJSON(true);

		LineChart plot = new LineChart();
		plot.setTitle("Sort Runtime");
		SortingBenchmark bench = new SortingBenchmark(plot);
		bench.linearRange(100, 10000, 20);
		bench.setTimeCap(1000 * 1); //1 seconds
		bench.run("InsertSort", sort);
		bench.run("bubblesort", bubbleSort);
		bench.run("javasort", javasort);

		bridges.setDataStructure(plot);
		bridges.visualize();

		LineChart plot2 = new LineChart();
		plot2.setTitle("Sort Runtime");
		SortingBenchmark bench2 = new SortingBenchmark(plot2);
		bench2.geometricRange(100, 1000000, 1.5);
		bench2.setTimeCap(1000 * 1); //1 seconds
		bench2.run("InsertSort", sort);
		bench2.run("bubblesort", bubbleSort);
		bench2.run("javasort", javasort);

		bridges.setDataStructure(plot2);
		bridges.visualize();
	}

}
