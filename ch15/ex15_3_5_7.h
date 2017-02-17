#include <iostream>
#include <string>

class Quote{										// class Quote
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const 
	{ return n * price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_Quote : public Quote{					// class Bulk_Quote
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string &book, double sales_price, std::size_t n, double dsct):
		Quote(book, sales_price), min_qty(n), discount(dsct) { }
	double net_price(std::size_t n) const override{
		if (n >= min_qty)
			return n * (1 - discount) * price;
		else
			return n * price;
	}
private:
	std::size_t min_qty;
	double discount;
};

class Quk_Quote : public Quote{
public:
	Quk_Quote() = default;
	Quk_Quote(const std::string &book, double sales_price, std::size_t n, double dsct):
		Quote(book, sales_price), max_qty(n), discount(dsct) { }
	double net_price(std::size_t n) const override{
		if (n >= max_qty)
			return max_qty * (1 - discount) * price + (n - max_qty) * price;
		else
			return n * (1 - discount) * price;
	}
private:
	std::size_t max_qty;
	double discount;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n){		// function print_total
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}