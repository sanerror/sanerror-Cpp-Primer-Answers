#include <iostream>
#include "ex14_2_Sales_data.h"

using namespace std;

int main() {
	Sales_data s1 = { "A1", 5, 4 };
	Sales_data s2 = { "B2", 1, 199 };
	Sales_data s3;
	cin >> s3;
	Sales_data total;
	total += s1;
	cout << s1;
	return 0;
}