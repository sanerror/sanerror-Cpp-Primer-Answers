#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; };
int substract(int a, int b) { return a - b; };
int func(int a, int b);

int main() {

	std::vector<decltype(func) *> vec{ add,substract };

	for (auto f : vec) {
		std::cout << f(2, 2) << std::endl;
	}

	return 0;
}