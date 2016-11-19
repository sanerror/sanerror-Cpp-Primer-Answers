#include "ex14_38.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char **argv) {
	ifstream file(argv[1]);
	string str;
	checkLength cl(1, 9);
	map<int, int> mii;
	while (file >> str) {
		++mii[cl(str)];
	}
	for (int i = 0; i != 2; ++i) {
		cout << mii[i] << " ";
	}
	return 0;
}