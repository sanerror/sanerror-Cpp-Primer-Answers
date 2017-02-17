#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
	list<const char*> l{"cxy", "sanerror", "black"};

	//vector<string> svec(l.cbegin(), l.cend());
	vector<string> svec;
	svec.assign(l.cbegin(), l.cend());

	for (const auto& i : svec) cout << i << " ";
	cout << endl;

	return 0;
}