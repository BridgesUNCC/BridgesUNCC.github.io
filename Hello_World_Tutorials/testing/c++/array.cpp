#include <iostream>
#include <string>

using namespace std;

#include "Bridges.h"
#include "Element.h"
#include "Array.h"

using namespace bridges;
int main() {
                        // initialize BRIDGES with credentials
    Bridges::initialize(0, "YOUR_USER_ID", "YOUR API KEY");

                        // allocate a 1D array
    int dims[3] = {10, 1, 1};
    Array<int> *arr = new Array<int>(1, dims);

    for (int j = 0; j < dims[0]; j++)
        arr->getValue(j).setLabel("El " + to_string(j));

                        // color the elements of the array
    arr->getValue(0).getVisualizer()->setColor(Color("red"));
    arr->getValue(1).getVisualizer()->setColor(Color("green"));
    arr->getValue(2).getVisualizer()->setColor(Color("blue"));
    arr->getValue(3).getVisualizer()->setColor(Color("cyan"));
    arr->getValue(4).getVisualizer()->setColor(Color("magenta"));
    arr->getValue(5).getVisualizer()->setColor(Color("yellow"));
    arr->getValue(6).getVisualizer()->setColor(Color("red"));
    arr->getValue(7).getVisualizer()->setColor(Color("green"));
    arr->getValue(8).getVisualizer()->setColor(Color("blue"));
    arr->getValue(9).getVisualizer()->setColor(Color("black"));


                        // set title
    Bridges::setTitle("Array Example");
                        // tell BRIDGES what data structure you are using
    Bridges::setDataStructure(arr);
                        // visualize
    Bridges::visualize();

    return 0;
}
