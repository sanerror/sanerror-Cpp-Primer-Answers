#include <iostream>
#include <string>

using namespace std;

int main() {
	string numbers{ "0123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };

	for (string::size_type pos = 0;
	(pos = str.find_first_of(numbers, pos)) != string::npos;++pos)
		cout << str[pos] << " ";
	cout << endl;

	for (string::size_type pos = 0;
	(pos = str.find_first_of(alphabet, pos)) != string::npos;++pos)
		cout << str[pos] << " ";
	cout << endl;

	return 0;
}