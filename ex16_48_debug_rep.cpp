#include <iostream>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);
string debug_rep(const string &s);
string debug_rep(const char *p);
string debug_rep(char *p);

template <typename T> string debug_rep(const T &t) {
	cout << "Type: const T &t  (";
	ostringstream ret;
	ret << t;
	cout << endl;
	return ret.str();
}

template <typename T> string debug_rep(T *p) {
	cout << "Type: T *p  (";
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else {
		ret << "null pointer";
		cout << endl;
	}
	return ret.str();
}

string debug_rep(const string &s) {
	cout << "Type: string &s  (" << endl;
	return '"' + s + '"';
}

string debug_rep(char *p) {
	cout << "Type: char *p  (";
	return debug_rep(string(p));
}

string debug_rep(const char *p) {
	cout << "Type: const char *p  (";
	return debug_rep(string(p));
}

int main() {
	const char c1[6] = "apple";
	char c2[4] = "pen";
	string* s = new string("");
	debug_rep(string("pen"));
	debug_rep("pineapple");
	debug_rep(s);
	debug_rep(c1);
	debug_rep(c2);
	return 0;
}