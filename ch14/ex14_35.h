#include <iostream>
#include <string>

class PrintSth {
public:
	PrintSth(std::istream &is_ = std::cin) : is(is_) {}
	std::string operator()() {
		std::string str;
		if (getline(is, str))
			return str;
		else
			return std::string();
	}
private:
	std::istream &is;
};