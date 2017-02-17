#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename P>
void print(P p1, P p2) {
	cout << p1 << " " << p2 << endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main() {
	string s1("pen"), s2("pineapple");
	//print(s1, s2);
	void (*f)(string, string) = print;
	flip(f, s1, s2);
	return 0;
}