#include <iostream>
#include "ex13_26.h"

using namespace std;

int main() {
	StrBlob b1;
	StrBlob b2 = { "a","an","one" };
	b1 = b2;
	b2.push_back("about");
	cout << "b2 size: " << b2.size() << endl;
	cout << "b2 front&back: " << b2.front() << "&" << b2.back()
		<< endl;
	cout << "b1 size: " << b1.size() << endl;
	cout << "b1 front&back: " << b1.front() << "&" << b1.back()
		<< endl;

	StrBlob b3 = b2;
	b3.push_back("next");
	cout << "b3 front&back: " << b3.front() << "&" << b3.back()
		<< endl;

	return 0;
}