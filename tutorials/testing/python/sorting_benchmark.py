from bridges import *
from bridges.sorting_benchmark import *

def sort(arr):
    n = len(arr)

    for i in range(n-1):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        temp = arr[min_idx]
        arr[min_idx] = arr[i]
        arr[i] = temp

def pythonsort(arr):
    arr.sort()

def bubblesort(arr):
    n = len(arr)

    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp

def main():

    # create the Bridges object, set credentials
    bridges = Bridges(ASSIGNMENT_NUMBER, "USER_ID", "API_KEY")

    bridges.set_title("Sorting Benchmark")
    bridges.set_description("Plot the performance of sorting algorithms using Bridges Line Chart.")

    plot = LineChart()
    plot.title = "Sort Runtime"
    bench = SortingBenchmark(plot)
    bench.linear_range(100, 10000, 20)
    bench.time_cap = 1000*1
    bench.run("insert sort", sort)
    bench.run("bubble sort", bubblesort)
    bench.run("python sort", pythonsort)

    bridges.set_data_structure(plot)
    bridges.visualize()

    plot2 = LineChart()
    plot2.title = "Sort Runtime"
    bench2 = SortingBenchmark(plot2)
    bench2.geometric_range(100, 1000000, 1.5)
    bench2.time_cap = 1000*1

    bench2.run("insert sort", sort)
    bench2.run("bubble sort", bubblesort)
    bench2.run("python sort", pythonsort)    
    
    bridges.set_data_structure(plot2)
    bridges.visualize()


if __name__ == "__main__":
    main()
