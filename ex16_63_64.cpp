#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>unsigned Count(const vector<T> &vec, T val);
template <> unsigned Count(const vector<const char*> &vec, const char* val);

template <typename T>
unsigned Count(const vector<T> &vec, T val) {
	unsigned count(0);
	for (const auto & elem : vec) {
		if (elem == val)
			++count;
	}
	return count;
}

template <>
unsigned Count(const vector<const char*> &vec, const char* val) {
	unsigned count(0);
	for (const auto & elem : vec) {
		if (strcmp(elem, val) == 0)
			++count;
	}
	cout << "for const char* :";
	return count;
}

int main() {
	vector<double> d{1.2, 2.3, 3.4, 4.5};
	vector<int> i{1, 2, 3, 4, 5};
	vector<string> str{ "pen", "pineapple", "apple", "pen" };

	cout << Count(d, 1.2) << endl;
	cout << Count(i, 2) << endl;
	cout << Count(str, string("pen")) << endl;

	vector<const char*> c{ "hello", "hell", "hey", "hello" };
	const char ch[] = "hello";
	cout << Count(c, ch) << endl;
	return 0;
}