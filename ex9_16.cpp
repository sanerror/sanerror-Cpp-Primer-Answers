#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
	list<int> ilst{ 1, 2, 3 };
	vector<int> ive{ 1, 2, 3 };
	vector<int> ive2{ 1, 2 };

	cout << (vector<int>(ilst.begin(), ilst.end()) == ive) << endl;
	cout << (vector<int>(ilst.begin(), ilst.end()) == ive2) << endl;

	return 0;
}