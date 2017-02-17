#include <iostream>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& a) : ps(new std::string(*(a.ps))), i(a.i) {}
	HasPtr& HasPtr::operator=(const HasPtr& a) { 
		// the executing order is important to avoid some mistakes
		// like a(a)
		auto newp = new std::string(*(a.ps));
		delete ps;
		ps = newp;
		i = a.i;
		return *this;
	}
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};
