#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
	std::vector<int> vint{ 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> lint;
	copy(vint.crbegin() + 3, vint.crbegin() + 8, std::back_inserter(lint));
	for (const auto& i : lint)
		std::cout << i << std::endl;
	return 0;
}