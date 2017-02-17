#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

void add_home(map<string, vector<pair<string, string>>>& homes, const string& new_house){
	homes[new_house];
}

void add_mem_bir(map<string, vector<pair<string, string>>>& homes, const string& house,
	const string& name, const string& bir){
	homes[house].push_back({name, bir});
}

int main(){
	map<string, vector<pair<string, string>>> homes;
	string house, name, line, bir;
	cout << "Enter house names & member names & birthdays?" << endl;
	while (getline(cin, line)){
		istringstream record(line);
		record >> house;
		add_home(homes, house);
		while (record >> name >> bir)
			add_mem_bir(homes, house, name, bir);
	}
	for (const auto& ele : homes){
		cout << ele.first << " : ";
		for (const auto& ele2 : ele.second)
			cout << ele2.first << ":" << ele2.second << " ";
		cout << endl;
	}
	return 0;
}