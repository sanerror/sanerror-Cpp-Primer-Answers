#include <iostream>
#include "ex14_2_6_9_13_20_22_Sales_data.h"

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main() {
	string str1("hello"), str2("world");
	cout << compare(str1, str2);

	Sales_data sd1("hello"), sd2("world");
	cout << compare(sd1, sd2);
	return 0;
}