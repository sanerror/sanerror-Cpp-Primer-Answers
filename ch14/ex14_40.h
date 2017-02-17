#include <iostream>
#include <string>

struct ShorterString {
	bool operator()(const std::string &s1, const std::string &s2) {
		return s1.size() < s2.size();
	}
};

struct SizeComp {
	SizeComp(std::size_t n) : sz(n) { }
	bool operator()(const std::string &s) {
		return s.size() >= sz;
	}
private:
	std::size_t sz;
};

struct Print {
	void operator()(const std::string &s) {
		std::cout << s << std::endl;
	}
};