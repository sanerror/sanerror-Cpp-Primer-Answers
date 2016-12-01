#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename Itr, typename Val>
	Itr Find(Itr i1, Itr i2, const Val &v3) {
		for (Itr i = i1; i != i2; ++i) {
			if (*i == v3) return i;
		}
		return i2;
	}

template <typename T, unsigned N>
void Print(const T (&a)[N]) {
	for (auto iter = begin(a); iter != end(a); ++iter)
		cout << *iter << " ";
	cout << endl;
}

template <typename T, unsigned N>
const T* Begin(const T (&a)[N]) {
	return a;
}

template <typename T, unsigned N>
const T* End(const T(&a)[N]) {
	return a+N;
}

template <typename T, unsigned N>
constexpr int arr_size(const T(&a)[N]) {
	return N;
}

int main() {
	vector<int> vecint{ 2,3,4,5,7 };
	list<string> listr{ "pen", "pine", "apple", "hell", "counting"};

	auto i = Find(vecint.begin(), vecint.end(), 3);
	cout << *i << endl;
	auto j = Find(listr.begin(), listr.end(), "apple");
	cout << *j << endl;

	int in[5]{ 1,2,3,4,5 };
	string str[5]{ "hello", "world" };

	Print(in);
	Print(str);
	cout << *Begin(in) << " " << *End(str) << endl;
	cout << arr_size(in) << endl;
	return 0;
}