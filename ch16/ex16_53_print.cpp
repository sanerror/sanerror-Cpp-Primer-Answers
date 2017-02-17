#include <iostream>
using std::ostream;

#include <string>

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
/*
int main() {
	print(std::cout, "hi");
	print(std::cout, "hello", 11, 11.5);
	print(std::cout, true, "hey", 35, 11.5, 'a');
	return 0;
}
*/
