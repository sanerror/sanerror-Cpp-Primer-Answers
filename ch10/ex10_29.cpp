#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream ifs("./data/book.txt");
	istream_iterator<string> in(ifs), eof;
	vector<string> str;
	copy(in, eof, back_inserter(str));
	copy(str.cbegin(), str.cend(), ostream_iterator<string>(cout, "\n"));
	return 0;
}