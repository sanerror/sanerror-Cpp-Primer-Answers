#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	multimap<string, string> houses;
	cout << "Enter your name and your last_name :" << endl;
	for (string house, name; cin >> name >> house; houses.emplace(house, name));
	for (const auto& ele : houses)
		cout << ele.second << " " << ele.first << endl;
	return 0;
}