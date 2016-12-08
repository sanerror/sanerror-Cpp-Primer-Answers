#include <iostream>
#include <type_traits>

using namespace std;

template <typename T1, typename T2>
auto sum(const T1 &lhs, const T2 &rhs)
-> typename remove_reference<decltype(lhs + rhs)>::type
{
	return (lhs + rhs);
}

int main() {
	double i = 0.35;
	long j = 35;
	cout << sum(i, j) << endl;
	return 0;
}