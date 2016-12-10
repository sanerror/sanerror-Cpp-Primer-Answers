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

template <typename T>
ostream& print(ostream &os, const T &t)
{
	return os << t << std::endl;
}

template <typename T, typename ... Args>
ostream& print(ostream &os, const T &t, const Args &...args) {
	os << t << ",";
	return print(os, args...);
}


template <typename ... Args>
ostream &errorMsg(ostream &os, const Args &... rest) {
	return print(os, debug_rep(rest)...);
}

int main() {
	errorMsg(std::cout, "hello", new std::string("hi"));
	return 0;
}