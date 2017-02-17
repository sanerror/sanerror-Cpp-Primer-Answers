#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int> vec(ia, end(ia));
	list<int> lis(ia, end(ia));

	for (auto iter = vec.begin(); iter != vec.end();)
		if (*iter & 0x1)
			iter = vec.erase(iter);
		else
			++iter;

	for (auto iter = lis.begin(); iter != lis.end();)
		if (!(*iter & 0x1))
			iter = lis.erase(iter);
		else
			++iter;

	cout << "list : ";
	for (auto i : lis) cout << i << " ";
	cout << "\nvector : ";
	for (auto i : vec) cout << i << " ";
	cout << std::endl;

	return 0;
}