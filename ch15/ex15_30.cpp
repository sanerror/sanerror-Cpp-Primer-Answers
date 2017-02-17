#include "ex15_30.h"

void Basket::add_item(const std::shared_ptr<Quote> &sale) {
	items.insert(sale);
}

void Basket::add_item(const Quote &sale) {
	items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote &&sale) {
	items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}

bool Basket::compare(const std::shared_ptr<Quote> &lhs,
	const std::shared_ptr<Quote> &rhs) {
	return lhs->isbn() < rhs->isbn();
}

double Basket::total_receipt(std::ostream &os) const {
	double sum = 0;
	for (auto iter = items.cbegin(); iter != items.cend();
	iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

double print_total(std::ostream& os, const Quote &q, unsigned n) {
	double b = q.net_price(n);
	os << "Isbn: " << q.isbn() << " costs " << b << std::endl;
	return b;
}



