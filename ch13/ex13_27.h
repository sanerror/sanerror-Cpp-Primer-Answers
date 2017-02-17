#ifndef EX13_27_H
#define EX13_27_H

#include <iostream>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr& a) : 
		ps(a.ps), i(a.i), use(a.use) { ++*use; }
	HasPtr& HasPtr::operator=(const HasPtr& a);
	HasPtr& HasPtr::operator=(const std::string& str);
	std::string& HasPtr::operator*();
	~HasPtr();
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr& a) {
	// the executing order is important to avoid some mistakes
	// like a(a)
	++*a.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = a.ps;
	i = a.i;
	use = a.use;
	return *this;
}

HasPtr& HasPtr::operator=(const std::string& str) {
	*ps = str;
	return *this;
}

std::string& HasPtr::operator*() {
	return *ps;
}

HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}



#endif