#include <iostream>
#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& a) : ps(new std::string(*(a.ps))), i(a.i) {}
	HasPtr& HasPtr::operator=(HasPtr a);
	HasPtr& HasPtr::operator=(const std::string& str);
	std::string& HasPtr::operator*();
	std::string& HasPtr::operator*() const;
	bool operator<(const HasPtr&);

	~HasPtr() { delete ps; }

	friend void swap(HasPtr &lhs, HasPtr &rhs);
private:
	std::string *ps;
	int i;
};

HasPtr& HasPtr::operator=(HasPtr a) {
	// the executing order is important to avoid some mistakes
	// like a(a)
	swap(a, *this);
	return *this;
}

HasPtr& HasPtr::operator=(const std::string& str) {
	*ps = str;
	return *this;
}

std::string& HasPtr::operator*() {
	return *ps;
}

std::string& HasPtr::operator*() const{
	return *ps;
}

bool HasPtr::operator<(const HasPtr& rhs) {
	return (*ps < *rhs.ps);
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	std::cout << "exchange " << *lhs.ps << " & " << *rhs.ps << std::endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

