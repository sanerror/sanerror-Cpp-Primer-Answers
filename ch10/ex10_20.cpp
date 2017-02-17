#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<string> str{"pen", "pineapple", "apple", "pen"};
	string::size_type sz(6);
	auto num = count_if(str.begin(), str.end(), [&sz](const string& v) {return v.size() >= sz;});
	cout << num << endl;
	return 0;
}