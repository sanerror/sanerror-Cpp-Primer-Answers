#include <iostream>
#include "ex16_22.h"

using namespace std;

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main() {
	ifstream infile("../data/TheLittlePrince.txt");
	runQueries(infile);
	return 0;
}