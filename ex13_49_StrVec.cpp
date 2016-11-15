#include "ex13_49_StrVec.h"
#include <algorithm>

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n) {
	if (n < size()) return;
	size_t newcapacity = n;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto data = alloc.allocate(e - b);
	return{ data, uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	// if element exists from back to front
	if (elements) {
		/*for (auto p = first_free; p != elements;)
		alloc.destroy(--p);*/
		for_each(elements, first_free,
			[](std::string &p) { alloc.destroy(&p); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		// C++11 move constructor
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

// constuctor 
StrVec::StrVec(std::initializer_list<std::string> ils) {
	auto newdataPair = alloc_n_copy(ils.begin(), ils.end());
	elements = newdataPair.first;
	first_free = cap = newdataPair.second;
}

StrVec::StrVec(const StrVec &s) {
	auto newdataPair = alloc_n_copy(s.begin(), s.end());
	elements = newdataPair.first;
	first_free = cap = newdataPair.second;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(const StrVec &s) {
	auto dataPair = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = dataPair.first;
	first_free = cap = dataPair.second;
	return *this;
}


StrVec::StrVec(StrVec &&s) noexcept :
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&s) noexcept {
	free();
	elements = s.elements;
	first_free = s.first_free;
	cap = s.cap;
	s.elements = s.first_free = s.cap = nullptr;
}
