from bridges import *

def generatePerformanceCharts(bridges):
    # TODO:
    # You will be using the LineChart class to plot the performance of 
    # machines of varying capabilities (crudely approximated by clock speed!)
    # as function of input size
    #
    # Review the Line Chart tutorial at 
    # http://bridgesuncc.github.io/tutorials/LineChart.html
    # 

    lc = LineChart()
    lc.title = "Something"
    lc.x_label = "n"
    lc.y_label = "Time in seconds"

    xdata = []
    ydata = []

    # create the function y = 10^4n, assuming 1 Mhz clock. Use the line chart
    # to plot performance (dont use all values of n, use some convenient step
    # size  to go from 1 to 10^4


    # use the setDataSeries() method of LineChart to add the plot to BRIDGES



    # Similarly, create the function y = 5*10^4n, assuming 1 Mhz clock. 

    # use the setDataSeries() method of LineChart to add the plot to BRIDGES


    # Similarly, create the function y = 100*n^2, assuming 1 Mhz clock

    # use the setDataSeries() method of LineChart to add the plot to BRIDGES


    # send the line chart data to the BRIDGES server and visualize
    #bridges.set_data_structure(lc)
    #bridges.visualize()

def main():
    bridges = Bridges(228, "BRIDGES_USER_ID", "BRIDGES_API_KEY")

    bridges.set_title("Big Oh Matters")
    bridges.set_description("Plot Big Oh runtimes on a Bridges Line Chart.")

    generatePerformanceCharts(bridges)

if __name__ == '__main__':
    main()
