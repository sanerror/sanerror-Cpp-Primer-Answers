#include <iostream>
#include <unordered_set>
#include "ex14_2_6_9_13_20_22_Sales_data.h"

namespace std {
	template <>
	struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument;
		size_t operator()(const Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				hash<unsigned>()(s.units_sold) ^
				hash<double>()(s.revenue);
		}
	};
}

using namespace std;

int main() {
	unordered_multiset<Sales_data> SDset;
	SDset.insert(Sales_data("x-1", 2, 99));
	SDset.insert(Sales_data("x-2", 3, 98));
	for (auto ele : SDset)
		print(cout, ele);
	return 0;
}