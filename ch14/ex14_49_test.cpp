#include "ex14_49.h"

using namespace std;

int main() {
	Date d(25, 12, 2015);
	bool b = static_cast<bool>(d);
	cout << b;
	return 0;
}