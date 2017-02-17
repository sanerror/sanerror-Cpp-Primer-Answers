#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, char **argv){
	using line_no = vector<string>::size_type;
	ifstream ifs(argv[1]);
	string keyword(argv[2]);
	vector<string> file;
	string line;
	set<line_no> lines;

	while (getline(ifs, line)){
		file.push_back(line);
		int n = file.size() - 1;
		istringstream ld(line);
		string word;
		while (ld >> word){
			if (word == keyword)
				lines.insert(n);
		}
	}

	cout << keyword << " occurs " << lines.size() 
		<< ((lines.size() > 1) ? " times" : " time") << endl;
	for (auto ele : lines)
		cout << "\t(line " << ele + 1 << ") " << file[ele] << endl;
	return 0;
}