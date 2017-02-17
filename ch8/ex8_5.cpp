#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void read(const string&, vector<string>&);

int main() {
	vector<string> vec;
	read("./data/book.txt", vec);
	for (const auto& str : vec) cout << str << endl;
	return 0;
}

void read(const string& fname, vector<string>& vec) {
	ifstream ifs(fname);
	if (ifs) {
		string buf;
		while (ifs >> buf) vec.push_back(buf);
	}
}