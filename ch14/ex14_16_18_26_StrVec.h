#ifndef EX13_39_H
#define EX13_39_H

#include <iostream>
#include <memory>

class StrVec {
	friend bool operator==(const StrVec& lhs, const StrVec& rhs);
	friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
	friend bool operator<(const StrVec& lhs, const StrVec& rhs);
	friend bool operator<=(const StrVec& lhs, const StrVec& rhs);
	friend bool operator>(const StrVec& lhs, const StrVec& rhs);
	friend bool operator>=(const StrVec& lhs, const StrVec& rhs);

public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);				// copy constructor func
	StrVec& operator=(const StrVec &);	// copy assignment func
	~StrVec();							// destructor

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	std::string& operator[](std::size_t n);
	const std::string& operator[](std::size_t n) const;

private:
	static std::allocator<std::string> alloc;
	// used by func that adds elements
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	// utility func used by copy control func
	std::pair<std::string*, std::string*>
		alloc_n_copy(const std::string*, const std::string*);
	void free();			// destroy elements and free memory
	void reallocate();		// allocate more memory and copy the elements
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
bool operator==(const StrVec& lhs, const StrVec& rhs);
bool operator!=(const StrVec& lhs, const StrVec& rhs);
bool operator<(const StrVec& lhs, const StrVec& rhs);
bool operator<=(const StrVec& lhs, const StrVec& rhs);
bool operator>(const StrVec& lhs, const StrVec& rhs);
bool operator>=(const StrVec& lhs, const StrVec& rhs);

#endif