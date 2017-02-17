#include <iostream>
#include <vector>
#include <algorithm>
#include "ex13_30_31.h"

using namespace std;

int main() {
	vector<string> vs{ "b","a","f","c" };
	vector<HasPtr> vh;
	for (const string& ele : vs)
		vh.push_back(ele);
	for (const auto& ele : vh)
		cout << *ele << " ";
	cout << endl;
	sort(vh.begin(), vh.end());
	for (const auto& ele : vh)
		cout << *ele << " ";
	cout << endl;
	return 0;
}