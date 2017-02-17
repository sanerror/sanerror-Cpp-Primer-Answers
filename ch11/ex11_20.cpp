#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count.insert({ word, 0 }).first->second;
	for (const auto& elem : word_count)
		cout << elem.first << " : " << elem.second << "\n";
	return 0;
}