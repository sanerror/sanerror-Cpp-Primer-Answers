#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> ia{ 1,2,3,4,8,11,56 };
	auto pre = ia.before_begin();
	auto nx = ia.begin();

	while (nx != ia.end()) {
		if (*nx & 0x1)
			nx = ia.erase_after(pre);
		else {
			pre = nx;
			++nx;
		}
	}

	for (const auto& i : ia) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}