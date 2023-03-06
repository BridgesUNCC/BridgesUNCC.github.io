#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/GutenbergBook.h"

using namespace bridges;


// this program illustrates how to access the Gutenberg book meta data
int main(int argc, char **argv) {

	// create bridges object
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");


	// set title
	bridges.setTitle("Accessing Gutenberg Book Collection Meta Data");

	// read the Gutenberg book data
	DataSource ds (&bridges);
	vector<GutenbergBook> book_list = ds.getGutenbergBookData();

	// print the first book record
	cout << "Guttenberg Book Data:"
		<< "\tAuthor: "  << book_list[0].getAuthorName() << endl
		<< "\tAuthor Birth: "  << book_list[0].getAuthorBirth() << endl
		<< "\tAuthor Death: "  << book_list[0].getAuthorBirth() << endl
		<< "\tTitle: "  << book_list[0].getTitle() << endl;
	cout << "\tLanguage: ";
	for (auto& i : book_list[0].getLang())
		cout << i << ",";
	cout << endl << "\tSubject: ";
	for (auto& i : book_list[0].getSubject())
		cout << i << ",";
	cout << endl << "\tNum Downloads: "  << book_list[0].getNumDownloads() << endl
		<< "\tNum Words: "  << book_list[0].getNumWords() << endl
		<< "\tNum Difficult Words: "  << book_list[0].getNumDifficultWords() << endl
		<< "\tNum Sentences: "  <<  book_list[0].getNumSentences() << endl
		<< "\tNum Characters: "  <<  book_list[0].getNumChars() << endl;

	for (int k = 0; k < book_list.size(); k++) {
		GutenbergBook b = book_list[k];
	}


	return 0;
}
