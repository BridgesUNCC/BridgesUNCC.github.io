#include "Bridges.h"
#include "Array1D.h"

using namespace bridges;

#define SIZE 17*1000l*1000l

int main(int argc, char **argv) {
	// create Bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
	// title, description
	bridges.setTitle("BREAKING");
	bridges.setDescription("BREAKING");

	// create, populate the array
	Array1D<int> arr (1);

	std::cout<<"This test pipes on purpose more data than the server can handle so as to trigger an error"<<"\n";
	
	// populate the array, with squares of indices
	// use the values to label the elements
	for (int j = 0; j < 1; j++) {
		arr[j] = j * j;
	}

	std::string payload="";
	for (int i=0; i<SIZE; ++i) {
	  payload += " ";
	}
	arr.getElement(0).setLabel(payload);

	try {
	  // visualize
	  bridges.setDataStructure(&arr);
	  bridges.visualize();
	}
	catch (std::string s) {
	  std::cerr<<"Exception: "<<s<<"\n";
	}
	
	return 0;
}
