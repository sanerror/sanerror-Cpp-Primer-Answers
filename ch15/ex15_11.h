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

class Bulk_Quote : public Quote {					
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string &book, double sales_price, 
		std::size_t n, double dsct);
	double Bulk_Quote::net_price(std::size_t n) const override;
	void debug() const override;
private:
	std::size_t min_qty;
	double discount;
};

class Quk_Quote : public Quote {
public:
	Quk_Quote() = default;
	Quk_Quote(const std::string &book, 
		double sales_price, std::size_t n, double dsct);
	double net_price(std::size_t n) const override;
	void debug() const override;
private:
	std::size_t max_qty;
	double discount;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n);