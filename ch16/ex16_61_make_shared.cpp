#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace ch16 
{
	template <typename T, typename... Args>
	shared_ptr<T> make_shared(Args&&... args) {
		return shared_ptr<T>(new T(std::forward<Args>(args)...));
	}
}

struct Foo {
	Foo(int b) : a(b) {}
	int a;
};

int main() {
	auto num = ch16::make_shared<int>(42);
	cout << *num << endl;

	auto str = ch16::make_shared<string>("hello");
	cout << *str << endl;

	auto foo = ch16::make_shared<Foo>(42);
	cout << foo->a << endl;

	return 0;
}