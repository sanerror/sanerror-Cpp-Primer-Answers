#include <iostream>
#include "ex12_2.h"

using namespace std;

int main(){
	StrBlob sb{ "hello", "world" };
	const StrBlob csb{ "const", "hello", "world", "aha" };

	cout << "sb : " << sb.front() << " " << sb.back() << endl;
	cout << "csb : " << csb.front() << " " << csb.back() << endl;
	
	return 0;
}