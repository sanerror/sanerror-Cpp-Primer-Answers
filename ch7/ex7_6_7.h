#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
	Sales_data& combine(const Sales_data&);
	std::string isbn() const { return bookNo; };

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//member function
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

//nonmember function
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
std::ostream& print(std::ostream& os,const Sales_data& item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif