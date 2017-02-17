#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,3,2,1 };
	cout << "ex10_1:" << accumulate(v.begin(), v.end(), 0) << endl;

//	list<string> l{ "pen", "pineapple", "apple", "pen" };
//	cout << "ex10_2:" << count(l.begin(), l.end(), "apple") << endl;

	return 0;
}