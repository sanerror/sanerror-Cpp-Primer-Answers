#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

istream& func(istream& is) {
	string buf;
	while (is >> buf) {
		cout << buf << endl;
	}
	is.clear();
	return is;
}

int main() {
	ifstream in("./data/book.txt");
	if (!in) {
		cerr << "No data?" << endl;
		return -1;
	}

	vector<string> str;
	string line;
	while (getline(in, line)) str.push_back(line);

	for (auto& ele : str) {
		istringstream iss(ele);
		string word;
		while (iss >> word) cout << word << endl;
	}
	return 0;
}