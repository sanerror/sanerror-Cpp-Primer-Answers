#include <iostream>
#include <vector>

int main() {
	std::vector<int> vint{ 1,2,3,4,5 };
	for (auto beg = --vint.cend(); ; --beg){
		std::cout << *beg << " ";
		if (beg == vint.cbegin()) break;
	}	
	return 0;
}