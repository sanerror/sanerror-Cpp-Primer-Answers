#ifndef EX14_16_26_STRING_H
#define EX14_16_26_STRING_H

#include <iostream>
#include <memory>

class String {
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator<=(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);

public:
	String() : elements(nullptr), end(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return end - elements; }
	const char* c_str() { return elements; }
	char& operator[](std::size_t n);
	const char& operator[](std::size_t n) const;

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();

	static std::allocator<char> alloc;
	char *elements;
	char *end;
};
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);


#endif