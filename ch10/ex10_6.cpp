#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> num(10,1);
	fill_n(num.begin(), 10, 0);
	for (const int& i : num)
		cout << i << " ";
	return 0;
}