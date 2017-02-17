#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool judge(const string & s1) {
	return s1.size() < 5;
}

int main() {
	vector<string> str{ "pen","pineapple","apple","pen" };
	auto judge_begin = partition(str.begin(), str.end(), judge);
	while (judge_begin != str.end()) {
		cout << *judge_begin << " ";
		++judge_begin;
	}
	cout << endl;
	return 0;
}