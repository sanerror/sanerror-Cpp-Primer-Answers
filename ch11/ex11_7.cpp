#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void add_home(map<string, vector<string>>& homes, const string& new_house){
	homes[new_house];
}

void add_mem(map<string, vector<string>>& homes, const string& house,
	const string& name){
	homes[house].push_back(name);
}

int main(){
	map<string, vector<string>> homes;
	string house, name, line;
	cout << "Enter house names & member names?" << endl;
	while (getline(cin, line)){
		istringstream record(line);
		record >> house;
		add_home(homes, house);
		while (record >> name)
			add_mem(homes, house, name);
	}
	for (const auto& ele : homes){
		cout << ele.first << " : ";
		for (const auto& ele2 : ele.second)
			cout << ele2 << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}