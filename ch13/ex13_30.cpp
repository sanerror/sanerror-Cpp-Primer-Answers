#include <iostream>
#include "ex13_30_31.h"

using namespace std;

int main() {
	HasPtr h("hello!");
	HasPtr h2(h);
	HasPtr h3 = h;
	h2 = "hi!";
	h3 = "hihi!";
	swap(h2, h3);
	cout << *h << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;

	h = h3;
	cout << *h << endl;
	return 0;
}