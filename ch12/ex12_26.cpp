#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
	int n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q = p;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	for (size_t i = 0; i < size; ++i)
		cout << p[i] << endl;

	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);
	return 0;
}