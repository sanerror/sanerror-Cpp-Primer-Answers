#ifndef EX14_7_H
#define EX14_7_H

#include <iostream>
#include <memory>

class String {
	friend std::ostream& operator<<(std::ostream& os, const String& str);
public:
	String() : elements(nullptr), end(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return end - elements; }
	const char* c_str() { return elements; }
private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();

	static std::allocator<char> alloc;
	char *elements;
	char *end;
};


#endif