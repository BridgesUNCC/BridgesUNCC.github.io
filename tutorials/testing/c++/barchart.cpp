/**
 * Created by Kalpathi Subramanian, 9/15/2024
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "DataSource.h"
#include "BarChart.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace bridges;


int main (int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	BarChart bar;
	bar.setTitle("Hello World BarChart!");
	bar.setSubTitle("Woah!");
	bar.setCategoriesLabel("Continents");
	bar.setValueLabel("Population (in millions)");
	bar.setBarOrientation("horizontal");
	bar.setTooltipSuffix(" millions");

	vector<string> bins{"Africa", "America", "Asia", "Europe"};
	bar.setCategories(bins);

	vector<double> y1{10, 100, 40, 23};
	vector<double> y2{100, 10, 80, 232};
	bar.addDataSeries("year 1", y1);
	bar.addDataSeries("year 2", y2);

	bridges.setDataStructure(bar);
	bridges.visualize();


	return 0;
}
