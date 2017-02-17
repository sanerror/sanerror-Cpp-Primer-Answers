#include <iostream>

using namespace std;

int main() {

	auto func = [](double a, double b) -> int {return a + b;};
	cout << func(1.5, 3.5);
	return 0;
}