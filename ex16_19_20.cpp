#include <iostream>
#include <vector>

template <typename V>
void print(const V &vc) {
	typedef V::size_type szt;
	szt sz = vc.size();
	for (szt i = 0; i != sz; ++i) {
		std::cout << vc[i] << " ";
	}
	return;
}

template <typename V>
void print_it(const V &vc) {
	for (auto beg = vc.begin(), end = vc.end(); beg != end; ++beg) {
		std::cout << *beg << " ";
	}
}

int main() {
	std::vector<int> vi{ 1,2,3,4 };
	print(vi);
	print_it(vi);
	return 0;
}