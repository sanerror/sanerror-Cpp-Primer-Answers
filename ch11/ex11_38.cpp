#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> buildMap(ifstream& map_file){
	unordered_map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value)){
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for" + key);
	}
	return trans_map;
}

const string& transform(const unordered_map<string, string>& trans_map, const string& word){
	auto map_it = trans_map.find(word);
	if (map_it != trans_map.end())
		return map_it->second;
	else
		return word;
}

void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map = buildMap(map_file);
	string line;
	while (getline(input, line)){
		istringstream stream(line);
		bool firstword = true;
		string word;
		while (stream >> word){
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(trans_map, word);
		}
		cout << endl;
	}
}

int main(int argc, char **argv){
	ifstream map_file(argv[1]), input(argv[2]);
	word_transform(map_file, input);
	return 0;
}