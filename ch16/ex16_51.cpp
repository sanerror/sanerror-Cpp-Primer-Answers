#include <iostream>

template <typename T, typename...Args>
void foo(const T &t, const Args& ... rest) 
{
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(rest) << std::endl;
	return;
}

int main() {
	int i = 0; double d = 3.14; std::string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(2, 42, "hi");
	foo(d, s);
	foo("hi");
	return 0;
}

