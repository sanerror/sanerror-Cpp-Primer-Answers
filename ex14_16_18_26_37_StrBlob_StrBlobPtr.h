#ifndef EX14_16_26_StrBlob_StrBlobPtr_H
#define EX14_16_26_StrBlob_StrBlobPtr_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>

using std::vector; using std::string; using std::size_t;

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator<(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator<=(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator>(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator>=(const StrBlob& lhs, const StrBlob& rhs);
	typedef vector<string>::size_type size_type;

public:
	StrBlob() :data(std::make_shared<vector<string>>()) {};
	StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {};

	StrBlobPtr begin();
	StrBlobPtr end();
	string& operator[](size_t n);
	const string& operator[](size_t n) const;
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &s) const { data->push_back(s); }

	void pop_back() const {
		check(0, "pop_back on empty StrBlob");
		data->pop_back(); }

	string& front() {
		check(0, "front on empty StrBlob");
		return data->front(); }

	string& back() {
		check(0, "back on empty StrBlob");
		return data->back(); }

	string& front() const {
		check(0, "front on empty StrBlob");
		return data->front(); }

	string& back() const {
		check(0, "back on empty StrBlob");
		return data->back(); }

private:
	void check(size_type i, const string &msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg); }
	std::shared_ptr<vector<string>> data;
};



class StrBlobPtr {
	friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	string& deref() const;
	StrBlobPtr& incr();
	string& operator[](size_t n);
	const string& operator[](size_t n) const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

private:
	std::shared_ptr<vector<string>> check(std::size_t, const string&) const;
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};


// all definitions down here


std::shared_ptr<vector<string>>
StrBlobPtr::check(std::size_t i, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobStr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end of StrBlobPtr");
	return (*p)[curr];
}

/*
std::string& StrBlobPtr::deref() const{
return (*check(curr, "dereference past end"))[curr];
}
*/


StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); };
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); };
bool operator==(const StrBlob& lhs, const StrBlob& rhs) { return (lhs.data == rhs.data); }
bool operator!=(const StrBlob& lhs, const StrBlob& rhs) { return !(lhs == rhs); }
bool operator<(const StrBlob& lhs, const StrBlob& rhs){	return (*lhs.data < *rhs.data); }
bool operator<=(const StrBlob& lhs, const StrBlob& rhs){ return (lhs < rhs) || (lhs == rhs); }
bool operator>(const StrBlob& lhs, const StrBlob& rhs){ return !(lhs <= rhs); }
bool operator>=(const StrBlob& lhs, const StrBlob& rhs) { return !(lhs < rhs); }

string& StrBlob::operator[](size_t n){
	if (n >= 0 && n < size())
		return (*data)[n];
	else 
		throw std::runtime_error("out of bound!");
}

const string& StrBlob::operator[](size_t n) const{
	if (n >= 0 && n < size())
		return (*data)[n];
	else
		throw std::runtime_error("out of bound!");
}
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r){
		if (!r)
			return false;
		return (lhs.curr < rhs.curr);
	}
	else
		return false;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
	return !(lhs <= rhs);
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
	return !(lhs < rhs);
}

string& StrBlobPtr::operator[](size_t n){ 
	if (n >= 0 && n < size())
		return (*wptr.lock())[n];
	else
		throw std::runtime_error("out of bound!");
}
const string& StrBlobPtr::operator[](size_t n) const {
	if (n >= 0 && n < size())
		return (*wptr.lock())[n];
	else
		throw std::runtime_error("out of bound!");
}

StrBlobPtr& StrBlobPtr::operator++(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
	--curr;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int){
	StrBlobPtr ret = *this;
	++ *this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int){
	StrBlobPtr ret = *this;
	-- *this;
	return ret;
}

#endif