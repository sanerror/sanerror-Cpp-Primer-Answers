#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int add(int i, int j) { return i + j; }

int main() {
	map<string, function<int(int, int)>> binOps = {
		{"+", add},
		{"-", minus<int>()},
		{"*", [](int i, int j) { return i*j; } },
		{"/", divides<int>()},
		{"%", modulus<int>()}
	};

	int left, right;
	string op;
	cin >> left >> op >> right;
	cout << binOps[op](left, right) << endl;
	return 0;
}