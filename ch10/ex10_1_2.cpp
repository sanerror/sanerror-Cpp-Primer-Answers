#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,3,2,1 };
	cout << "ex10_1:" << count(v.begin(), v.end(), 2) << endl;

	list<string> l{ "pen", "pineapple", "apple", "pen" };
	cout << "ex10_2:" << count(l.begin(), l.end(), "apple") << endl;

	return 0;
}