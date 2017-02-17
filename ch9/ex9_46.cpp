#include <iostream>
#include <string>

using namespace std;

string rename(string& name, const string& prev, const string& post) {
	name.insert(0, prev);
	name.insert(name.size(), " "+post);
	return name;
}

int main() {
	string name("Dennis");
	string s = rename(name, "Mr.", "Jr.");
	cout << s << endl;
	return 0;
}