#include <iostream>
#include <string>
#include "ex16_28_shared_ptr.h"
#include "ex16_28_unique_ptr.h"

using namespace std;

int main() {
	auto foo = share_point<int>(new int(42));
	auto bar = foo;
	foo.swap(bar);
	swap(foo, bar);
	std::cout << *foo << std::endl;
	std::cout << foo.use_count() << std::endl;

	auto string_ptr = share_point<string>(new string("Hello"));
	std::cout << *string_ptr << std::endl;
	std::cout << string_ptr->size() << std::endl;
	string_ptr.reset();

	auto fuo = unique_point<string>(new string("pen"));
	auto p = fuo.get();
	std::cout << *fuo << std::endl;
	std::cout << fuo->size() << std::endl;


	return 0;
}