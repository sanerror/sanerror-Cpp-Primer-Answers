#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}

int main() {
	vector<string> str{ "pen", "pineapple", "apple", "pen" };
	string::size_type sz(6);
	auto wc = count_if(str.begin(), str.end(), bind(check_size, _1, sz));
	cout << wc << endl;
	return 0;
}