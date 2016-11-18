#include "ex14_16_18_26_String.h"
#include <algorithm>
#include <cstring>

std::allocator<char> String::alloc;

std::pair<char*, char*> String::alloc_n_copy(const char *a, const char *b) {
	auto newdata = alloc.allocate(b - a + 1);
	alloc.construct(newdata + (b - a), '\0');
	return{ newdata, std::uninitialized_copy(a, b, newdata) };
}

void String::free() {
	if (elements) {
		std::for_each(elements, end, [](char& c) { alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}

String::String(const char *c) {
	const char *ce = c;
	while (*ce)
		++ce;
	auto newdata = alloc_n_copy(c, ce);
	elements = newdata.first;
	end = newdata.second;
}

String::String(const String& s) {
	auto newdata = alloc_n_copy(s.elements, s.end);
	elements = newdata.first;
	end = newdata.second;
}

String& String::operator=(const String &s) {
	auto newdata = alloc_n_copy(s.elements, s.end);
	free();
	elements = newdata.first;
	end = newdata.second;
	return *this;
}

String::~String() {
	free();
}

bool operator==(const String& lhs, const String& rhs) {
	return !strcmp(lhs.elements, rhs.elements);
}

bool operator!=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs){
	return strcmp(lhs.elements, rhs.elements) < 0;
}

bool operator<=(const String& lhs, const String& rhs){
	return strcmp(lhs.elements, rhs.elements) <= 0;
}

bool operator>(const String& lhs, const String& rhs){
	return strcmp(lhs.elements, rhs.elements) > 0;
}

bool operator>=(const String& lhs, const String& rhs){
	return strcmp(lhs.elements, rhs.elements) >= 0;
}

char& String::operator[](std::size_t n){
	if (n >= 0 && n < size())
		return elements[n];
	else
		throw std::runtime_error("out of bound!");
}

const char& String::operator[](std::size_t n) const{
	if (n >= 0 && n < size())
		return elements[n];
	else
		throw std::runtime_error("out of bound!");
}