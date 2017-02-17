#include "ex15_27.h"

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

Quote::Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
	//std::cout << "Quote copy-constructor" << std::endl;
}

Quote::Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
	//std::cout << "Quote move-constructor" << std::endl;
}

Quote& Quote::operator=(const Quote& rhs) {
	bookNo = rhs.bookNo;
	price = rhs.price;
	//std::cout << "Quote copy-assignment" << std::endl;
	return *this;
}

Quote& Quote::operator=(Quote&& rhs) noexcept {
	bookNo = std::move(rhs.bookNo);
	price = std::move(rhs.price);
	//std::cout << "Quote move-assignment" << std::endl;
	return *this;
}

Quote::~Quote() {
	//std::cout << "Quote destructor" << std::endl;
}

//  FOR DISC_QUOTE

Disc_quote::Disc_quote(const std::string &book, double price,
	std::size_t qty, double disc) :
	Quote(book, price), quantity(qty), discount(disc) {}

Disc_quote::Disc_quote(const Disc_quote& dq) :
	Quote(dq), quantity(dq.quantity), discount(dq.discount) {
	//std::cout << "Disc_quote copy-constructor" << std::endl;
}

Disc_quote::Disc_quote(Disc_quote&& dq)noexcept :
	Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {
	//std::cout << "Disc_quote move-constructor" << std::endl;
}

Disc_quote& Disc_quote::operator=(const Disc_quote& dq) {
	Quote::operator=(dq);
	quantity = dq.quantity;
	discount = dq.discount;
	//std::cout << "Disc_quote copy-assignment" << std::endl;
	return *this;
}

Disc_quote& Disc_quote::operator=(Disc_quote&& dq)noexcept {
	Quote::operator=(std::move(dq));
	quantity = std::move(dq.quantity);
	discount = std::move(dq.discount);
	//std::cout << "Disc_quote move-assignment" << std::endl;
	return *this;
}

Disc_quote::~Disc_quote() {
	//std::cout << "Disc_quote destructor" << std::endl;
}

// FOR BULK_QUOTE

/*Bulk_quote::Bulk_quote(const std::string &book, double price,
	std::size_t qty, double disc) :
	Disc_quote(book, price, qty, disc) {}*/

double Bulk_quote::net_price(std::size_t n) const {
	if (n >= quantity)
		return quantity*(1 - discount)*price + (n - quantity)*price;
	else
		return n * (1 - discount) * price;
}

Bulk_quote::Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) {
	//std::cout << "Bulk_quote copy-constructor" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& bq)noexcept : Disc_quote(std::move(bq)) {
	//std::cout << "Bulk_quote move-constructor" << std::endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& bq) {
	Disc_quote::operator=(bq);
	//std::cout << "Bulk_quote copy-assignment" << std::endl;
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& bq) {
	Disc_quote::operator=(std::move(bq));
	//std::cout << "Bulk_quote move-assignment" << std::endl;
	return *this;
}

Bulk_quote::~Bulk_quote() {
	//std::cout << "Bulk_quote destructor" << std::endl;
}