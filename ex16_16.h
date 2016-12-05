#ifndef VEC_H
#define VEC_H
#include <iostream>
#include <memory>

template <typename T>
class Vec{
public:
	Vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T>);
	Vec(const Vec&);				// copy constructor func
	Vec& operator=(const Vec &);	// copy assignment func
	~Vec();							// destructor

	void push_back(const T&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	T* begin() const { return elements; }
	T* end() const { return first_free; }
private:
	static std::allocator<std::string> alloc;
	// used by func that adds elements
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	// utility func used by copy control func
	std::pair<T*, T*>
		alloc_n_copy(const T*, const T*);
	void free();			// destroy elements and free memory
	void reallocate();		// allocate more memory and copy the elements
	T *elements;
	T *first_free;
	T *cap;
};


#endif