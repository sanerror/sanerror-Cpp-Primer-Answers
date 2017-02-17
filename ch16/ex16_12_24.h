#pragma once
#include <iostream>
#include <vector>
#include <memory>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);


template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	// constructor
	Blob();
	Blob(std::initializer_list<T> il);
	template <typename It> Blob(It b, It e);
	// quantity of elems in Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add or delete elems
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	// elems access
	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
	// if i is a large number, check would throw exception to prevent it.
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
	data(std::make_shared<std::vector<T>>(il)) { }

template <typename T> template <typename It> 
Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>>(b, e)) {}





template <typename T> class BlobPtr {
public:
	BlobPtr(): curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr]; // (*p) return vector of this object.
	}
	// increase and decrease
	BlobPtr& operator++();
	BlobPtr& operator--();

	BlobPtr& operator++(int);
	BlobPtr& operator--(int);

private:
	// if check is OK, return a shared_ptr.
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr; // current position
};

template <typename T> std::shared_ptr<std::vector<T>>
	BlobPtr<T>::check(std::size_t sz, const std::string &msg) const {
		auto ret = wptr.lock();
		if (!ret)
			throw std::runtime_error("unbound BlobPtr");
		if (sz >= ret->size())
			throw std::out_of_range(msg);
		return ret;
	}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	--curr;
	check(curr, "increment past end of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}

