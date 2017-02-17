#include <iostream>
#include <vector>

int main() {
	std::vector<int> vint{ 1,2,3,4,5 };
	for (auto beg = vint.crbegin(); beg != vint.crend(); ++beg)
		std::cout << *beg << " ";
	return 0;
}