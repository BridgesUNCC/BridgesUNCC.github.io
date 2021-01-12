#include <iostream>
#include <fstream>

using namespace std;

int main() {

ifstream infile ("map.txt");

int num_verts;
infile >> num_verts;

cout << num_verts << endl;


return 0;
}
