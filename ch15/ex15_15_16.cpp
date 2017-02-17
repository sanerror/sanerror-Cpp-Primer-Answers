#include "ex15_15_16.h"

// FOR QUOTE

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

//  FOR DISC_QUOTE

Disc_quote::Disc_quote(const std::string &book, double price,
	std::size_t qty, double disc) :
	Quote(book, price), quantity(qty), discount(disc) {}

// FOR BULK_QUOTE

Bulk_quote::Bulk_quote(const std::string &book, double price,
	std::size_t qty, double disc) :
	Disc_quote(book, price, qty, disc) {}

double Bulk_quote::net_price(std::size_t n) const {
	if (n > quantity)
		return quantity*(1 - discount)*price + (n - quantity)*price;
	else
		return n * (1 - discount) * price;
}