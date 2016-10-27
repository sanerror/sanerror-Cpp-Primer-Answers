#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	deque<string> dstr;
	string str;
	while (cin >> str) dstr.push_back(str);
	for (auto a = dstr.begin(); a != dstr.end(); ++a)
		cout << (*a) << " ";
	return 0;
}