#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price);
	virtual ~Quote() = default;

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const;
	virtual void debug() const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string&, double,
		std::size_t, double);

	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double,
		std::size_t, double);

	double net_price(std::size_t) const override;
};