#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

int main() {
	vector<string> str{"pen", "pineapple", "apple", "pen"};
	elimDups(str);
	for (const string& i : str) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}