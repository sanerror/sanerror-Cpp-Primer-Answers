#include "ex13_44.h"

using namespace std;

int main() {
	String s1;
	String s2 = "hello!";
	String s3 = s2;
	s1 = s2;

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	cout << s1.size() << endl;
	return 0;
}