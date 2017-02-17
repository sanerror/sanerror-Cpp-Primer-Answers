#include <iostream>
#include <string>
#include "ex13_27.h"

using namespace std;

int main() {
	HasPtr h("hello world!");
	HasPtr h2 = h;
	h = "hi!";
	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;
	return 0;
}