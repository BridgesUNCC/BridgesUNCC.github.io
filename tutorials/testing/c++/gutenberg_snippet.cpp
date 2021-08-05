#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/GutenbergBook.h"

using namespace bridges;


// this program illustrates how to access the Gutenberg book meta data
int main(int argc, char **argv) {

	// create bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");


	// set title
	bridges.setTitle("Accessing Gutenberg Book Collection Meta Data");

	// read the Gutenberg book data
	DataSource ds (&bridges);

	cout << "Retrieving a single book's metadata\n";

	GutenbergBook b = ds.getGutenbergBookMetaData(2701);// Moby Dick
	cout << "\n\tTitle: "  << b.getTitle() << "\n";
	cout << "\tId: " << b.getId();
	cout << "\n\tLanguage:" << b.getLang();
	cout << "\n\tAuthors:";
	for (auto& k: b.getAuthors()) 
		cout << k << ",";

	cout << "\nRetrieving books  by title: Pride and Prejudice"  << endl;
	vector<GutenbergBook> gbook_list = ds.getGutenbergBookMetaData("Pride and Prejudice", "title");
	cout << "Print the first 3 books of search results\n";
	int n = 0;
	for (auto& b : gbook_list) {
		cout << "\tId: " << b.getId();
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle() << "\n";
		if (++n == 3) break;
	}
	gbook_list.clear();

	cout << "Retrieving books by Language: English"  << endl;
	gbook_list = ds.getGutenbergBookMetaData("en", "language");
	cout << "Print the first 3 books of search results\n";
	n = 0;
	for (auto& b : gbook_list) {
		cout << "\tId: " << b.getId();
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle() << "\n";
		if (++n == 3) break;
	}
	gbook_list.clear();

	cout << "Retrieving books by Date: 2018"  << endl;
	gbook_list = ds.getGutenbergBookMetaData("2018-01-01", "date");
	cout << "Print the first 3 books of search results\n";
	n = 0;
	for (auto& b : gbook_list) {
		cout << "\tId: " << b.getId();
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle();
		cout << "\n\tDate: "  << b.getDateAdded() << "\n";
		if (++n == 3) break;
	}
	gbook_list.clear();

	cout << "\n";
	cout << "\nRetrieving books  by Author: Mark Twain"  << endl;
	gbook_list = ds.getGutenbergBookMetaData("Mark Twain", "author");
	cout << "Print the first 3 books of search results\n";
    n = 0;
	for (auto& b : gbook_list) {
		cout << "\tId: " << b.getId();
		cout << "\n\tTitle: "  << b.getTitle();
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		if (++n == 3) break;
    	cout << "\n";
    }
    cout << "\n";

	cout << "Testing  Getting Moby Dick text..\n";

	string moby_dick_str = ds.getGutenbergBookText(2701);

	cout << "Moby Dick: Size : " << moby_dick_str.size() << "chars.\n";
	cout << "First 300 chars..\n";
	for (int k = 0; k < 300; k++) 
		cout << moby_dick_str[k];
	cout << "\n";
	
	return 0;
}
