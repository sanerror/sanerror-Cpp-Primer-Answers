#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<double> v{ 1.1,2.5,3.5 };
	cout << "ex10_1:" << accumulate(v.begin(), v.end(), 0) << endl;
	//output:6

	return 0;
}