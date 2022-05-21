#include <iostream>
#include <vector>
#include <cmath>
#include "LineChart.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

void task1(Bridges * bridges) {
  LineChart lc = LineChart();
  lc.setTitle("Something");
  lc.setXLabel("n");
  lc.setYLabel("Time in Seconds");

  vector<double> xData;
  vector<double> yData;

  // create the function y = 10^4n, assuming 1 Mhz clock
  for (int i = 1; i < 100000; i += 1000) {
    double n = (double)i;
    double t = (double)10000.0 * i / (1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("10^4 n at 1MHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = 5*10^4n, assuming 1 Mhz clock
  for (int i = 1; i < 100000; i += 1000) {
    double n = (double)i;
    double t = (double)(5 * 10000.0 * i) / (1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("5.10^4 n at 1MHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = 100*n^2, assuming 1 Mhz clock
  for (int i = 1; i < 100000; i += 1000) {
    double n = (double)i;
    double t = (double)(100 * i * i) / (100.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("10^2 n^2 at 1MHz", xData, yData);

  bridges->setDataStructure(lc);
  bridges->visualize();
}

void task2(Bridges * bridges) {
  LineChart lc = LineChart();
  lc.setTitle("Something");
  lc.setXLabel("n");
  lc.setYLabel("Time in Seconds");

  vector<double> xData;
  vector<double> yData;

  // create the function y = 10^4n, assuming 1 Mhz clock
  for (int i = 1; i < 10000; i += 300) {
    double n = (double)i;
    double t = (double)10000.0 * i / (1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("10^4 n at 1MHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = 100*n^2, assuming 100 Mhz clock
  for (int i = 1; i < 10000; i += 300) {
    double n = (double)i;
    double t = (double) (100.0 * i * i) / (100.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("100 n^2 at 100MHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = n^4, assuming 10 Ghz clock
  for (int i = 1; i < 10000; i += 100) {
    double n = (double)i;
    double t = (double) (i * i * i * i) / (10.0 * 1000.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("n^4 at 10GHz", xData, yData);

  bridges->setDataStructure(lc);
  bridges->visualize();
}

void task3(Bridges * bridges) {
  LineChart lc = LineChart();
  lc.setTitle("Something");
  lc.setXLabel("n");
  lc.setYLabel("Time in Seconds");

  vector<double> xData;
  vector<double> yData;

  // create the function y = 10000*n, assuming 1 Mhz clock
  for (int i = 1; i < 50; i += i + 3) {
    double n = (double)i;
    double t = (double)10000.0 * i / (1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("10^4 n at 1MHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = 100*n^2, assuming 100 Mhz clock
  for (int i = 1; i < 50; i += i + 3) {
    double n = (double)i;
    double t = (double) (100.0 * i * i) / (100.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("100 n^2 at 100MHz", xData, yData);

  xData.clear();
  yData.clear();

  for (int i = 1; i < 50; i += i + 3) {
    double n = (double)i;
    double t = (double) (i * i * i * i) / (10.0 * 100.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("n^4 at 10GHz", xData, yData);

  xData.clear();
  yData.clear();

  // create the function y = 2^n, assuming 1 Phz clock
  for (int i = 1; i < 50; i += i + 3) {
    double n = (double)i;
    double t = (double) (pow(2, n)) / (1000.0 * 1000.0 * 1000.0 * 1000.0);
    xData.push_back(i);
    yData.push_back(t);
  }

  lc.setDataSeries("2^n at 1PHz", xData, yData);

  bridges->setDataStructure(lc);
  bridges->visualize();
}


int main() {
  // initialize BRIDGES
  Bridges *bridges = new Bridges(128, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

  bridges->setTitle("Big Oh Matters");

  task1(bridges);
  task2(bridges);
  task3(bridges);

  return 0;
}
