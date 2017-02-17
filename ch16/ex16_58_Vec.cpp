#include "ex16_16_Vec.h"
#include <algorithm>

template <typename T>
std::allocator<std::string> Vec<T>::alloc;

template <typename T>
template <typename Ty... Args>
void Vec<T>::emplace_back(Args&&...args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
void Vec<T>::push_back(const T &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::reserve(size_t n) {
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

template <typename T> std::pair<T*, T*>
	Vec<T>::alloc_n_copy(const T *b, const T *e) {
		auto data = alloc.allocate(e - b);
		return{ data, uninitialized_copy(b, e, data) };
	}

	template <typename T>
	void Vec<T>::free() {
		// if element exists from back to front
		if (elements) {
			/*for (auto p = first_free; p != elements;)
			alloc.destroy(--p);*/
			for_each(elements, first_free,
				[](std::string &p) { alloc.destroy(&p); });
			alloc.deallocate(elements, cap - elements);
		}
	}

	template <typename T>
	void Vec<T>::reallocate() {
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
	template <typename T>
	Vec<T>::Vec(std::initializer_list<T> ils) {
		auto newdataPair = alloc_n_copy(ils.begin(), ils.end());
		elements = newdataPair.first;
		first_free = cap = newdataPair.second;
	}

	template <typename T>
	Vec<T>::Vec(const Vec<T> &s) {
		auto newdataPair = alloc_n_copy(s.begin(), s.end());
		elements = newdataPair.first;
		first_free = cap = newdataPair.second;
	}

	template <typename T>
	Vec<T>::~Vec() {
		free();
	}

	template <typename T>
	Vec<T>& Vec<T>::operator=(const Vec<T> &s) {
		auto dataPair = alloc_n_copy(s.elements, s.first_free);
		free();
		elements = dataPair.first;
		first_free = cap = dataPair.second;
		return *this;
	}