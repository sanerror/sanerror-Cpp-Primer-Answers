#include <iostream>
#include "ex14_37.h"
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

int main() {
	vector<int> box{ 1,5,3,7,8,9,4,5,5,3 };
	checkEqual ce;
	auto temp = bind(ce, _1, 5);
	replace_if(box.begin(), box.end(), temp, 0);
	for (auto ele : box)
		cout << ele;
	return 0;
}