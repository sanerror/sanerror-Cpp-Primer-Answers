#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <memory>
#include <set>
#include "ex15_27.h"

class Basket {
public:
	void add_item(const std::shared_ptr<Quote> &sale);
	void add_item(const Quote &sale);
	void add_item(Quote &&sale);
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs);
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
		items{compare};
};

double print_total(std::ostream&, const Quote&, unsigned);

#endif