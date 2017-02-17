#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main() {
	list<int> lint{ 1,2,3,4,5,6 };
	deque<int> de1, de2;
	for (const auto& ele : lint)
		(ele % 2 == 1 ? de1 : de2).push_back(ele);
	for (const auto& ele : de1) cout << ele << " ";
	cout << endl;
	for (const auto& ele : de2) cout << ele << " ";
	return 0;
}