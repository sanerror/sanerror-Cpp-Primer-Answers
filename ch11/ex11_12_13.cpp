#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
	vector<pair<string, int>> vec;
	string str;
	int i;
	while (cin >> str >> i)
		vec.push_back(make_pair(str, i));
	// vec.push_back(pair<string, int>(str, i));
	// vec.push_back({str, i});
	// vec.emplace_back(str, i); 

	for (const auto& ele : vec)
		cout << ele.first << " : " << ele.second << endl;
	return 0;
}