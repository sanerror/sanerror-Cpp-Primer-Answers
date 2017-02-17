#include "ex14_45.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Sales_data sd("newbook", 5, 6);
	string str = sd;
	double db = sd;
	cout << str << " " << db << endl;
	return 0;
}