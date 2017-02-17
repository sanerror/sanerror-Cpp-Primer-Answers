#ifndef EX12_19_H
#define EX12_19_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>

using std::vector; using std::string;

class StrBlobPtr;

class StrBlob{
public:
	friend class StrBlobPtr;
	typedef vector<string>::size_type size_type;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() :data(std::make_shared<vector<string>>()) {};
	StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)){};

	size_type size() const {
		return data->size();
	}

	bool empty() const{
		return data->empty();
	}

	void push_back(const string &s) const{
		data->push_back(s);
	}

	void pop_back() const{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	string& front(){
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string& back(){
		check(0, "back on empty StrBlob");
		return data->back();
	}

	string& front() const{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string& back() const{
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
	void check(size_type i, const string &msg) const{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}

	std::shared_ptr<vector<string>> data;
};

class StrBlobPtr{
public:
	StrBlobPtr() :curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz){}
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	string& deref() const;
	StrBlobPtr& incr();

private:
	std::shared_ptr<vector<string>> check(std::size_t, const string&) const;
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};

std::shared_ptr<vector<string>> 
StrBlobPtr::check(std::size_t i, const string& msg) const{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobStr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const{
	auto p = check(curr, "dereference past end of StrBlobPtr");
	return (*p)[curr];
}

/*
std::string& StrBlobPtr::deref() const{
	return (*check(curr, "dereference past end"))[curr];
}
*/


StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin(){ return StrBlobPtr(*this); };

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
};

#endif