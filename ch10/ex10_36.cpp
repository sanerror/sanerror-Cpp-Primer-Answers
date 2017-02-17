#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vint{ 1,2,3,4,0,5 };
	auto i = find(vint.crbegin(), vint.crend(), 0);
	std::cout << distance(i,vint.crend()) << std::endl;
	return 0;
}