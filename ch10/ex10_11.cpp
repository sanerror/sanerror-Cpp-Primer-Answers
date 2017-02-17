#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isShorter(const string & s1, const string & s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

int main() {
	vector<string> str{ "pineapple", "pen", "apple", "pen" };
	elimDups(str);
	stable_sort(str.begin(), str.end(), isShorter);
	for (const string& i : str) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}