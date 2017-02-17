#include <iostream>
#include "ex14_5_8_12_15_17_19_24_25_Date.h"

using namespace std;

int main() {
	Date date1(25,12,2010);
	Date date2;
	cin >> date2;
	cout << date1;
	cout << (date1 == date2) << (date1 != date2) << (date1<date2)
		<< (date1>date2);
	return 0;
}
