#include <iostream>
#include <vector>
#include <cmath>
#include "LineChart.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main() {
  // initialize BRIDGES
  Bridges bridges(128, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

  bridges.setTitle("UNCC Workshop: Complexity and Big Oh Matters!");

  // TODO:
  // You will be using the LineChart class to plot the performance of 
  // machines of varying capabilities (crudely approximated by clock speed!)
  // as function of input size
  //
  // Review the Line Chart tutorial at 
  // http://bridgesuncc.github.io/tutorials/LineChart.html


  LineChart lc = LineChart();
  lc.setTitle("Something");
  lc.setXLabel("n");
  lc.setYLabel("Time in Seconds");

   vector<double> xData, yData;

  // create the function y = 10^4n, assuming 1 Mhz clock. Use the line chart
  // to plot performance (dont use all values of n, use some convenient step
  // size  to go from 1 to 10^4


  // use the setDataSeries() method of LineChart to add the plot to BRIDGES



  // Similarly, create the function y = 5*10^4n, assuming 1 Mhz clock. 

  // use the setDataSeries() method of LineChart to add the plot to BRIDGES


  // Similarly, create the function y = 100*n^2, assuming 1 Mhz clock

  // use the setDataSeries() method of LineChart to add the plot to BRIDGES


  // send the line chart data to the BRIDGES server and visualize

  // bridges.setDataStructure(&lc);
  // bridges.visualize();
}


