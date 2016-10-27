#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin(),
		iter2 = lst1.end();
	return (iter1 != iter2);
	return 0;
}