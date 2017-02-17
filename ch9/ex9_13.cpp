#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
	list<int> lst(4,5);
	vector<int> veci(4,4);

	vector<double> vecd(veci.begin(), veci.end());
	vector<double> vecd2(lst.begin(), lst.end());
	
	for (const auto& i : vecd) cout << i;
	cout << endl;
	for (const auto& i : vecd2) cout << i;

	return 0;
}