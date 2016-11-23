#include "ex15_11.h"

//FOR QUOTE

Quote::Quote(const std::string &book, double sales_price) :
	bookNo(book), price(sales_price) {}

double Quote::net_price(std::size_t n) const
{
	return n * price;
}

void Quote::debug() const {
	std::cout << "bookNo = " << bookNo
		<< ", price = " << price << std::endl;
}

// FOR BULK_QUOTE

Bulk_Quote::Bulk_Quote(const std::string &book, double sales_price,
	std::size_t n, double dsct) :
	Quote(book, sales_price), min_qty(n), discount(dsct) { }

double Bulk_Quote::net_price(std::size_t n) const {
	if (n >= min_qty)
		return n * (1 - discount) * price;
	else
		return n * price;
}

void Bulk_Quote::debug() const {
	std::cout << "Minimum Quantity = " << min_qty
		<< ", discount = " << discount << std::endl;
}

// FOR QUK_QUOTE

Quk_Quote::Quk_Quote(const std::string &book, 
	double sales_price, std::size_t n, double dsct) :
	Quote(book, sales_price), max_qty(n), discount(dsct) { }

double Quk_Quote::net_price(std::size_t n) const {
	if (n >= max_qty)
		return max_qty * (1 - discount) * price + (n - max_qty) * price;
	else
		return n * (1 - discount) * price;
}

void Quk_Quote::debug() const {
	std::cout << "Maximum Quantity = " << max_qty
		<< ", discount = " << discount << std::endl;
}

// OUTER FUNCTION

double print_total(std::ostream &os, const Quote &item, std::size_t n) {		// function print_total
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}