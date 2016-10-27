#include <iostream>
#include <string>

using namespace std;

string& rename(string& name, const string& prev, const string& post) {
	name.insert(name.begin(), prev.begin(), prev.end());
	name.append(" "+post);
	return name;
}

int main() {
	string name("Dennis");
	string s = rename(name, "Mr.", "Jr.");
	cout << s << endl;
	return 0;
}