#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

template <typename T> class std::hash;

class Sales_data {
	friend class std::hash<Sales_data>;

	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

	friend std::ostream& operator<<(std::ostream &os, const Sales_data &item);
	friend std::istream& operator>>(std::istream &is, Sales_data &item);
	friend Sales_data& operator+(const Sales_data &item1, const Sales_data &item2);
	friend Sales_data& operator-(const Sales_data &item1, const Sales_data &item2);
	friend bool operator==(const Sales_data &item1, const Sales_data &item2);

public:
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {};
	Sales_data(const std::string& s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(n*p) {};
	Sales_data(std::istream& is) { read(is, *this); };

	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data &rhs);
	Sales_data& operator-=(const Sales_data &rhs);
	Sales_data& operator=(const std::string& isbn);
	Sales_data& operator=(const Sales_data& s);
	std::string isbn() const { return bookNo; };

private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//friend functions
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue 
		<< std::endl;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data& operator+(const Sales_data &item1, const Sales_data &item2) {
	Sales_data sum = item1;
	sum += item2;
	return sum;
}

Sales_data& operator-(const Sales_data &item1, const Sales_data &item2) {
	Sales_data sum = item1;
	sum -= item2;
	return sum;
}

//member functions
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs) {
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator=(const std::string& isbn) {
	bookNo = isbn;
	return *this;
}

Sales_data& Sales_data::operator=(const Sales_data& s) {
	bookNo = s.bookNo;
	units_sold = s.units_sold;
	revenue = s.revenue;
	return *this;
}

inline double Sales_data::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

bool operator==(const Sales_data &item1, const Sales_data &item2) {
	return item1.bookNo == item2.bookNo &&
		item1.units_sold == item2.units_sold &&
		item1.revenue == item2.revenue;
}

#endif