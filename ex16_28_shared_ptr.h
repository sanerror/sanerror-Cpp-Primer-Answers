#ifndef SHARE_POINT
#define SHARE_POINT

#include "ex16_28_delete.h"
#include <iostream>
#include <functional>

template <typename T> class share_point;

template <typaname T>
void swap(share_point &lhs, share_point &rhs) {
	std::swap(lhs.ptr, rhs.ptr);
	std::swap(lhs.ref_count, rhs.ref_count);
	std::swap(lhs.deleter, rhs.deleter);
}

template <typename T>
class share_point {
public:
	share_point();
	explicit share_point(T* raw_ptr);
	share_point(const share_point & sp);
	share_point(share_point && sp) noexcept;
	~share_point() { decrement_n_destroy(); }
	share_point& operator=(const share_point &rhs);
	share_point& operator=(share_point &&rhs) noexcept;
	operator bool() const { return ptr ? true : false; }
	T& operator*() const { return *ptr; }
	T* operator->() const { return &*ptr; } // something wrong?
	std::size_t use_count() const { return *ref_count; }
	void swap(share_point& rhs) { swap(*this, rhs); }
	void reset() { decrement_n_destroy(); }
	void reset(T* p);
	void reset(T* p, const std::function<void(T*)>& d);

private:
	void decrement_n_destroy();
	T* ptr;
	std::size_t* ref_count;
	std::function<void(T*)> deleter;
};

template <typename T>
void share_point<T>::decrement_n_destroy() {
	if (ptr && --*ref_count == 0) {
		delete ref_count;
		deleter(ptr);
	}
	else if (!ptr) {
		delete ref_count;
	}
	ref_count = nullptr;
	ptr = nullptr;
}

template <typename T>
share_point<T>::share_point() :
	ptr(nullptr), ref_count(new std::size_t(1)), deleter(Delete()) {}

template <typename T>
share_point<T>::share_point(T* raw_ptr) :
	ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(Delete()) {}

template <typename T>
share_point<T>::share_point(const share_point & sp) :
	ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter)
{
	++*ref_count;
}

template <typename T>
share_point<T>::share_point(share_point && sp) noexcept :
	ptr(sp.ptr), ref_count(sp.ref_count), deleter(std::move(sp.deleter))
{
	sp.ptr = nullptr; sp.ref_count = nullptr;
}

template <typename T>
share_point& share_point<T>::operator=(const share_point &rhs) {
	++*rhs.ref_count;
	decrement_n_destroy();
	ptr = rhs.ptr;
	ref_count = rhs.ref_count;
	return *this;
}

template <typename T>
share_point& share_point<T>::operator=(share_point &&rhs) noexcept {
	swap(*this, rhs);
	rhs.decrement_n_destroy();
	return *this;
}

template <typename T>
void share_point<T>::reset(T* p) {
	if (ptr != p) {
		decrement_n_destroy();
		ptr = p;
		ref_count = new std::size_t(1);
	}
}

template <typename T>
void share_point<T>::reset(T* p, const std::function<void(T*)>& d) {
	reset(p);
	deleter = d;
}

#endif