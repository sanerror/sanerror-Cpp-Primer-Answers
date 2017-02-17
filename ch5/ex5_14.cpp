#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string pre_str, str, max_str;
	int i{ 1 }, max_i{ 0 };
	while (cin >> str) {
		if (str == pre_str) {
			++i;
		}
		else {
			i = 1;
			pre_str = str;
		}

		if (i > max_i) {
			max_str = str;
			max_i = i;
		}
	}
	if (max_i > 1) {
		cout << max_str << " " << max_i << endl;
	}
	return 0;

}