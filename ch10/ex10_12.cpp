#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data & s1, const Sales_data & s2) {
	return s1.isbn() < s2.isbn();
}

int main() {
	Sales_data d1("a"), d2("aa"), d3("ab"), d4("bb");
	vector<Sales_data> v{ d1,d4,d3,d2,d4 };
	stable_sort(v.begin(), v.end(), compareIsbn);
	for (const Sales_data& i : v) {
		cout << i.isbn() << " ";
	}
	cout << endl;
	return 0;
}