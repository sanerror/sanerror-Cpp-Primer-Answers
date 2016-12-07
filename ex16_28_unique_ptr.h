#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <iostream>
#include "ex16_28_delete.h"

template <typename T, typename D = Delete> class unique_point;
template <typename T, typename D = Delete>
void swap(unique_point<T, D>& lhs, unique_point<T, D>& rhs) {
	std::swap(lhs.ptr, rhs.ptr);
	std::swap(lhs.deleter, rhs.deleter);
}

template <typename T, typename D = Delete>
class unique_point {
	friend swap(T, D)(unique_point& lhs, unique_point& rhs);

public:
	// delete: copy constructor and assignment
	unique_point(const unique_point&) = delete;
	unique_point& operator=(const unique_point&) = delete;

	// constructor & destructor
	unique_point() = default;
	explicit unique_point(T *up): ptr(up) { }
	unique_point(unique_point &&up) noexcept: ptr(up.ptr) { up.ptr = nullptr; }
	~unique_point() { deleter(ptr); }

	// operator
	unique_point& operator = (unique_point&& rhs) noexcept;
	unique_point& operator = (std::nullptr_t n) noexcept;
	T& operator*() const { return *ptr; }
	T* operator->() const { return &*ptr; }
	operator bool() const { return ptr ? true : false; }

	// other function
	T* get() const noexcept { return ptr; }
	void swap(unique_point &rhs) { swap(*this, rhs); }
	void reset() { deleter(ptr); ptr = nullptr; }
	void reset(T* p) { deleter(ptr); ptr = p; }
	T* release();

private:
	T *ptr = nullptr;
	D deleter = D();
};

template <typename T, typename D = Delete>
inline unique_point<T, D>& 
unique_point<T, D>::operator = (unique_point&& rhs) noexcept {
	if (ptr != rhs.ptr) {
		deleter(ptr);
		ptr = nullptr;
		swap(*this, rhs);
	}
	return *this;
}

template <typename T, typename D = Delete>
unique_point<T, D>& 
unique_point<T, D>::operator = (std::nullptr_t n) noexcept {
	if (n == nullptr) {
		deleter(ptr);
		ptr = nullptr;
	}
	return *this;
}

template <typename T, typename D = Delete>
inline T*
unique_point<T, D>::release() {
	T* ret = ptr;
	ptr = nullptr;
	return ret;
}

#endif