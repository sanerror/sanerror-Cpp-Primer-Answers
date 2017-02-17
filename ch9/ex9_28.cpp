#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void insert(forward_list<string>& fst, const string& to_find, const string& to_add);

int main() {
	forward_list<string> fst{ "pen", "pineapple", "apple", "pen" };
	insert(fst, "pen", "and");
	for (auto& i : fst)
		cout << i << " ";
	cout << endl;
	return 0;
}

void insert(forward_list<string>& fst, const string& to_find, const string& to_add) {
	auto prev = fst.before_begin();
	for (auto iter = fst.begin(); iter != fst.end(); prev = iter++) {
		if (*iter == to_find) {
			fst.insert_after(iter, to_add);
			return;
		}
	}
	fst.insert_after(prev, to_add);
	return;
}